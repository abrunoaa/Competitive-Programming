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
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 100010

typedef long long ll;
typedef long double lf;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> tri;
typedef pair<ii, ii> qua;
typedef vector<ll> vi;
typedef vector<ii> vii;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<ll, ll, less<ll>, rb_tree_tag, tree_order_statistics_node_update> Map;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << ' ' << x, db(y...); }

#ifdef LOCAL
__attribute__((destructor)) static void destroy()
{ cerr << "\nTime elapsed: " << (lf)clock() / CLOCKS_PER_SEC << "s.\n"; }

#define db(x...) cerr << " >> [" #x "] =", db(x)
#else
#warning "JUDGE"
#define NDEBUG
#define db(...) 42
#endif

ll n, a[maxn];

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] += a[i - 1];
  }

  map<ll, ii> m = { make_pair(1, ii(n, a[n])) };
  multiset<ll, greater<ll>> s = { a[n] };
  for (ll i = 1, k; i < n; ++i) {
    cin >> k;
    auto it = m.upper_bound(k);
    --it;
    ll l = it->st, r = it->nd.st;
    ll sum = it->nd.nd;
    assert(l <= k && k <= r);
    db(k, l, r, sum);
    s.erase(s.find(sum));
    if (k < r) {
      s.insert(a[r] - a[k]);
      m[k + 1] = ii(r, a[r] - a[k]);
    }
    if (l < k) {
      s.insert(a[k - 1] - a[l - 1]);
      m[l] = ii(k - 1, a[k - 1] - a[l - 1]);
    }
    cout << *s.begin() << endl;
  }
  cout << 0 << endl;

  return 0;
}
