#include <bits/stdc++.h>
using namespace std;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << " " << x, db(y...); }

#define gcd __gcd
#define st first
#define nd second
#define pb push_back
#define eps 1e-9
#define zero(x) (abs(x) < eps)
#define inf 0x3f3f3f3f
#define mod 1000000009
#define maxn 210

typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
typedef pair<ii, int> tri;
typedef vector<int> vi;
typedef vector<ii> vii;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> Map;

#ifndef ONLINE_JUDGE
struct _ { _() { assert(freopen("in", "r", stdin)); } } _;
#define db(x...) cerr << " >>", db(x)
#else
#warning "ONLINE_JUDGE"
struct _ { _() { cin.sync_with_stdio(0), cin.tie(0); } } _;
#define db(x...)
#endif

bool vis[maxn][maxn] = {};
int h, l;
int m[maxn][maxn];
int X[] = {-1, 0, +1, 0}, Y[] = {0, +1, 0, -1};

int conta(int x, int y, int c) {
  if (x < 0 || x >= h || y < 0 || y >= l || m[x][y] != c || vis[x][y]) { return 0; }

  vis[x][y] = 1;
  int k = 1;
  for (int i = 0; i < 4; ++i) {
    k += conta(x + X[i], y + Y[i], c);
  }
  return k;
}

int main() {
  cin >> h >> l;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < l; ++j) {
      cin >> m[i][j];
    }
  }

  int ans = inf;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < l; ++j) {
      if (!vis[i][j]) {
        ans = min(ans, conta(i, j, m[i][j]));
      }
    }
  }

  cout << ans << '\n';

  return 0;
}

