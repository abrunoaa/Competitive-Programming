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
#define maxn 1000010

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

#ifndef ONLINE_JUDGE
__attribute__((destructor)) static void destroy()
{ cerr << "\nTime elapsed: " << (lf)clock() / CLOCKS_PER_SEC << "s.\n"; }

#define db(x...) cerr << " >> [" #x "] =", db(x)
#else
#warning "JUDGE"
#define NDEBUG
#define db(...) 42
#endif

int n, a[maxn], ftl[maxn], ftg[maxn];

void addl(int i, int x) {
  for (; i < maxn; i += i & -i) {
    ftl[i] += x;
  }
}

int suml(int i) {
  int s = 0;
  for (; i; i -= i & -i) {
    s += ftl[i];
  }
  return s;
}

void addg(int i, int x) {
  for (; i; i -= i & -i) {
    ftg[i] += x;
  }
}

int sumg(int i) {
  int s = 0;
  for (; i < maxn; i += i & -i) {
    s += ftg[i];
  }
  return s;
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  map<int, int> mp;

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mp[a[i]] = i;
  }

  int cnt = 0;
  for (auto i : mp) {
    a[i.nd] = ++cnt;
    addl(cnt + 1, +1);
  }

  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += (ll)sumg(a[i]) * suml(a[i]);
    addl(a[i] + 1, -1);
    addg(a[i] - 1, +1);
  }

  cout << ans << endl;

  return 0;
}
