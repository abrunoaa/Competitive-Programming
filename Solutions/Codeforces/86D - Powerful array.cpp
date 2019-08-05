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
#define maxn 200010

typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
typedef pair<ii, int> tri;
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> Map;

#ifdef LOCAL
struct _ { _() { assert(freopen("in", "r", stdin)); } } _;
#else
struct _ { _() { cin.sync_with_stdio(0), cin.tie(0); } } _;
#define db(x...)
#endif

int n, m, a[maxn], f[1000010] = {};
ll cur = 0, ans[maxn];
tri qry[maxn];

inline void add(int k) { cur += (2ll * f[k]++ + 1) * k; }
inline void rem(int k) { cur -= (2ll * f[k]-- - 1) * k; }

void mo() {
  int bs = sqrt(n);
  sort(qry, qry + m, [bs](const tri & x, const tri & y) {
    int bx = x.st.st / bs, by = y.st.st / bs;
    return (bx != by ? bx < by : x.st.nd < y.st.nd);
  });

  int ml = 0, mr = -1;

  for (int i = 0; i < m; ++i) {
    auto &q = qry[i];
    int l = q.st.st - 1;
    int r = q.st.nd - 1;
    int p = q.nd;

    while (mr < r) { add(a[++mr]); }
    while (mr > r) { rem(a[mr--]); }
    while (ml < l) { rem(a[ml++]); }
    while (ml > l) { add(a[--ml]); }

    ans[p] = cur;
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) { cin >> a[i]; }
  for (int i = 0; i < m; ++i) {
    auto &q = qry[i];
    cin >> q.st.st >> q.st.nd;
    q.nd = i;
  }

  mo();
  for (int i = 0; i < m; ++i) { cout << ans[i] << '\n'; }

  return 0;
}
