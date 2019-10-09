#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int inf = (int)2e9 + 3;
const int maxn = 1003;
const int maxm = 30003;

int timer, ans = inf, rem_a, rem_b;
int w[maxm];
int tin[maxn], low[maxn];
bool vis[maxn], isBridge[maxm];
ii parent[maxn];
vector<ii> g[maxn];

void updateAns(int i, int j = 0) {
  int x = w[i] + w[j];
  if (x < ans) {
    ans = x;
    rem_a = i;
    rem_b = j;
  }
}

void dfs(int blocked, int u, int p = -1) {
  tin[u] = low[u] = ++timer;
  for (auto [v, i] : g[u]) {
    if (i == p || i == blocked) continue;
    if (tin[v] != -1) {
      low[u] = min(low[u], tin[v]);
    } else {
      dfs(blocked, v, i);
      low[u] = min(low[u], low[v]);
      if (low[v] > tin[u]) {
        isBridge[i] = 1;
      }
    }
  }
}

void findBridges(int blocked, int s) {
  timer = 0;
  memset(isBridge, 0, sizeof(isBridge));
  memset(tin, -1, sizeof(tin));
  dfs(blocked, s);
}

void bfs(int blocked, int s) {
  memset(vis, 0, sizeof(vis));
  vis[s] = 1;
  parent[s] = {0, 0};
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto [v, idx] : g[u]) {
      if (!vis[v] && idx != blocked) {
        vis[v] = 1;
        parent[v] = {u, idx};
        q.push(v);
      }
    }
  }
}

auto rec(int t) {
  vector<int> path;
  int p = t, idx;
  while (tie(p, idx) = parent[p], p) {
    path.emplace_back(idx);
  }
  return path;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y >> w[i];
    g[x].emplace_back(y, i);
    g[y].emplace_back(x, i);
  }
  bfs(0, s);
  if (parent[t].first == 0) {
    cout << "0\n0\n\n";
    return 0;
  }
  for (auto i : rec(t)) {
    findBridges(i, s);
    if (tin[t] == -1) {
      updateAns(i);
      continue;
    }
    bfs(i, s);
    for (auto j : rec(t)) {
      if (isBridge[j]) {
        updateAns(i, j);
      }
    }
  }
  if (ans == inf) {
    cout << "-1\n";
    return 0;
  }
  cout << ans << '\n';
  cout << 1 + (rem_b != 0) << '\n';
  cout << rem_a;
  if (rem_b) {
    cout << ' ' << rem_b;
  }
  cout << '\n';
  return 0;
}
