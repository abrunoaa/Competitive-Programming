// dijkstra não funciona!!!

#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define inf 0x3f3f3f3f
#define maxn 2010

typedef pair<int,int> ii;
typedef pair<int,ii> tri;

int uf[maxn];

void init(int n){
  for(int i = 1; i <= n; ++i){
    uf[i] = i;
  }
}

int find(int u){
  return u == uf[u] ? u : uf[u] = find(uf[u]);
}

void unite(int u, int v){
  uf[find(u)] = find(v);
}

int main(){
  assert(freopen("iptv.in","r",stdin));
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n, m, cnt = 1;
    map<string,int> id;
    vector<tri> edges;

    cin >> n >> m;
    edges.reserve(m);
    while(m--){
      int w;
      string c1, c2;
      cin >> c1 >> c2 >> w;

      int &u = id[c1], &v = id[c2];
      if(!u) u = cnt++;
      if(!v) v = cnt++;

      edges.push_back(tri(w, ii(u, v)));
    }

    sort(edges.begin(), edges.end());
    init(n);

    int ans = 0;
    for(tri e : edges){
      if(find(e.nd.st) != find(e.nd.nd)){
        ans += e.st;
        unite(e.nd.st, e.nd.nd);
      }
    }
    cout << ans << '\n';
    if(t){
      cout << '\n';
    }
  }

  return 0;
}
