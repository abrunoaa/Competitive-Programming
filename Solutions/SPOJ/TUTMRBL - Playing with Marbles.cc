#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#if !defined ONLINE_JUDGE || defined LOCAL
__attribute__((destructor)) static void __destroy__() { cerr << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void debug(){}
template<class t, class... u> void debug(t x, u ...y){ cerr << ' ' << x, debug(y...); }
#define debug(x...) cerr << "\x1b[91m[" #x "] =", debug(x), cerr << "\x1b[0m\n"
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

#define pb push_back

typedef unsigned long long ull;
typedef vector<int> vi;

#define maxn ((int)sqrt(1e7) + 10)

bool flag;
vi primes;
bitset<maxn> isp;

void sieve(){
  isp.set();
  isp[0] = isp[1] = 0;
  primes.reserve(maxn / (log(maxn) - 1) + 1000);
  for(int i = 2; i < maxn; ++i){
    if(isp[i]){
      primes.pb(i);
      for(int j = 2 * i; j < maxn; j += i){
        isp[j] = 0;
      }
    }
  }
}

void print_pf(int p){
  if(flag){
    cout << " *";
  }
  flag = 1;
  cout << ' ' << p;
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  sieve();

  int n0;
  while(cin >> n0 && n0){
    cout << n0 << " =";

    flag = 0;
    int n = n0;
    int ndiv = 1;
    for(int p : primes){
      if((ull)p * p > n){
        break;
      }
      if(n % p == 0){
        int e = 1;
        while(n % p == 0){
          n /= p;
          ++e;
          print_pf(p);
        }
        ndiv *= e;
      }
    }
    if(n > 1){
      print_pf(n);
      ndiv *= 2;
    }

    cout << "\nWith " << n0 << " marbles, " << (ndiv + 1) / 2 << " different rectangles can be constructed.\n";
  }

  return 0;
}
