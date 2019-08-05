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
#define zero(x) (fabs(x) < eps)
#define inf 0x3f3f3f3f
#define mod 1000000007
#define maxn 100010

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
#define db(x...) cerr << " >>", db(x)
#else
struct _ { _() { cin.sync_with_stdio(0), cin.tie(0); } } _;
#define db(x...)
#endif

int n, m, bs, power[maxn];
tri v[maxn];

void build_blk(int b) {
  int beg = b * bs, end = min((b + 1) * bs, n);
  for (int i = end - 1; i >= beg; --i) {
    if (i + power[i] < end) {
      v[i] = v[i + power[i]];
      ++v[i].st.nd;
    } else {
      v[i] = tri(ii(i + power[i], 1), i);
    }
  }
}

void build() {
  bs = sqrt(n);
  for (int i = (n - 1) / bs; i >= 0; --i) {
    build_blk(i);
  }
}

void upd(int i, int p) {
  power[i] = p;
  build_blk(i / bs);
}

ii qry(int i) {
  ii ans(0, 0);
  while (i < n) {
    ans.st = v[i].nd;
    ans.nd += v[i].st.nd;
    i = v[i].st.st;
  }
  return ans;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) { cin >> power[i]; }

  build();
  while (m--) {
    int op, a, b;
    cin >> op;
    if (op == 0) {
      cin >> a >> b;
      upd(a - 1, b);
    } else {
      cin >> a;
      // for (int i = 0; i < n; ++i) cerr << '(' << v[i].st.st << "," << v[i].st.nd << ") "; cerr << endl;
      ii ans = qry(a - 1);
      cout << ans.st + 1 << ' ' << ans.nd << '\n';
    }
  }

  return 0;
}
