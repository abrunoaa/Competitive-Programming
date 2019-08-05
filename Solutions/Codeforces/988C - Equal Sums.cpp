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

int v[maxn];
map<int, ii> mp;

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int k;
  cin >> k;
  for (int i = 1; i <= k; ++i) {
    int n;
    cin >> n;
    int s = 0;
    for (int j = 1; j <= n; ++j) {
      cin >> v[j];
      s += v[j];
    }
    for (int j = 1; j <= n; ++j) {
      int s2 = s - v[j];
      if (i != mp[s2].st && mp[s2].st) {
        cout << "YES\n";
        cout << i << ' ' << j << endl;
        cout << mp[s2].st << ' ' << mp[s2].nd << endl;
        return 0;
      }
      mp[s2] = ii(i, j);
    }
  }
  cout << "NO\n";

  return 0;
}
