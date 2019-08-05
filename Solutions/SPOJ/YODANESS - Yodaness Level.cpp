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
#define maxn 30010

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

int ft[maxn];

void upd(int i, int x) {
  for (; i < maxn; i += i & -i) {
    ft[i] += x;
  }
}

int qry(int i) {
  int s = 0;
  for (; i; i -= i & -i) {
    s += ft[i];
  }
  return s;
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    memset(ft, 0, sizeof ft);

    int n;
    cin >> n;

    string s;
    map<string, int> mp;
    for (int i = 1; i <= n; ++i) {
      cin >> s;
      mp[s] = i;
      upd(i, +1);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> s;
      int k = mp[s];
      ans += qry(k) - i;
      upd(1, +1);
      upd(k, -1);
    }

    cout << ans << endl;
  }

  return 0;
}
