#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#define maxn 10001
#define fst first
#define snd second
#define mt(f, s, t) tri(f, ii(s, t))

typedef pair<int,int> ii;
typedef pair<int,ii> tri;

struct cmp { bool operator () (tri &x, tri &y) { return x.fst > y.fst; } };

int N, V;
int dist[maxn][2];
vector<ii> g[maxn];

int dijkstra ()
{
  memset(dist, inf, sizeof dist);
  dist[0][0] = 0;

  priority_queue<tri,vector<tri>,cmp> pq;
  pq.push(mt(0, 0, 0));
  while (!pq.empty())
  {
    tri top = pq.top();
    pq.pop();
    int d = top.fst;
    int u = top.snd.fst;
    int k = top.snd.snd;

    if (d > dist[u][k]) continue;

    k ^= 1;
    for (int i = 0; i < (int)g[u].size(); ++i)
    {
      int v = g[u][i].fst;
      int c = g[u][i].snd;
      if (d + c < dist[v][k])
      {
        dist[v][k] = d + c;
        pq.push(mt(d + c, v, k));
      }
    }
  }

  return (dist[N - 1][0] == inf ? -1 : dist[N - 1][0]);
}

int main()
{
  // freopen("ain", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  while (cin >> N >> V)
  {
    for (int i = 0; i < N; ++i) g[i].clear();
    while (V--)
    {
      int C1, C2, G;
      cin >> C1 >> C2 >> G, --C1, --C2;
      g[C1].push_back(ii(C2, G));
      g[C2].push_back(ii(C1, G));
    }

    cout << dijkstra() << '\n';
  }

  return 0;
}
