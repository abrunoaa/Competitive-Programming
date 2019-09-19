#include <bits/stdc++.h>
using namespace std;

const int maxf = 3630000;

int vis[maxf], dis[maxf];
vector<int> g[maxf];
map<string,int> mp;

string rev(string s, int l, int r) {
  for (int k = 0; k < ((r - l + 1) >> 1); ++k) {
    swap(s[l + k], s[r - k]);
  }
  return s;
}

void build() {
  string s = "abcdefghij";
  int m = 0;
  do {
    mp[s] = ++m;
  } while (next_permutation(s.begin(), s.end()));
  do {
    int u = mp[s];
    for (int i = 0; i < 9; ++i) {
      for (int j = i + 1; j < 10; ++j) {
        g[u].push_back(mp[rev(s, i, j)]);
      }
    }
  } while (next_permutation(s.begin(), s.end()));
}

int bfs(int s, int t) {
  if (s == t) return 0;
  memset(dis, -1, sizeof(dis));
  dis[s] = 0;
  dis[t] = 0;
  vis[s] = 1;
  vis[t] = 2;
  queue<int> q;
  q.push(s);
  q.push(t);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (dis[v] == -1) {
        dis[v] = dis[u] + 1;
        vis[v] = vis[u];
        q.push(v);
      } else if (vis[v] != vis[u]) {
        return dis[u] + 1 + dis[v];
      }
    }
  }
  assert(0);
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  build();
  string a, b;
  while (cin >> a >> b, a[0] != '*') {
    cout << bfs(mp[a], mp[b]) << '\n';
  }
  return 0;
}
