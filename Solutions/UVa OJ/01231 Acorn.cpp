#include <bits/stdc++.h>
using namespace std;

#define maxn 2010

int t, h, f;
int best[maxn];
int pd[maxn][maxn];
int acorn[maxn][maxn];

int solve() {
  memset(best, 0, sizeof best);
  memset(pd, 0, sizeof pd);

  for (int hh = 1; hh <= h; ++hh)
    for (int a = 0; a < t; ++a) {
      if (hh >= f) {
        pd[hh][a] = max(best[hh - f], pd[hh - 1][a]) + acorn[hh][a];
      } else {
        pd[hh][a] = pd[hh - 1][a] + acorn[hh][a];
      }

      best[hh] = max(best[hh], pd[hh][a]);
    }

  return best[h];
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  int ct, p, aux;

  cin >> ct;
  while (ct--) {
    memset(acorn, 0, sizeof acorn);

    cin >> t >> h >> f;
    for (int i = 0 ; i < t ; ++i) {
      cin >> p;
      for (int j = 0 ; j < p ; ++j) {
        cin >> aux;
        ++acorn[aux][i];
      }
    }

    cout << solve() << '\n';
  }

  return 0;
}
