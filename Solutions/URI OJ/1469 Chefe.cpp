// modelagem + travessia de grafo

#include <bits/stdc++.h>
using namespace std;

typedef vector < int > vi;
typedef vector < vi > vvi;

const int inf = 1e9;
char op;
int n, m, l, ans, i, x, y, a, b, e, k[505], emp[505];
vi vis;
vvi adj;

// atravessa o grafo
void dfs(int u) {
  vis[u] = 1;
  for (int i = 0; i < (int)adj[u].size(); ++i) {
    int v = adj[u][i];
    if (!vis[v]) {
      ans = min(ans, k[v]), dfs(v);  // mod: pega a menor idade
    }
  }
}

int main() {
  while (scanf("%d%d%d", &n, &m, &l) == 3) {
    adj.assign(n, vi());

    for (i = 0; i < n; ++i) { emp[i] = i; }                         // reseta empregados
    for (i = 0; i < n; ++i) { scanf("%d", k + i); }
    for (i = 0; i < m; ++i) { scanf("%d%d", &x, &y), adj[y - 1].push_back(x - 1); }

    while (l--) {
      scanf(" %c", &op);
      if (op == 'T') {
        scanf("%d%d", &a, &b);
        --a, --b;
        swap(k[emp[a]], k[emp[b]]);                             // "troca" idades
        swap(emp[a], emp[b]);                                   // e empregados
      } else {
        scanf("%d", &e);

        ans = inf;
        vis.assign(n, 0);
        dfs(emp[e - 1]);

        if (ans < inf) { printf("%d\n", ans); }
        else { puts("*"); }
      }
    }
  }

  return 0;
}
