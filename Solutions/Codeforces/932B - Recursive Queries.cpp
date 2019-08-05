#include <bits/stdc++.h>
using namespace std;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << " " << x, db(y...); }

#define db(x...) cerr << " >>", db(x)
#define gcd __gcd
#define st first
#define nd second
#define eps 1e-9
#define zero(x) (fabs(x) < eps)
#define inf 0x3f3f3f3f
#define mod 1000000007
#define maxn 1000010

typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
typedef pair<int, ii> tri;
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> Map;

int memo[maxn], ans[maxn][10];

int f(int x) {
  int t = 1;
  while (x) {
    if (x % 10) { t *= x % 10; }
    x /= 10;
  }
  return t;
}

int g(int x) {
  if (x < 10) { return x; }
  int &pd = memo[x];
  if (pd != -1) { return pd; }
  return pd = g(f(x));
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);

  memset(memo, -1, sizeof memo);

  for (int i = 1; i < maxn; ++i) {
    for (int j = 0; j < 10; ++j) {
      ans[i][j] = ans[i - 1][j];
    }
    ++ans[i][g(i)];
    // if (i < 100) db(i, " == ", g(i));
  }

  int q, l, r, k;

  cin >> q;
  while (q--) {
    cin >> l >> r >> k;
    // db(ans[r][k], ans[l - 1][k]);
    cout << ans[r][k] - ans[l - 1][k] << '\n';
  }

  return 0;
}

