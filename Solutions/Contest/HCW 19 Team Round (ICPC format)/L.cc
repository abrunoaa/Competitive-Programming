#include <bits/stdc++.h>
using namespace std;

#define int long long
#define u second
#define d first

typedef pair<int,int> ii;

const int maxn = (int)1e5 + 3;
const int inf = 0x3f3f3f3f3f3f3f3f;

int n, L, R, C;
int x, y;
int a[maxn];
int dis[maxn];
vector<int> g[maxn];

void remap() {
  map<int,int> mp;
  for (int i = 1; i <= n; ++i) {
    mp[a[i]];
  }
  int m = 0;
  for (auto &t : mp) {
    t.second = ++m;
  }
  for (int i = 1; i <= n; ++i) {
    a[i] = mp[a[i]];
    g[a[i]].push_back(i);
  }
}

void check(auto &pq, int u, int d) {
  if (1 <= u && u <= n && d < dis[u]) {
    // cerr << " -- new " << u << " == " << d << ' ' << dis[u] << endl;
    dis[u] = d;
    pq.push({dis[u], u});
  }
}

signed main() {
  // assert(freopen("lin", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> n >> L >> R >> C;
  cin >> x >> y;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  remap();
  memset(dis, 63, sizeof(dis));
  dis[x] = 0;
  priority_queue<ii,vector<ii>,greater<ii>> pq;
  pq.push({dis[x], x});
  while (!pq.empty()) {
    ii s = pq.top();
    pq.pop();
    int u = s.u;
    int d = s.d;
    // assert(1 <= u && u <= n);
    // cerr << " §§ " << u << ' ' << d << endl;
    for (int v : g[a[u]]) {
      if (d + C < dis[v]) {
        // cerr << " $$ " << u << " -> " << v << " == " << d + C << endl;
        dis[v] = d + C;
        pq.push({dis[v], v});
      }
    }
    g[a[u]].clear();
    // if (u == y) {
      // break;
    // }
    if (d > dis[u]) {
      continue;
    }
    // cerr << " >> " << u << ' ' << d << endl;
    check(pq, u - 1, d + L);
    check(pq, u + 1, d + R);
  }
  cout << dis[y] << '\n';
  return 0;
}
