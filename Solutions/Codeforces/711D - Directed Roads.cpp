#include <bits/stdc++.h>
using namespace std;

#define maxn 200010
#define mod 1000000007

typedef long long ll;

int n, cycle, vis[maxn], a[maxn], two[maxn] = {1};

void build(){
  for(int i = 1; i < maxn; ++i)
    two[i] = 2 * two[i - 1] % mod;
}

int dfs(int u, int cnt){
  if(vis[u] != -1){
    if(vis[u] == -2) return 1;
    cycle = u;
    return (two[cnt - vis[u]] - 2 + mod) % mod;
  }

  vis[u] = cnt;
  int x = dfs(a[u], cnt + 1);
  vis[u] = -2;

  if(cycle == -1) return 2ll * x % mod;
  if(u == cycle) cycle = -1;
  return x;
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  build();

  while(cin >> n){
    memset(vis, -1, sizeof vis);

    for(int i = 1; i <= n; ++i) cin >> a[i];

    int ans = 1;
    for(int u = 1; u <= n; ++u)
      if(vis[u] == -1){
        cycle = -1;
        ans = ll(ans) * dfs(u, 1) % mod;
      }
    cout << ans << '\n';
  }

  return 0;
}
