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
#define maxn 2010

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

int n, t, cs = 0;
deque<int> temp, a, d;

int check(bool f) {
  while (!d.empty()) {
    if (f) {
      temp.pb(d.back());
      d.pop_back();
      if (d.empty()) { break; }
      temp.push_front(d.back());
      d.pop_back();
    } else {
      temp.pb(d.front());
      d.pop_front();
      if (d.empty()) { break; }
      temp.push_front(d.front());
      d.pop_front();
    }
    f ^= 1;
  }

  // cerr << " >> "; for(int x : temp) cerr << x << ' '; cerr << endl;

  int ans = 0;
  for (int i = 1; i < (int)temp.size(); ++i) {
    ans += abs(temp[i] - temp[i - 1]);
  }

  return ans;
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    a.resize(n);
    for (int &x : a) { cin >> x; }

    sort(a.begin(), a.end());
    d = a;
    temp.clear();
    temp.pb(d[0]);
    d.pop_front();
    int ans = check(1);

    db(ans);

    d = a;
    temp.clear();
    temp.pb(d.back());
    d.pop_back();
    ans = max(ans, check(0));

    db(ans);

    cout << "Case " << ++cs << ": " << ans << '\n';
  }

  return 0;
}
