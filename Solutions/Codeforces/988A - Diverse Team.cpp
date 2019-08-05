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
typedef pair<int, int> ii;
typedef pair<ii, int> tri;
typedef pair<ii, ii> qua;
typedef vector<int> vi;
typedef vector<ii> vii;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> Map;

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

int n, k, a[110], f[110];
vi cand;

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (++f[a[i]] == 1) {
      cand.pb(i + 1);
    }
  }
  if ((int)cand.size() < k) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < k; ++i) {
      if (i) { cout << ' '; }
      cout << cand[i];
    }
    cout << endl;
  }

  return 0;
}
