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
#define maxn 1003
#define inf 0x3f3f3f3f

typedef long long ll;
typedef double lf;
typedef pair<int, int> ii;

int dis[maxn];
vector<int> g[maxn];

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, m;
nextCase:
  while (cin >> n >> m && (n || m)) {
    for (int u = 1; u <= n; ++u) {
      g[u].clear();
    }
    while (m--) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    int a = 0, b = 0;
    for (int u = 1; u <= n; ++u) {
      if (g[u].size() % 2) {
        if (!a) {
          a = u;
        } else {
          b = u;
          break;
        }
      }
    }

    for (int u = 1; u <= n; ++u) {
      if (g[u].size() < 2) {
        cout << "Poor Koorosh\n";
        goto nextCase;
      }
    }
    if (a == 0) {
      cout << "0\n";
    } else if (b == 0 || g[a].size() <= 2 || g[b].size() <= 2) {
      cout << "Poor Koorosh\n";
    } else {
      memset(dis, inf, sizeof dis);
      dis[a] = 0;
      queue<int> q;
      q.push(a);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
          if (dis[v] == inf && g[v].size() > 2) {
            dis[v] = dis[u] + 1;
            q.push(v);
          }
        }
      }

      if (dis[b] == inf) {
        cout << "Poor Koorosh\n";
      } else {
        cout << dis[b] << '\n';
      }
    }
  }

  return 0;
}
