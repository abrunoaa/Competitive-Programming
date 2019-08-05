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

#define maxn 10003

int a[maxn];

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, u;
    cin >> n >> u;
    memset(a, 0, sizeof a);
    while (u--) {
      int l, r, val;
      cin >> l >> r >> val;
      a[l] += val;
      a[r + 1] -= val;
    }
    for (int i = 1; i < n; ++i) { a[i] += a[i - 1]; }
    int q;
    cin >> q;
    while (q--) {
      int i;
      cin >> i;
      cout << a[i] << '\n';
    }
  }

  return 0;
}
