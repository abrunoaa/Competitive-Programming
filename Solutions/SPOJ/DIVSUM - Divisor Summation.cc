#include <bits/stdc++.h>
using namespace std;

#define maxn 500010

int ans[maxn];

void sieve(){
  int n = maxn;
  for(int i = 1; i < n; ++i)
    for(int j = 2 * i; j < n; j += i)
      ans[j] += i;
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  sieve();

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << ans[n] << '\n';
  }

  return 0;
}
