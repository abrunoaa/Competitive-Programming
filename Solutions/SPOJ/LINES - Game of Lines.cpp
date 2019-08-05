#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9
#define maxn 210

typedef double lf;

int x[maxn], y[maxn];

bool cmp(lf x, lf y) {
  if (isinf(x)) { return 0; }
  if (isinf(y)) { return 1; }
  return x <= y - eps;
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n;
  while (cin >> n && n) {
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
    }

    set<lf, bool(*)(lf, lf)> lines(cmp);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        lines.insert(lf(y[j] - y[i]) / (x[j] - x[i]));
      }
    }

    cout << lines.size() << '\n';
  }

  return 0;
}
