#include <bits/stdc++.h>
using namespace std;

#define maxn 100010

int n, t[maxn], pos[maxn], neg[maxn];

int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  cin.sync_with_stdio(0), cin.tie(0);

  while(cin >> n){
    int z = 0;
    for(int i = 0; i < n; ++i){
      cin >> t[i];
      if(t[i] == 0){
        --i;
        --n;
        ++z;
      }
    }
    if(n == 0){
      cout << z << '\n';
      continue;
    }

    for(int i = 0; i < n; ++i) pos[i] = (i ? pos[i - 1] : 0) + (t[i] > 0);
    for(int i = n - 1; i >= 0; --i) neg[i] = neg[i + 1] + (t[i] < 0);

    int ans = 1e9;
    for(int k = 0; k < n - 1; ++k) ans = min(ans, pos[k] + neg[k + 1] + z);
    cout << ans << '\n';
  }

  return 0;
}
