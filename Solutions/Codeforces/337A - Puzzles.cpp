#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define endl '\n'

typedef pair<int, int> ii;

const int inf = 1e9;
int n, m, i, j, v[51];
map<ii, ii> memo[51][51];

ii put (int x, ii p) { return ii(max(x, p.fst), min(x, p.snd)); }
ii min (ii x, ii y) { return (abs(x.fst - x.snd) < abs(y.fst - y.snd)) ? x : y; }

ii shop (int p, int rem, ii mm) {
  if (!rem) { return mm; }
  if (p == m) { return ii(inf, -inf); }

  if (memo[p][rem].find(mm) != memo[p][rem].end()) { return memo[p][rem][mm]; }

  return memo[p][rem][mm] = min(shop(p + 1, rem, mm), shop(p + 1, rem - 1, put(v[p], mm)));
}

int main() {
  // freopen("in", "r", stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  while (cin >> n >> m) {
    for (i = 0; i < m; ++i) { cin >> v[i]; }

    if (n == m) {
      cout << *max_element(v, v + m) - *min_element(v, v + m) << endl;
    } else {
      ii ans = shop(0, n, ii(-inf, inf));
      cout << abs(ans.fst - ans.snd) << endl;

      for (i = 51; i--; )
        for (j = 51; j--; ) {
          memo[i][j].clear();
        }
    }
  }

  return 0;
}
