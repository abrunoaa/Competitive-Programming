#include <bits/stdc++.h>
using namespace std;

#define maxn 5000010

int nfac[maxn], ans[maxn];

void sieve(){
  int n = maxn;
  for(int i = 2; i < n; ++i){
    if(nfac[i] == 0){
      nfac[i] = 1;
      for(int j = 2 * i; j < n; j += i){
        for(int k = j; k % i == 0; k /= i){
          ++nfac[j];
        }
      }
    }
  }
}

void solve(){
  int n = maxn;
  for(int i = 2; i < n; ++i){
    ans[i] = ans[i - 1] + nfac[i];
  }
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  sieve();
  solve();

  int t;
  cin >> t;
  while(t--){
    int a, b;
    cin >> a >> b;
    cout << ans[a] - ans[b] << '\n';
  }

  return 0;
}
