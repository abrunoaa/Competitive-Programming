#include <bits/stdc++.h>
using namespace std;

#define maxn 10010

int cnt, low[maxn], num[maxn], p[maxn];
vector<int> g[maxn];

int find(int u){
  return (u == p[u] ? u : p[u] = find(p[u]));
}

void unite(int u, int v){
  p[find(u)] = find(v);
}

void bridges(int u, int p){
  low[u] = num[u] = ++cnt;
  for(int v : g[u]){
    if(v != p){
      if(num[v] == -1){
        bridges(v, u);
        if(low[v] > num[u]){
          unite(u, v);
        }
      }
      low[u] = min(low[u], low[v]);
    }
  }
}

int main(){
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  int n, c, q;
  while(cin >> n >> c >> q && (n || c || q)){
    cnt = 0;
    for(int u = 1; u <= n; ++u){
      g[u].clear();
      p[u] = u;
    }

    for(int i = 0, u, v; i < c; ++i){
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    memset(num, -1, sizeof num);
    for(int u = 1; u <= n; ++u){
      if(num[u] == -1){
        bridges(u, -1);
      }
    }

    for(int i = 0, u, v; i < q; ++i){
      cin >> u >> v;
      cout << (find(u) == find(v) ? 'Y' : 'N') << '\n';
    }
    cout << "-\n";
  }

  return 0;
}
