#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("in", "r", stdin);

  int T, n, p, q, i, aux, pos, lis, cs = 0;
  int L[65000], ar[65000];
  map < int, int > mp;

  scanf("%d", &T);
  while (T--) {
    mp.clear();

    scanf("%d%d%d", &n, &p, &q);
    ++p, ++q;

    for (i = 1; i <= p; ++i) {
      scanf("%d", &aux);
      mp[aux] = i;
    }
    for (i = 0; i < q; ++i) {
      scanf("%d", &aux);
      ar[i] = mp[aux];
    }

    lis = 0;
    for (i = 0; i < q; ++i) {
      if (!ar[i]) { continue; }
      //printf("%d ", ar[i]);
      pos = lower_bound(L, L + lis, ar[i]) - L;
      L[pos] = ar[i];

      if (pos + 1 > lis) {
        lis = pos + 1;
      }
    }

    printf("Case %d: %d\n", ++cs, lis);
  }

  return 0;
}
