#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__(){ cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n"; }

void debug(){}
template<class t,class... u> void debug(const t& x,const u& ...y){ cerr<<' '<<x,debug(y...); }
#define debug(x...) cerr<<"\x1b[91m[" #x "] =",debug(x),cerr<<"\x1b[0m\n"
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

#define gcd __gcd
#define abs myabs

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 big;

inline int abs(int x){ return (x < 0 ? -x : x); }
inline ll abs(ll x){ return (x < 0 ? -x : x); }
inline big abs(big x){ return (x < 0 ? -x : x); }

inline int ctz(int x){ return __builtin_ctz((unsigned)x); }
inline int ctz(ll x){ return __builtin_ctzll((unsigned long long)x); }
inline int ctz(big x){ return (x & ~0ll ? ctz((ll)x) : 64 + ctz((ll)(x >> 64))); }

inline int mul(int a, int b, int m){ return (int)((ll)a * b % m); }
inline ll mul(ll a, ll b, ll m){ return (ll)((big)a * b % m); }
inline big mul(big a, big b, big m){
  big x = 0, y = a % m;
  while(b){
    if(b % 2) x = (x + y) % m;
    y = 2 * y % m;
    b /= 2;
  }
  return x;
}

template<class T> T pow(T b, T e, T m){
  b %= m;
  T x = 1;
  while(e){
    if(e % 2) x = mul(x, b, m);
    b = mul(b, b, m);
    e /= 2;
  }
  return x;
}

template<class T> T isqrt(T n){
  T x = n, y = (n + 1) / 2;
  while(x > y){
    x = y;
    y = (x + n / x) / 2;
  }
  return x;
}

template<class B, class T> bool millerRabin(const B* base, int len, T n){
  if(n < 2) return 0;
  if(n % 2 == 0) return n == 2;
  T d = n - 1;
  int r = ctz(d);
  d >>= r;
  for(int i = 0; i < len; ++i){
    T a = (T)(base[i] % n);
    if(!a) continue;
    a = pow(a, d, n);
    if(a == 1 || a == n - 1) continue;
    for(int i = 1; i < r && 1 < a && a < n - 1; ++i) a = pow(a, (T)2, n);
    if(a != n - 1) return 0;
  }
  return 1;
}

template<class T> inline bool isPrime(T n){
  static const ull b1[] = {9345883071009581737ull};
  static const ull b2[] = {336781006125ull, 9639812373923155ull};
  static const ull b3[] = {4230279247111683200ull, 14694767155120705706ull, 16641139526367750375ull};
  static const ull b4[] = {2, 141889084524735ull, 1199124725622454117ull, 11096072698276303650ull};
  static const ull b5[] = {2, 4130806001517ull, 149795463772692060ull, 186635894390467037ull, 3967304179347715805ull};
  static const ull b6[] = {2, 123635709730000ull, 9233062284813009ull, 43835965440333360ull, 761179012939631437ull, 1263739024124850375ull};
  static const int b7[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
  if(n < 341531) return millerRabin(b1, 1, (int)n);
  if(n < 1050535501) return millerRabin(b2, 2, (int)n);
  if(n < 350269456337ll) return millerRabin(b3, 3, (ll)n);
  if(n < 55245642489451ll) return millerRabin(b4, 4, (ll)n);
  if(n < 7999252175582851ll) return millerRabin(b5, 5, (ll)n);
  if(n < 585226005592931977ll) return millerRabin(b6, 6, (ll)n);
  return millerRabin(b7, 7, n);
}

template<class T> T rho(T n){
  if(n <= 3 || isPrime(n)) return 0;
  if(n % 2 == 0) return 2;
  T r = isqrt(n);
  if(r * r == n) return r;

  do{
    T x, y, ys, m, c, q, g;
    y = (T)rand() % (n - 1) + 1;
    m = (T)rand() % (n - 1) + 1;
    c = (T)rand() % (n - 1) + 1;
    q = g = 1;
    for(int r = 1; g == 1; r *= 2){
      x = y;
      for(int i = 0; i < r; ++i)
        y = (mul(y, y, n) + c) % n;
      for(int k = 0; k < r && g == 1; k += m){
        ys = y;
        for(int i = min(m, r - k); i; --i){
          y = (mul(y, y, n) + c) % n;
          q = mul(q, abs(x - y), n);
        }
        g = gcd(q, n);
      }
    }
    if(g == n) do{
      ys = (mul(ys, ys, n) + c) % n;
      g = gcd(n, abs(x - ys));
    } while(g == 1);
  } while(g == n);
  return g;
}

vector<big> factors;

template<class T> void getFactors(T x){
  if(sizeof(T) == 8 && x < (int)2e9) return getFactors((int)x);
  if(sizeof(T) == 16 && x < (ll)1e18) return getFactors((ll)x);
  big d = rho(x);
  if(d == 0){
    factors.push_back(x);
    return;
  }
  getFactors(d);
  getFactors(x / d);
}

vector<pair<big,int>> solve(big n){
  factors.clear();
  getFactors(n);
  sort(factors.begin(), factors.end());
  vector<pair<big,int>> ans;
  for(int i = 0, j; i < (int)factors.size(); i = j){
    for(j = i + 1; j < (int)factors.size() && factors[i] == factors[j]; ++j);
    ans.emplace_back(factors[i], j - i);
  }
  return ans;
}

static char buf[50];

istream& operator >> (istream& in, big& x){
  if(cin >> buf){
    x = 0;
    for(int i = 0; buf[i]; ++i) x = x * 10 + buf[i] - '0';
  }
  return in;
}

ostream& operator << (ostream& out, big x){
  if(!x) return out << "0";
  char* s = buf + sizeof(buf) - 1;
  *--s = 0;
  if(x < 0) *--s = '-', x = -x;
  while(x) *--s = (char)(x % 10 + '0'), x /= 10;
  return out << s;
}

int main(){
  freopen("in","r",stdin);
  srand(2019);

  big n;
  while(cin >> n && n){
    bool flag = 0;
    for(auto x : solve(n)){
      if(flag) cout << ' ';
      flag = 1;
      cout << x.first << '^' << x.second;
    }
    cout << '\n';
  }

  return 0;
}
