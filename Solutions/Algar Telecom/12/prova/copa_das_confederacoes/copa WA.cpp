#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("in", "r", stdin);

  register int i, j;
  int t, n, k, u, v, gr[320];
  ulong s;
  bool adj[320][320];

  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);

    for (i = n; i--; )
      for (j = n; j--; ) {
        adj[i][j] = 1;
      }

    while (k--) {
      scanf("%d%d", &u, &v);
      adj[u][v] = adj[v][u] = 0;
    }

    for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) {
        if (!vis[i][j] && adj[i][j]) {
        }
      }
    }
  }

  return 0;
}
