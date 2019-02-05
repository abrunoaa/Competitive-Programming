#include <bits/stdc++.h>
using namespace std;

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

#define endl '\n'
#define maxn ((int)1e6 + 1)

bool ans[maxn];
int d[maxn];

int main(){
  freopen("out","w",stdout);
  cin.sync_with_stdio(0), cin.tie(0);

  for(int i = 1; i < maxn; ++i){
    d[i] = 1;
  }
  for(int i = 2; i < maxn; ++i){
    if(d[i] == 1){
      for(int j = i; j < maxn; j += i){
        int e = 1;
        for(int k = j; k % i == 0; k /= i){
          ++e;
        }
        d[j] *= e;
      }
    }
    ans[i] = (d[i] > 3);
  }
  for(int i = 2; i < maxn; ++i){
    for(int j = 2 * i; j < maxn; j += i){
      ans[j] &= (d[j] % d[i] == 0);
    }
  }
  for(int i = 0, j = 0; i < maxn; ++i){
    if(ans[i] && (j = (j + 1) % 108) == 0){
      cout << i << endl;
    }
  }

  return 0;
}
