#include <bits/stdc++.h>
using namespace std;

typedef int Int;

// #define int long long
#define maxn 100010
#define mod 5000000

int n, k;
int bit[maxn][55] = {};

void upd(int x, int y, int v)
{ for (; x < maxn; x += x & -x) bit[x][y] = (bit[x][y] + v) % mod; }

int qry(int x, int y) {
  int s = 0;
  for (; x; x -= x & -x) { s = (s + bit[x][y]) % mod; }
  return s;
}

Int main() {
  // freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> k;
  for (int i = 0, s; i < n; ++i) {
    cin >> s, ++s;
    upd(s, 1, 1);
    for (int j = 2; j <= k; ++j) {
      upd(s, j, qry(s - 1, j - 1));
    }
  }

  cout << qry(maxn - 1, k) << '\n';

  return 0;
}
