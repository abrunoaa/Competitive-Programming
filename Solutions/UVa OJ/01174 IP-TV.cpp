#include <bits/stdc++.h>
using namespace std;

typedef pair < int, int > ii;
typedef vector < ii > vii;
typedef vector < vii > vvii;

const int inf = 1e9;
bool vis[2500];
int m;
vvii adj;
priority_queue < ii > pq;

void primh (register int u) {
  ii v;
  vis[u] = 1;
  for (register int i = 0, size = adj[u].size(); i < size; ++i) {
    v = adj[u][i];
    if (!vis[v.first]) { pq.push(ii(-v.second, -v.first)); }
  }
}

int prim () {
  register int u, cost = 0;
  for (u = m + 1; --u; vis[u] = 0);
  primh(1);
  ii v;
  while (!pq.empty()) {
    v = pq.top();
    pq.pop();
    u = -v.second;
    if (!vis[u]) {
      cost -= v.first;
      primh(u);
    }
  }
  return cost;
}

int main() {
  //freopen("in", "r", stdin);

  char c1[1000], c2[1000];
  int T, n, w, c;
  map < string, int > mp;

  scanf("%d", &T);
  while (--T >= 0) {
    scanf("%d%d", &m, &n);
    adj.assign(n, vii());
    c = 0;
    while (--n >= 0) {
      scanf(" %s %s%d", c1, c2, &w);

      if (!mp[c1]) { mp[c1] = ++c; }
      if (!mp[c2]) { mp[c2] = ++c; }

      adj[mp[c1]].push_back(ii(mp[c2], w));
      adj[mp[c2]].push_back(ii(mp[c1], w));
    }

    printf("%d\n", prim());
    if (T)	{ printf("\n"); }

    mp.clear();
  }
  return 0;
}
