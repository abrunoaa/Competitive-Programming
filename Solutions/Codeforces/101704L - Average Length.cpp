#include <bits/stdc++.h>
using namespace std;
#define maxn 104
#define inf 9999999
typedef long long ll;

ll g[maxn][maxn];

int main() {
  //~ freopen("in","r",stdin);

  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n ; i++)
    for (int j = 0; j < n; j++) {
      g[i][j] = inf;
    }

  while (m--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    g[a - 1][b - 1] = c;
  }

  for (int k = 0; k < n; k++)
    for (int i = 0; i < n ; i++)
      for (int j = 0; j < n ; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }

  ll cont = 0;
  double sum = 0;

  for (int i = 0; i < n ; i++)
    for (int j = 0; j < n; j++) {
      if (g[i][j] >= inf || i == j) { continue; }
      sum += g[i][j];
      cont++;
    }

  printf("%.6lf\n", sum / (double)cont);
}
