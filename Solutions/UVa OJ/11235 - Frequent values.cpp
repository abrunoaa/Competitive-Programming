#include <bits/stdc++.h>
using namespace std;

#define gcd __gcd
#define popcnt __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define eps 1e-9
#define zero(x) (abs(x) < eps)
#define pi acos(-1.0l)
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 200010

typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
typedef pair<ii, int> tri;
typedef pair<ii, ii> qua;
typedef vector<int> vi;
typedef vector<ii> vii;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class t>
using Set = tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>;
template<class t, class u>
using Map = tree<t, u, less<t>, rb_tree_tag, tree_order_statistics_node_update>;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << ' ' << x, db(y...); }

#if !defined ONLINE_JUDGE || defined LOCAL
__attribute__((destructor)) static void destroy()
{ cerr << "\nTime elapsed: " << (lf)clock() / CLOCKS_PER_SEC << "s.\n"; }

#define db(x...) cerr << " >> [" #x "] =", db(x)
#else
#warning "JUDGE"
#define NDEBUG
#define db(...) 42
#endif

template<class t> t sq(t x) { return x * x; }

#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)

int n, q, a[maxn], v[maxn], pmin[maxn], pmax[maxn], st[4 * maxn];

int build(int k = 1, int l = 0, int r = n - 1) {
  if (l == r) { return st[k] = v[l]; }
  return st[k] = max(build(L, l, M), build(R, M + 1, r));
}

int qry(int i, int j, int k = 1, int l = 0, int r = n - 1) {
  if (r < i || j < l) { return -inf; }
  if (i <= l && r <= j) { return st[k]; }
  return max(qry(i, j, L, l, M), qry(i, j, R, M + 1, r));
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  while (cin >> n >> q && n) {
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    a[n] = -inf;

    for (int i = 0, j; i < n; i = j) {
      for (j = i + 1; a[i] == a[j]; ++j);
      for (int k = i; k < j; ++k) {
        v[k] = j - i;
        pmin[k] = i - 1;
        pmax[k] = j;
      }
    }

    memset(st, 0, sizeof st);
    build();
    while (q--) {
      int l, r;
      cin >> l >> r, --l, --r;
      if (a[l] == a[r]) {
        cout << r - l + 1 << endl;
      } else {
        int m1 = pmax[l], m2 = pmin[r];
        cout << max(qry(m1, m2), max(m1 - l, r - m2)) << endl;
      }
    }
  }

  return 0;
}
