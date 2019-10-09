#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)3e5 + 3;
const int maxm = (int)1e5 + 3;
const int inf = 0x3f3f3f3f;

string johny, michelle;
vector<int> cross[maxn], path[maxm];
unordered_map<string,int> stops;
bool processed[maxn];
int ans[maxn];

void read() {
  string str;
  cin >> str;
  int n = 0;
  stops.clear();
  while (1) {
    cin >> str;
    bool done = str.back() != ',';
    if (!done) str.pop_back();
    stops[str] = ++n;
    cross[n].clear();
    if (done) break;
  }
  int m = 0;
  cin >> str;
  while (1) {
    ++m;
    cin >> str;
    if (str.back() != ',') break;
  }
  for (int p = 1; p <= m; ++p) {
    path[p].clear();
    cin >> str >> str;
    while (1) {
      cin >> str;
      bool done = str.back() != ',';
      if (!done) str.pop_back();
      int v = stops[str];
      path[p].push_back(v);
      cross[v].push_back(p);
      if (done) break;
    }
  }
  cin >> str >> str >> str >> johny;
  cin >> str >> str >> str >> michelle;
}

pair<int,int> bfs(int s, int t) {
  memset(processed, 0, sizeof(processed));
  memset(ans, -63, sizeof(ans));
  ans[s] = 0;
  vector<int> q;
  q = {s};
  int dis = 0;
  while (!q.empty()) {
    vector<int> routes;
    for (int v : q) {
      for (int x : cross[v]) {
        if (!processed[x]) {
          processed[x] = true;
          routes.push_back(x);
        }
      }
    }
    q.clear();
    map<int,int> change;
    for (int r : routes) {
      for (int go = 0; go < 2; ++go) {
        int d = -inf;
        for (int p : path[r]) {
          d = max(d + 1, ans[p]);
          change[p] = max(change[p], d);
        }
        reverse(path[r].begin(), path[r].end());
      }
    }
    for (auto &pp : change) {
      int v, d;
      tie(v, d) = pp;
      if (ans[v] < 0) {
        ans[v] = d;
        q.push_back(v);
        if (v == t) {
          return {dis, ans[t]};
        }
      }
    }
    ++dis;
  }
  assert(0);
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    read();
    int changes, time;
    tie(changes, time) = bfs(stops[johny], stops[michelle]);
    printf("optimal travel from %s to %s: %d line%s, %d minute%s\n", johny.data(), michelle.data(), changes + 1, (changes == 0 ? "" : "s"), time, (time == 1 ? "" : "s"));
  }
  return 0;
}
