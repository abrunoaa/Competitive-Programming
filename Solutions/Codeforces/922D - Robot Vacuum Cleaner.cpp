#include <bits/stdc++.h>
using namespace std;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << " " << x, db(y...); }

#define db(x...) cerr << " >>", db(x)
#define gcd(x,y) __gcd(x,y)
#define st first
#define nd second
#define eps 1e-9
#define zero(x) (fabs(x) < eps)
#define inf 0x3f3f3f3f
#define mod 1000000007
#define maxn 100010

typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
typedef pair<int, ii> tri;
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> Map;

int n;
ll ans = 0;
ii v[maxn];
string t;

// bool cmp(ii f, ii s) { return f.nd / f.st < s.nd / s.st; }
bool cmp(ii f, ii s) { return 1LL * f.nd * s.st < 1LL * f.st * s.nd; }

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t;

    int k = 0;
    for (char c : t)
      if (c == 'h') {
        ans += k;
      } else {
        ++k;
      }

    v[i] = ii(k, t.size() - k);
  }

  sort(v, v + n, cmp);

  ll k = v[0].st;
  for (int i = 1; i < n; ++i) {
    ans += v[i].nd * k;
    k += v[i].st;
  }

  cout << ans << '\n';

  return 0;
}
