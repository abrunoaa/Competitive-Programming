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
#define pb push_back
#define eps 1e-9
#define zero(x) (fabs(x) < eps)
#define inf 0x3f3f3f3f
#define mod 1000000007
#define maxn 100010

typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
typedef pair<int, ii> tri;
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> Map;

#ifdef LOCAL
struct _S { _S() { assert(freopen("in", "r", stdin)); } } _S;
#else
struct _S { _S() { cin.sync_with_stdio(0), cin.tie(0); } } _S;
#define db(x...)
#endif

int v[maxn];

int main() {
  int n;

  cin >> n;
  for (int i = 0; i < n; ++i) { cin >> v[i]; }//, db(v[i]);

  int i;
  for (i = 0; i < n && v[i] <= 500000; ++i) {
  }
  --i;

  int j;
  for (j = n - 1; j >= 0 && v[j] > 500000; --j) {
  }
  ++j;

  // db(i, v[i]);
  // db(j, v[j]);

  int ans = max((i >= 0 ? v[i] - 1 : 0), (j < n ? 1000000 - v[j] : 0));
  cout << ans << '\n';

  return 0;
}
