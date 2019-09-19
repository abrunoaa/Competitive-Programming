#include <bits/stdc++.h>
using namespace std;

int mat[10][10];
int g[100][100];

int get(char c, int i) {
  return mat[c - 'a' + 1][i];
}

void build() {
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j) {
      mat[i][j] = (i - 1) * 8 + j;
    }
  }
  static int I[] = {-2, -1, 1, 2, 2, 1, -1, -2};
  static int J[] = {-1, -2, -2, -1, 1, 2, 2, 1};
  memset(g, 63, sizeof(g));
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j) {
      int u = mat[i][j];
      for (int k = 0; k < 8; ++k) {
        int a = i + I[k];
        int b = j + J[k];
        if (1 <= a && a <= 8 && 1 <= b && b <= 8) {
          g[u][mat[a][b]] = 1;
        }
      }
    }
  }
  for (int u = 1; u <= 64; ++u) {
    g[u][u] = 0;
  }
}

void floyd() {
  for (int w = 1; w <= 64; ++w)
    for (int u = 1; u <= 64; ++u)
      for (int v = 1; v <= 64; ++v)
        g[u][v] = min(g[u][v], g[u][w] + g[w][v]);
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  build();
  floyd();
  int t;
  cin >> t;
  while (t--) {
    char c1, c2;
    int t1, t2;
    cin >> c1 >> t1 >> c2 >> t2;
    cout << g[get(c1, t1)][get(c2, t2)] << '\n';
  }
  return 0;
}
