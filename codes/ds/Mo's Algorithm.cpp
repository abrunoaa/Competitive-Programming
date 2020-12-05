#include <bits/stdc++.h>
using namespace std;

const int maxn = 100003;
const int maxq = 100003;

/** begin *********************************************************************/
struct Qry { int l, r, id; };

int cur, ans[maxq];
int n, m, v[maxn];
Qry q[maxq];

/* add/remove an index and updates the current answer */
void add(int) {}
void rem(int) {}

void mo() { // O(n * sqrt(n) * u), where u is the cost to add/remove an index
  int bs = (int)sqrt(n);
  sort(q, q + m, [bs](const Qry& x, const Qry& y) {
    int bx = x.l / bs, by = y.l / bs;
    if (bx != by) return bx < by;
    return bx % 2 == 0 ? x.r < y.r : x.r > y.r;
  });
  int mol = 0, mor = -1;
  for (int i = 0; i < m; ++i) {
    auto [l, r, id] = q[i];
    while (mor < r) add(++mor);
    while (mor > r) rem(mor--);
    while (mol < l) rem(mol++);
    while (mol > l) add(--mol);
    ans[id] = cur;  // answers the range [l, r] in O(1)
  }
}
/** end ***********************************************************************/

int main() {
  return 0;
}
