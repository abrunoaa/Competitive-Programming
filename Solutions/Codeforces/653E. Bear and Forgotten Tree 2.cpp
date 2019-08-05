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

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  int limit = n - 1;
  set<ii> forbidden;
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (u == 1 || v == 1) {
      --limit;
    }
    forbidden.insert({u, v});
    forbidden.insert({v, u});
  }
  if (k > limit) {
    cout << "impossible\n";
    return 0;
  }

  set<int> unvis;
  for (int u = 2; u <= n; ++u) {
    unvis.insert(u);
  }

  int need = 0;
  for (int u = 2; u <= n; ++u) {
    if (unvis.count(u) && !forbidden.count({1, u})) {
      ++need;
      if (need > k) {
        cout << "impossible\n";
        return 0;
      }

      queue<int> q;
      q.push(u);
      while (!q.empty()) {
        int u = q.front();
        q.pop();

        vector<int> vis;
        for (int v : unvis) {
          if (!forbidden.count({u, v})) {
            vis.push_back(v);
            q.push(v);
          }
        }
        for (int v : vis) {
          unvis.erase(v);
        }
      }
    }
  }

  cout << (unvis.empty() ? "possible" : "impossible") << '\n';
  return 0;
}
