#include <bits/stdc++.h>
using namespace std;

typedef int Int;

#define maxn 100003
#define inf 0x3f3f3f3f
#define st first
#define nd second
#define int long long

typedef pair<int,int> ii;
typedef vector<int> vi;

bool sc[maxn];
int N, M, K, P;
int dis[maxn], dsu[maxn], par[maxn], parb[maxn], reach[maxn];
vector<ii> g[maxn];
vi ans, g2[maxn];
map<int,ii> path[maxn];

int find(int u){ return (u == dsu[u] ? u : dsu[u] = find(dsu[u])); }
void unite(int u, int v){ dsu[find(u)] = find(v); }

vi buildPath(int u, int v){ // constrói o caminho: u -> v
  vi P;
  while(P.push_back(u), !sc[u]) u = par[u];
  reverse(P.begin(), P.end());
  while(P.push_back(v), !sc[v]) v = par[v];
  return P;
}

bool dijkstra(){
  priority_queue<ii,vector<ii>,greater<ii>> pq;
  memset(dis, inf, sizeof dis);
  sc[1] = sc[N] = 1;
  for(int u = 1; u <= N; ++u){
    dsu[u] = u;
    if(sc[u]){
      par[u] = u;
      reach[u] = u;
      dis[u] = 0;
      pq.push(ii(0, u));
    }
  }
  while(!pq.empty()){
    ii f = pq.top();
    pq.pop();
    int u = f.nd;
    int d = f.st;
    if(d > dis[u]) continue;

    int ru = reach[u];
    for(ii e : g[u]){
      int v = e.st;
      int w = e.nd;
      int &rv = reach[v];

      if(d + w < dis[v] && d + w <= P){
        dis[v] = d + w;
        par[v] = u;
        rv = ru;
        pq.push(ii(dis[v], v));
      }
      else if(dis[v] != inf && d + w + dis[v] <= P && find(u) != find(v)){
        unite(u, v);
        g2[ru].push_back(rv);
        g2[rv].push_back(ru);
        path[ru][rv] = ii(u, v);
        path[rv][ru] = ii(v, u);
      }
    }
  }
  // for(int u = 1; u <= N; ++u) cerr << " -- " << dis[u] << endl;
  return find(1) == find(N);
}

void bfs(){
  memset(parb, 0, sizeof parb);
  queue<int> q;
  q.push(1);
  par[1] = 1;
  while(!q.empty()){
    int u = q.front();
    // cerr << " >> " << u << ' ' << par[u] << endl;
    q.pop();
    for(int v : g2[u]){
      if(!parb[v]){
        parb[v] = u;
        q.push(v);
      }
    }
  }
}

vi rec(int v = N){
  if(v == 1) return vi();
  int u = parb[v];
  ii t = path[u][v];
  vi ans = rec(u), p = buildPath(t.st, t.nd);
  ans.insert(ans.end(), p.begin(), p.end() - 1);
  return move(ans);
}

Int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> N >> M >> K >> P;
  while(K--){
    int x;
    cin >> x;
    sc[x] = 1;
  }
  while(M--){
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back(ii(b, c));
    g[b].push_back(ii(a, c));
  }
  if(!dijkstra()){
    cout << "-1\n";
    return 0;
  }
  bfs();
  vi ans = rec();
  ans.push_back(N);
  cout << ans.size() << '\n';
  for(int i = 0; i < (int)ans.size(); ++i){
    if(i) cout << ' ';
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}
