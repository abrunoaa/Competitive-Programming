#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int> ii;
typedef set<ii,greater<ii>> Set;

struct Edge {
  int u, v, w, p;
};

const int maxn = (int)2e5 + 3;
const int inf = 0x3f3f3f3f3f3f3f3f;

int n;
Edge edge[maxn];
vector<int> g[maxn];
int minp[maxn];

int calc(int u, int i) {
  int s = 0;
  for (int id : g[u]) {
    auto [ign1, v, w, p] = edge[id];
    s += calc(v, id);
    s += w - (p - minp[id]);
  }
  minp[i] = max(s, edge[i].p - (edge[i].w - 1));
  return s;
}

inline void merge(auto &a, auto &b) {
  if (a.size() < b.size()) swap(a, b);
  a.insert(b.begin(), b.end());
}

pair<Set,int> dfs(int u, int str, int d) {
  int t = 0;
  Set e;
  for (int id : g[u]) {
    auto [ign1, v, w, p] = edge[id];
    auto [ev, tv] = dfs(v, p, d + 1);
    ev.emplace(d, id);
    merge(e, ev);
    t += tv + w;
  }
  while (t > str) {
    if (e.empty()) {
      throw (int)0;
    }
    int id = (*e.begin()).second;
    auto &[ign1, ign2, w, p] = edge[id];
    int get = min(t - str, p - minp[id]);
    t -= get;
    w -= get;
    p -= get;
    if (p == minp[id]) {
      e.erase(e.begin());
    }
  }
  return {move(e), t};
}

signed main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    auto &[u, v, w, p] = edge[i];
    cin >> u >> v >> w >> p;
    g[u].push_back(i);
  }
  try {
    calc(1, 0);
    dfs(1, inf, 1);
    cout << n << '\n';
    for (int i = 1; i < n; ++i) {
      auto [u, v, w, p] = edge[i];
      cout << u << ' ' << v << ' ' << w << ' ' << p << '\n';
    }
  } catch(int) {
    cout << "-1\n";
  }
  return 0;
}
