#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__() { cerr << "\nElapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void debug() {}
template<class t, class... u> void debug(const t &x, const u &...y) { cerr << ' ' << x, debug(y...); }
#define debug(x...) cerr<<"\x1b[91m[" #x "] =",debug(x),cerr<<"\x1b[0m\n"
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

#define null nullptr
#define st first
#define nd second
#define mod 1000000007
#define maxn 5003

typedef long long ll;
typedef double lf;
typedef pair<int, int> ii;

int n, q, tot, a[maxn];
int l[maxn], r[maxn];
int num1[maxn], num2[maxn];

ii qry(int i, int j) {
  return ii(num1[j] - num1[i - 1], num2[j] - num2[i - 1]);
}

int get(int i, int j) {
  if (l[j] < l[i]) { swap(i, j); }
  if (r[i] < l[j]) { return tot - qry(l[i], r[i]).st - qry(l[j], r[j]).st; }
  int a = min(r[i], r[j]), b = max(r[i], r[j]);
  return tot - qry(l[i], l[j] - 1).st - qry(l[j], a).nd - qry(a + 1, b).st;
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> q;
  for (int i = 0; i < q; ++i) {
    cin >> l[i] >> r[i];
    ++a[l[i]];
    --a[r[i] + 1];
  }
  tot = 0;
  num1[0] = num2[0] = 0;
  for (int i = 1; i <= n; ++i) {
    a[i] += a[i - 1];
    num1[i] = num1[i - 1] + (a[i] == 1);
    num2[i] = num2[i - 1] + (a[i] == 2);
    tot += a[i] > 0;
    // debug(a[i]);
  }
  // debug(tot);
  int ans = 0;
  for (int i = 0; i < q; ++i) {
    for (int j = i + 1; j < q; ++j) {
      // debug(i, j, get(i, j));
      ans = max(ans, get(i, j));
    }
  }
  cout << ans << '\n';

  return 0;
}
