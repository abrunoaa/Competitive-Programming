#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> matrix;

int mod;

// retorna a[n,m] * b[m,p]
matrix operator * (const matrix &a, const matrix &b) {
  int n = a.size();
  int m = b.size();
  int p = b[0].size();

  matrix c;
  c.resize(n);
  for (int i = 0; i < n; ++i) {
    c[i].assign(p, 0);
    for (int j = 0; j < p; ++j)
      for (int k = 0; k < m; ++k) {
        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) & mod;
      }
  }

  return c;
}

// constrói matriz identidade I[n,n]
matrix identity(int n) {
  matrix x(n);
  for (int i = 0; i < n; ++i) {
    x[i].assign(n, 0);
    x[i][i] = 1;
  }
  return x;
}

// retorna b[n,n] ** e
matrix pow(matrix b, int e) {
  matrix x = identity(b.size());
  while (1) {                 // fastExp normal
    if (e % 2) { x = x * b; }
    if (!(e /= 2)) { return x; }
    b = b * b;
  }
}

// retorna fib(n) ==> fib(0) = 0 (i.e. começa a partir do zero)
int nthFib(int n) {
  if (n == 0) { return 0; }
  return pow(matrix{{1, 1}, {1, 0}}, n - 1)[0][0];
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    mod = (1 << m) - 1;
    cout << nthFib(n) << '\n';
  }

  return 0;
}
