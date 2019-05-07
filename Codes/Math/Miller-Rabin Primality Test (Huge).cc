#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 big;

inline big abs(big x){ return (x < 0 ? -x : x); }

inline int ctz(int x){ return __builtin_ctz((unsigned)x); }
inline int ctz(ll x){ return __builtin_ctzll((ull)x); }
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

/// TESTES
#define maxn 1000003

bitset<maxn> isp;
vector<int> primes;

void sieve(){
  isp.set();
  isp[0] = isp[1] = 0;
  primes.reserve((int)(1.5 * maxn / log(maxn)));
  for(int i = 2; i < maxn; ++i){
    if(isp[i]){
      primes.push_back(i);
      if((ll)i * i < maxn){
        for(int j = i * i; j < maxn; j += i){
          isp[j] = 0;
        }
      }
    }
  }
}

bool isPrimeSieve(ll x){
  if(x < maxn) return isp[x];
  for(int p : primes){
    if((ll)p * p > x) return 1;
    if(x % p == 0) return 0;
  }
  assert(0);
}

int main(){
  sieve();
  for(int n = 0; n < 10 * maxn; ++n){
    if(isPrimeSieve(n) != isPrime(n)){
      cerr << " >> " << n << ' ' << isPrimeSieve(n) << ' ' << isPrime(n) << endl;
      // break;
    }
  }
  cerr << "end!\n";
  return 0;
}
