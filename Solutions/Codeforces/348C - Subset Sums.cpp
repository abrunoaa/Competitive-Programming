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
#define zero(x) (abs(x) < eps)
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

#ifndef ONLINE_JUDGE
struct _ { _() { assert(freopen("in", "r", stdin)); } } _;
#define db(x...) cerr << " >>", db(x)
#else
#warning "ONLINE_JUDGE"
struct _ { _() { cin.sync_with_stdio(0), cin.tie(0); } } _;
#define db(x...)
#endif

const int maxrt = sqrt(maxn) + 1;

struct {
  ll ans, att;
  int intersect[maxn];
  bool has[maxn];
} big[maxrt];

int n, m, q, nbig, rt, bigpos[maxn];
ll a[maxn];
vi s[maxn];

ll qry(int k) {
  int b = bigpos[k];
  ll ans = 0;
  if (b == -1) {
    for (int i : s[k]) {
      ans += a[i];
    }
  } else {
    ans = big[b].ans;
  }
  for (int i = 0; i < nbig; ++i) {
    ans += (ll)big[i].att * big[i].intersect[k];
  }
  return ans;
}

void upd(int k, int x) {
  int b = bigpos[k];
  if (b == -1) {
    for (int i : s[k]) {
      a[i] += x;
    }
    for (int i = 0; i < nbig; ++i) {
      big[i].ans += (ll)x * big[i].intersect[k];
    }
  } else {
    big[b].att += x;
  }
}

int main() {
  cin >> n >> m >> q;
  rt = sqrt(n);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1, k; i <= m; ++i) {
    cin >> k;
    s[i].resize(k);
    for (int j = 0; j < k; ++j) {
      cin >> s[i][j];
    }
    sort(s[i].begin(), s[i].end());
    if (k > rt) {
      int b = bigpos[i] = nbig++;
      for (int x : s[i]) {
        big[b].has[x] = 1;
        big[b].ans += a[x];
      }
    } else {
      bigpos[i] = -1;
    }
  }
  for (int i = 1; i <= m; ++i)
    if (!s[i].empty())
      for (int j = 0; j < nbig; ++j)
        for (int x : s[i]) {
          big[j].intersect[i] += big[j].has[x];
        }
  for (int i = 0; i < q; ++i) {
    char op;
    int k, x;
    cin >> op;
    if (op == '?') {
      cin >> k;
      cout << qry(k) << '\n';
    } else {
      cin >> k >> x;
      upd(k, x);
    }
  }
  return 0;
}
