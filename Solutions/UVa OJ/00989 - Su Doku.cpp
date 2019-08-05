#include <bits/stdc++.h>
using namespace std;

int n, n2, n4;  // n, n^2, n^4
int ans;  // 2^n2 - 1
int bml[10], bmc[10], bmb[10][10];
int mat[10][10];

bool solve(int pos) {
  if (pos == n4) {
    for (int i = 0; i < n2; ++i) {
      if (bml[i] != ans) {
        return 0;
      }
    }
    return 1;
  }

  int l = pos / n2, c = pos % n2;
  if (mat[l][c] != 0) { return solve(pos + 1); }

  int bm = bml[l] | bmc[c] | bmb[l / n][c / n];
  for (int k = 0; k < n2; ++k) {
    if (!(bm & (1 << k))) {
      bml[l] ^= 1 << k;
      bmc[c] ^= 1 << k;
      bmb[l / n][c / n] ^= 1 << k;
      if (solve(pos + 1)) {
        mat[l][c] = k + 1;
        return 1;
      }
      bml[l] ^= 1 << k;
      bmc[c] ^= 1 << k;
      bmb[l / n][c / n] ^= 1 << k;
    }
  }

  return 0;
}

int main() {
  // freopen("in","r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  bool flag = 0;
  while (cin >> n) {
    if (flag) { cout << '\n'; }
    flag = 1;

    n2 = n * n;
    n4 = n2 * n2;
    ans = (1 << n2) - 1;

    memset(bml, 0, sizeof bml);
    memset(bmc, 0, sizeof bmc);
    memset(bmb, 0, sizeof bmb);
    for (int i = 0; i < n2; ++i) {
      for (int j = 0; j < n2; ++j) {
        int &x = mat[i][j];
        cin >> x;
        if (x) {
          bml[i] |= (1 << (x - 1));
          bmc[j] |= (1 << (x - 1));
          bmb[i / n][j / n] |= (1 << (x - 1));
        }
      }
    }

    if (!solve(0)) {
      cout << "NO SOLUTION\n";
    } else {
      for (int i = 0; i < n2; ++i) {
        for (int j = 0; j < n2; ++j) {
          if (j) { cout << ' '; }
          cout << mat[i][j];
        }
        cout << '\n';
      }
    }
  }

  return 0;
}
