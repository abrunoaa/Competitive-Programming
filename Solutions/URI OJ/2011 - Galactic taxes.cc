#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define eps 1e-9
#define maxn 1003

typedef pair<double,int> P;

struct Node{
  int v, a, b;
};

int n, m;
double dis[maxn];
vector<Node> g[maxn];

double tax(double t){
  priority_queue<P,vector<P>,greater<P>> pq;
  pq.push(P(0.0, 1));
  dis[0] = 0.0;
  for(int i = 2; i <= n; ++i){
    dis[i] = 1e40;
  }
  while(!pq.empty()){
    double d = pq.top().st;
    int u = pq.top().nd;
    pq.pop();
    if(d >= dis[u] + eps) continue;
    for(const Node& v : g[u]){
      double c = v.a * t + v.b;
      if(d + c <= dis[v.v] - eps){
        dis[v.v] = d + c;
        pq.push(P(dis[v.v], v.v));
      }
    }
  }
  return dis[n];
}

int main(){
  // assert(freopen("in","r",stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    g[u].push_back({ v, a, b });
    g[v].push_back({ u, a, b });
  }
  double l = 0, r = 24 * 60;
  for(int i = 0; i < 100; ++i){
    double m = (l + r) / 2.0;
    if(tax(m) < tax(m + eps)){
      l = m;
    }
    else{
      r = m;
    }
  }
  cout << fixed << setprecision(5) << tax(l) << '\n';
  return 0;
}
