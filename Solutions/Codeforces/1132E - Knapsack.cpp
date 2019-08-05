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
#define maxn "abacate"

typedef long long ll;
typedef double lf;
typedef pair<int, int> ii;

int memo[10][2000];
ll n[10];

int f(int i, int w) {
  if (i == 0) { return 0; }
  int &pd = memo[i][w];
  if (pd != -1) { return pd; }
  for (int k = 0; k <= n[i] && k * i <= w; ++k) {
    pd = max(pd, k * i + f(i - 1, w - k * i));
  }
  return pd;
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  ll w;
  cin >> w;
  for (int i = 1; i <= 8; ++i) { cin >> n[i]; }

  ll sum = 0;
  for (int i = 8; i >= 1; --i) {
    ll k = max(0ll, min(n[i] - 1, (w - 847 + i - 1) / i));
    n[i] -= k;
    w -= k * i;
    sum += k * i;
  }
  ll ans = sum;
  memset(memo, -1, sizeof memo);
  for (int i = 1; i <= 8; ++i) {
    if (n[i] > 0 && i <= w) {
      --n[i];
      assert(w < 2000);
      ans = max(ans, i + sum + f(8, (int)(w - i)));
      debug(i, sum, f(8, (int)(w - i)));
      ++n[i];
    }
  }
  cout << ans << '\n';

  return 0;
}
