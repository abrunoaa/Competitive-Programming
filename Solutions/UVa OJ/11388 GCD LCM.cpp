#include <bits/stdc++.h>
using namespace std;

int mdc (int a, int b) { return b ? mdc(b, a % b) : a; }
int mmc (int a, int b) { return a * (b / mdc(a, b)); }

int main() {
  // freopen("in", "r", stdin);
  // freopen("out", "w", stdout);

  int t, g, l, i, lim, a, b;
  vector<int> div;

  scanf("%d", &t);
  while (t--) {
    div.clear();

    scanf("%d%d", &g, &l);

    if (l % g) { puts("-1"); }
    else { printf("%d %d\n", g, l); }
    continue;

    for (i = 1, lim = sqrt(l); i < lim; ++i)
      if (l % i == 0) {
        div.push_back(i), div.push_back(l / i);
      }
    if (l % lim == 0) {
      div.push_back(l / lim);
      if (lim * lim != l) { div.push_back(lim); }
    }
    sort(div.rbegin(), div.rend());

    a = -1;
    for (auto x : div)
      for (auto y : div)
        if (mdc(x, y) == g && mmc(x, y) == l) {
          a = x;
          b = y;
          goto fim;
        }
  fim:

    if (a > b) { swap(a, b); }

    if (a == -1) { puts("-1"); }
    else { printf("%d %d\n", a, b); }
  }

  return 0;
}
