#include <bits/stdc++.h>
using namespace std;

#define maxn 103

bool inGraph[maxn];
bool vis[2 * maxn];
int n, q;
int g[2 * maxn][2 * maxn];
int p[2 * maxn];
set<int> parent[maxn];

bool bfs(int source, int sink){
  queue<int> q;
  q.push(source);
  memset(vis, 0, sizeof(vis));
  vis[source] = 1;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v = 0; v < 2 * n + 2; ++v){
      if(g[u][v] && !vis[v]){
        q.push(v);
        p[v] = u;
        vis[v] = 1;
      }
    }
  }
  return vis[sink];
}

int mf(int source, int sink){
  int mf = 0;
  while(bfs(source, sink)){
    for(int u = sink; u != source; u = p[u]){
      g[p[u]][u] = 0;
      g[u][p[u]] = 1;
    }
    ++mf;
  }
  return mf;
}

int main(){
  // assert(freopen("in","r",stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for(int i = 0; i < n; ++i){
    int b;
    cin >> b;
    for(int j = 0; j < b; ++j){
      int x;
      cin >> x;
      parent[i].insert(x);
    }
  }
  while(q--){
    memset(g, 0, sizeof(g));
    int b;
    cin >> b;
    if(b < n){
      for(int i = 0; i < n; ++i){
        inGraph[i] = (int)parent[i].size() < n;
      }
    }
    for(int i = 0; i < b; ++i){
      int c;
      cin >> c;
      for(int j = 0; j < n; ++j){
        if(parent[j].count(c)){
          g[j][n + c - 1] = 1;
          inGraph[j] = 1;
        }
      }
    }
    const int source = 2 * n;
    const int sink = source + 1;
    for(int i = 0; i < n; ++i){
      g[source][i] = 1;
    }
    for(int i = 0; i < n; ++i){
      g[i + n][sink] = 1;
    }
    bool ok = 1;
    for(int i = 0; i < n; ++i){
      ok &= inGraph[i];
    }
    cout << (ok && mf(source, sink) == b ? 'Y' : 'N') << '\n';
  }
  return 0;
}
