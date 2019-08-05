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

#define maxn 2003

int n, m, cnt, num[maxn], low[maxn];
vector<int> g[maxn];

void tarjan(int u) {
  num[u] = low[u] = ++cnt;
  for (int v : g[u]) {
    if (!num[v]) { tarjan(v); }
    low[u] = min(low[u], low[v]);
  }
  if (num[u] == low[u]) { throw u; }
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  while (cin >> n >> m && (n || m)) {
    cnt = 0;
    for (int u = 1; u <= n; ++u) {
      num[u] = 0;
      g[u].clear();
    }
    while (m--) {
      int v, w, p;
      cin >> v >> w >> p;
      g[v].push_back(w);
      if (p == 2) { g[w].push_back(v); }
    }
    try { tarjan(1); }
    catch (int ans) {
      if (ans == 1) {
        for (int u = 1; u <= n; ++u) {
          if (!num[u]) {
            ans = 0;
            break;
          }
        }
      }
      cout << (ans == 1) << '\n';
    }
  }

  return 0;
}
