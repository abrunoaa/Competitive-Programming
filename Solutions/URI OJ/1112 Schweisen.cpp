#include <bits/stdc++.h>
using namespace std;

#define maxn 1010

int larg, alt;
int bit[maxn][maxn];

void add(int x, int y, int v) {
  for (int i = x + 1; i <= larg; i += i & -i)
    for (int j = y + 1; j <= alt; j += j & -j) {
      bit[i][j] += v;
    }
}

int sum(int x, int y) {
  int s = 0;

  for (int i = x + 1; i; i -= i & -i)
    for (int j = y + 1; j; j -= j & -j) {
      s += bit[i][j];
    }

  return s;
}

int query(int x1, int y1, int x2, int y2) {
  if (x2 < x1) { swap(x1, x2); }
  if (y2 < y1) { swap(y1, y2); }
  return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  int p, q;
  while (cin >> larg >> alt >> p >> q && (larg || alt || p)) {
    memset(bit, 0, sizeof bit);

    while (q--) {
      char op;
      cin >> op;
      if (op == 'A') {
        int n, x, y;
        cin >> n >> x >> y;
        add(x, y, n);
      } else {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << p* query(a, b, c, d) << '\n';
      }
    }
    cout << '\n';
  }

  return 0;
}
