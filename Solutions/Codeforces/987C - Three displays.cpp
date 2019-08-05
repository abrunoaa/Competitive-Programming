#include <bits/stdc++.h>
using namespace std;

#define gcd __gcd
#define popcnt __builtin_popcount
#define st first
#define nd second
#define pb push_back
#define eps 1e-9
#define zero(x) (abs(x) < eps)
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 3010

typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
typedef pair<ii, int> tri;
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> Map;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << ' ' << x, db(y...); }

#ifdef LOCAL
__attribute__((destructor))
static void destroy() {
  cerr << "\nTime elapsed: " << (lf)clock() / CLOCKS_PER_SEC << "s.\n";
}

#define db(x...) cerr << " >> [" #x "] = ", db(x)
#else
#warning "JUDGE"
#define db(...) 42
#endif

int n, s[maxn], c[maxn], ft[maxn];
map<int, int> mp;

int getmin(int p) {
  int m = inf;
  for (; p < maxn; p += p & -p) {
    m = min(m, ft[p]);
  }
  return m;
}

void upd(int p, int c) {
  for (; p; p -= p & -p) {
    ft[p] = min(ft[p], c);
  }
}

int main() {
  memset(ft, inf, sizeof ft);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    mp[s[i]] = -1;
  }
  int cnt = 0;
  for (auto &it : mp) {
    if (it.nd == -1) {
      it.nd = ++cnt;
    }
  }
  for (int i = 0; i < n; ++i) {
    db(s[i], mp[s[i]]);
    s[i] = mp[s[i]];
  }
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  int ans = inf;
  for (int j = n - 1; j > 0; --j) {
    upd(s[j], c[j]);
    int k = getmin(s[j] + 1);
    if (k == inf) {
      continue;
    }
    for (int i = 0; i < j; ++i) {
      if (s[i] < s[j]) {
        ans = min(ans, c[i] + c[j] + k);
      }
    }
  }
  cout << (ans == inf ? -1 : ans) << '\n';

  return 0;
}
