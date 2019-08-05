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
#define maxn 10003
#define inf 0x3f3f3f3f

typedef long long ll;
typedef double lf;
typedef pair<int, int> ii;

int n, m, k, dis[maxn], x[maxn], y[maxn];

int dijkstra(int s, int t, bool lit) {
  memset(dis, inf, sizeof dis);
  dis[s] = 0;
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.push({0, s});
  while (!pq.empty()) {
    int u = pq.top().nd;
    int d = pq.top().st;
    pq.pop();
    debug(u, d);
    if (u == t) {
      return d;
    }
    if (d == dis[u]) {
      for (int v = 0; v < k; ++v) {
        int cost = inf;
        if (x[v] == n && y[v] == m && !lit) {
          if (abs(x[u] - x[v]) <= 1 || abs(y[u] - y[v]) <= 1) {
            cost = 1;
          }
        } else if (abs(x[u] - x[v]) + abs(y[u] - y[v]) == 1) {
          cost = 0;
        } else if (abs(x[u] - x[v]) <= 2 || abs(y[u] - y[v]) <= 2) {
          cost = 1;
        }
        if (d + cost < dis[v]) {
          dis[v] = d + cost;
          pq.push({dis[v], v});
        }
      }
    }
  }

  return -1;
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> m >> k;

  int start = -1, end = k;
  for (int i = 0; i < k; ++i) {
    cin >> x[i] >> y[i];
    if (x[i] == 1 && y[i] == 1) {
      start = i;
    } else if (x[i] == n && y[i] == m) {
      end = i;
    }
  }

  bool lit = end < k;
  if (!lit) {
    x[k] = n;
    y[k] = m;
    ++k;
  }

  cout << dijkstra(start, end, lit) << '\n';

  return 0;
}
