#include <bits/stdc++.h>
using namespace std;

typedef pair < int, int > ii;
typedef pair < ii, int > iii;

ii dis[1010];
iii ar[1010];

bool cmp (ii i1, ii i2)
{ return i1.first <= i2.first || i1.second >= i2.second; }

void print(int v) {
  if (v < 0) {
    return;
  }
  print(dis[v].second);
  printf("%d\n", ar[v].second);
}

int main() {
  //freopen("in", "r", stdin);

  int n, i, j, p, e, m, d, w, s;

  for (n = 0; scanf("%d%d", &w, &s) > 0; ++n) {
    ar[n] = iii(ii(-s, w), n + 1);
  }

  sort(ar, ar + n);

  for (i = 0; i < n; ++i) {
    swap(ar[i].first.first, ar[i].first.second);
    ar[i].first.second *= -1;
  }

  for (i = 0; i < n; ++i) {
    p = d = -1;
    for (j = 0; j < i; ++j)
      if (!cmp(ar[i].first, ar[j].first) && dis[j].first > d) {
        d = dis[j].first;
        p = j;
      }

    if (p < 0) { dis[i] = ii(1, -1); }
    else { dis[i] = ii(dis[p].first + 1, p); }
  }

  m = 0;
  for (i = 0; i < n; ++i)
    if (dis[i].first > m) {
      m = dis[i].first;
      e = i;
    }

  printf("%d\n", m);
  print(e);

  return 0;
}
