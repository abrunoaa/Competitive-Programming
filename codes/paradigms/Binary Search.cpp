#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e7;

int n;
int v[maxn];

inline int f(int i) { return v[i]; }

/** begin *********************************************************************/
int bs(int x) {               // returns the first i such that f(i) >= x
  int i = 0, j = n;
  while (i < j) {
    int m = (i + j) / 2;
    f(m) < x ? i = m + 1 : j = m;       // `<=` for the first i with f(i) > x
  }
  return i;
}
/** end ***********************************************************************/

int main() {
  n = maxn;
  int maxv = (int)1e5;
  srand(0);
  generate(v, v + n, [&]() { return rand() % maxv; });
  sort(v, v + n);
  for (int x = 0; x <= maxv; ++x) {
    int i = bs(x);
    // cerr << i << ' ' << (i == maxn ? -1 : v[i]) << ' ' << x << endl;
    assert(i == maxn || v[i] >= x);
    assert(i == 0 || v[i - 1] < x);
  }
  return 0;
}
