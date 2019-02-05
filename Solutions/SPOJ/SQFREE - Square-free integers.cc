#ifdef ONLINE_JUDGE
# pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
__attribute__((destructor)) static void __destroy__() { cerr << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void debug(){}
template<class t, class... u> void debug(t x, u ...y){ cerr << ' ' << x, debug(y...); }
#define debug(x...) cerr << "\x1b[91m[" #x "] =", debug(x), cerr << "\x1b[0m\n"
#else
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

#define endl '\n'
#define pb push_back

typedef unsigned long long ull;
typedef vector<int> vi;

#define eps 1e-9
#define mod 1000000007
#define maxn 10000010

bitset<maxn> sf;  // square free
char npf[maxn];   // num (distinct) prime factors

void sieve(){
  sf.set();
  for(int i = 2; i < maxn; ++i){
    if(npf[i] == 0){
      for(int j = i; j < maxn; j += i){
        ++npf[j];
      }
      if((ull)i * i < maxn){
        for(int k = i * i, j = k; j < maxn; j += k){
          sf[j] = 0;
        }
      }
    }
  }
}

ull non_square_free(ull n){
  ull ans = 0;
  for(int i = 2, lim = (int)(sqrt(n) + eps); i <= lim; ++i){
    if(sf[i]){
      ans += n / ((ull)i * i) * (npf[i] % 2 ? 1 : -1);
    }
  }
  return ans;
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  sieve();

  int t;
  cin >> t;
  while(t--){
    ull n;
    cin >> n;
    cout << n - non_square_free(n) << endl;
  }

  return 0;
}
