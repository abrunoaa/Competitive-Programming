#include <bits/stdc++.h>
using namespace std;

int mdc(int a, int b) { return b ? mdc(b, a % b) : a; }

int main() {
  vector<int> v;
  v.reserve(60);
  int n, mdceq1, i, tmp, j, pairs;

  while (scanf("%d", &n) == 1 && n) {
    v.clear();
    mdceq1 = pairs = 0;

    for (i = 0; i < n; ++i) { scanf("%d", &tmp), v.push_back(tmp); }
    for (i = 0; i < n - 1; ++i)
      for (j = i + 1; j < n; ++j) {
        if (mdc(v[i], v[j]) == 1) { ++mdceq1; }
        ++pairs;
      }

    if (!mdceq1) { puts("No estimate for this data set."); }
    else { printf("%.6lf\n", sqrt(6.0 * pairs / mdceq1)); }
  }

  return 0;
}
