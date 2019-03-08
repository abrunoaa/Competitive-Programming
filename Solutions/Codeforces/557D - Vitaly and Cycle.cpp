#include <bits/stdc++.h>
using namespace std;

#define maxn 100010

typedef long long ll;
typedef pair<int,int> ii;

int n, m, cnt[2], color[maxn];
vector<int> g[maxn];

bool bipartite(int u){
  for(int v : g[u]){
    if(color[u] == color[v])
      return 0;
    if(color[v] == -1){
      color[v] = color[u] ^ 1;
      ++cnt[color[v]];
      if(!bipartite(v))
        return 0;
    }
  }
  return 1;
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  if(m == 0){
    cout << "3 " << (ll)n * (n - 1) * (n - 2) / 6 << '\n';
    return 0;
  }
  if(m == 1){
    cout << "2 " << n - 2 << '\n';
    return 0;
  }

  bool ans2 = 1;
  for(int i = 0, u, v; i < m; ++i){
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    ans2 &= g[u].size() == 1 && g[v].size() == 1;
  }
  if(ans2){
    cout << "2 " << (ll)m * (n - 2) << '\n';
    return 0;
  }

  ll ans = 0;
  memset(color, -1, sizeof color);
  for(int u = 1; u <= n; ++u){
    if(color[u] == -1){
      color[u] = 0;
      cnt[0] = 1;
      cnt[1] = 0;
      if(!bipartite(u)){
        cout << "0 1\n";
        return 0;
      }
      for(int c : cnt){
        ans += (ll)c * (c - 1) / 2;
      }
    }
  }
  cout << "1 " << ans << '\n';

  return 0;
}
