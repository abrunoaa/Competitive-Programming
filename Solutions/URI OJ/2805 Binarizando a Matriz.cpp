#include <bits/stdc++.h>
using namespace std;

const int maxn = 103;
const int mod = (int)1e9 + 7;

int n, m;
char mat[maxn][maxn];
int memo[maxn][maxn];

inline int upd(int x) {
  if (x >= mod) x -= mod;
  return x;
}

int f(int i, int j) {
  if (i == n || j < 0) return 1;
  int &dp = memo[i][j];
  if (dp != -1) return dp;
  if (mat[i][j] == '1') return dp = f(i + 1, j);
  dp = 0;
  for (int k = i; k < n; ++k) {
    dp = upd(dp + f(k, j - 1));
    if (mat[k][j] == '0') return dp;
  }
  return dp = upd(dp + 1);
}

void process() {
  for (int j = m - 1; j >= 0; --j) {
    if (j > 0) {
      for (int i = n - 1; i >= 0; --i) {
        if (mat[i][j] == '1') {
          if (mat[i][j - 1] == '0') {
            cout << "0\n";
            exit(0);
          }
          mat[i][j - 1] = '1';
        }
      }
    }
    for (int i = n - 2; i >= 0; --i) {
      if (mat[i + 1][j] == '1') {
        if (mat[i][j] == '0') {
          cout << "0\n";
          exit(0);
        }
        mat[i][j] = '1';
      }
    }
  }
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
      memo[i][j] = -1;
    }
  }
  process();
  cout << f(0, m - 1) << '\n';
  return 0;
}
