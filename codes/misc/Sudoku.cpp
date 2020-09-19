#include <bits/stdc++.h>
using namespace std;

int n, n2, n4, ans, bml[10], bmc[10], bmb[10][10], mat[10][10];

bool solve(int pos) {
  if (pos == n4) return 1;
  int l = pos / n2, c = pos % n2;
  if (mat[l][c] != 0) return solve(pos + 1);      // já tá preenchido
  int bm = bml[l] | bmc[c] | bmb[l / n][c / n];   // quem pode colocar?
  for (int k = 0; k < n2; ++k)
    if (!(bm & (1 << k))) {             // pode usar o nº k
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
  return 0;
}

int main() {
  while (cin >> n) {          // sudoku n^2 x n^2 (1 a n^2)
    n2 = n * n;
    n4 = n2 * n2;
    ans = (1 << n2) - 1;
    memset(bml, 0, sizeof bml);
    memset(bmc, 0, sizeof bmc);
    memset(bmb, 0, sizeof bmb);
    for (int i = 0; i < n2; ++i)
      for (int j = 0; j < n2; ++j) {
        int &x = mat[i][j];
        cin >> x;
        if (x) {                        // x = 0 ==> vazio
          int k = 1 << (x - 1);
          bml[i] |= k;                  // bloqueia na linha
          bmc[j] |= k;                  // bloqueia na coluna
          bmb[i / n][j / n] |= k;       // bloqueia no bloco
        }
      }
    if (!solve(0))
      cout << "NO SOLUTION\n";
    else
      for (int i = 0; i < n2; ++i) {
        for (int j = 0; j < n2; ++j) {
          if (j) cout << ' ';
          cout << mat[i][j];
        }
        cout << '\n';
      }
  }
  return 0;
}
