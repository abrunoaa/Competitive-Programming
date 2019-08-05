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
#define maxn 100010

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

int n, k, a[maxn];
ll ft[12][maxn];

void upd(ll* ft, int i, ll x) {
  for (; i; i -= i & -i) {
    ft[i] += x;
  }
}

ll qry(ll* ft, int i) {
  ll s = 0;
  for (; i < maxn; i += i & -i) {
    s += ft[i];
  }
  return s;
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> k;
  if (k == 0) {
    cout << n << endl;
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  ll ans = 0;
  for (int i = n; i; --i) {
    upd(ft[1], a[i], +1);
    for (int j = 2; j <= k; ++j) {
      upd(ft[j], a[i], qry(ft[j - 1], a[i] + 1));
    }
    ans += qry(ft[k], a[i] + 1);
  }
  cout << ans << endl;

  return 0;
}
