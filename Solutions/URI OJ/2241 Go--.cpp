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
#define maxn 510

typedef long long ll;
typedef long double lf;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> tri;
typedef vector<ll> vi;
typedef vector<ii> vii;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<ll, ll, less<ll>, rb_tree_tag, tree_order_statistics_node_update> Map;

#ifndef ONLINE_JUDGE
struct _ { _() { assert(freopen("in", "r", stdin)); } } _;
#define db(x...) cerr << " >>", db(x)
#else
#warning "ONLINE_JUDGE"
struct _ { _() { cin.sync_with_stdio(0), cin.tie(0); } } _;
#define db(x...)
#endif

int n, P;
int p[maxn][maxn] = {}, b[maxn][maxn] = {};

int main() {
  cin >> n >> P;
  for (int i = 0, x, y; i < P; ++i) {
    cin >> x >> y;
    p[x][y] = 1;
  }
  for (int i = 0, x, y; i < P; ++i) {
    cin >> x >> y;
    b[x][y] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
      b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
      // db(i, j, p[i][j], b[i][j]);
    }
  }

  int ansp = P, ansb = P;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; i + k <= n && j + k <= n; ++k) {
        int pr = p[i + k][j + k] - p[i + k][j - 1] - p[i - 1][j + k] + p[i - 1][j - 1];
        int br = b[i + k][j + k] - b[i + k][j - 1] - b[i - 1][j + k] + b[i - 1][j - 1];
        // db(i, j, k, pr, br, " == ", p[i + k][j + k], p[i + k][j - 1], p[i - 1][j + k],p[i - 1][j - 1]);
        if (pr && br) {
          break;
        }
        if (pr) {
          ++ansp;
        } else if (br) {
          ++ansb;
        }
      }
    }
  }

  cout << ansp << ' ' << ansb << '\n';

  return 0;
}

