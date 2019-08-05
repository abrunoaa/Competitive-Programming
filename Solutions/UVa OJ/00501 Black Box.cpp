#include <bits/stdc++.h>
using namespace std;

int main() {
  //freopen("in", "r", stdin);

  int k, m, n, i, aux, c, p, beg, a[30005];
  multiset<int> u, nums;
  multiset<int>::iterator pos;

  scanf("%d", &k);
  while (k--) {
    scanf("%d%d", &m, &n);
    for (i = 0; i < m; ++i) {
      scanf("%d", a + i);
    }
    for (i = 0; i < n; ++i) {
      scanf("%d", &aux);
      u.insert(aux);
    }

    p = 1;
    nums.insert(a[0]);
    pos = nums.begin();
    beg = *u.begin();
    c = 0;
    i = 1;
    while (1)
      if (i == beg) {
        //~ cerr << " >> " << p << " " << c << endl;
        ++c;
        if (p >= c) {
          if (p - c > c) {
            pos = nums.begin();
            advance(pos, c - 1);
          } else {
            advance(pos, c - p);
          }
        } else {
          // p < c
          if (c - p > (int)nums.size() - c) {
            pos = nums.end();
            advance(pos, c - nums.size() - 1);
          } else {
            advance(pos, c - p);
          }
        }
        p = c;

        printf("%d\n", *pos);
        u.erase(u.begin());
        if (u.empty()) {
          break;
        }
        beg = *u.begin();
      } else {
        if (a[i] < *pos) {
          ++p;
        }
        nums.insert(a[i]);
        ++i;
      }

    u.clear();
    nums.clear();

    if (k) { puts(""); }
  }

  return 0;
}
