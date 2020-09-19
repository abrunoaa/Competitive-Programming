typedef unsigned long long u64;
typedef __int128_t i128;
typedef __uint128_t u128;

struct u256 {
  u128 hi, lo;
  static u256 mult(u128 x, u128 y) {
    u128 a = x >> 64, b = (u64)x;
    u128 c = y >> 64, d = (u64)y;
    u128 ac = a * c;
    u128 ad = a * d;
    u128 bc = b * c;
    u128 bd = b * d;
    u128 carry = (u128)(u64)ad + (u64)bc + (bd >> 64u);
    u128 h = ac + (ad >> 64u) + (bc >> 64u) + (carry >> 64u);
    u128 l = (ad << 64u) + (bc << 64u) + bd;
    return {h, l};
  }
};

template<class tipo> class Dobra {
};

typedef Dobra<long long> Grande;
typedef Dobra<Grande> MaisGrande;
typedef Dobra<MaisGrande> Grandao;

struct Montgomery {
  u128 n, inv, r2;
  explicit Montgomery(u128 _n) : n(_n), inv(1), r2(-n % n) {
    assert(n & 1);
    for (int i = 0; i < 7; ++i) inv *= 2 - n * inv;
    for (int i = 0; i < 4; ++i) if ((r2 <<= 1) >= n) r2 -= n;
    for (int i = 0; i < 5; ++i) r2 = mult(r2, r2);
  }
  u128 init(u128 x) { return mult(x, r2); }
  u128 mult(u128 a, u128 b) { return reduce(u256::mult(a, b)); }
  u128 reduce(u256 x) {
    i128 a = x.hi - u256::mult(x.lo * inv, n).hi;
    return (a < 0) ? a + n : a;
  }
};
