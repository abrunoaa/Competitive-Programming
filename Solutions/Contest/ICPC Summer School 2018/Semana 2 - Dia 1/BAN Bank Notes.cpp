#include <iostream>
#include <deque>
#include <algorithm>
#include <cassert>
using namespace std;

#define maxn 203
#define maxm 20003
#define inf 0x3f3f3f3f
#define st first
#define nd second

template<class T>
struct MinQueue {
  int n;
  T lazy;
  deque<pair<T, int>> q;

  MinQueue() : n(0), lazy(0), q() {}

  int size() { return n; }
  void clear() { n = 0; lazy = 0; q.clear(); }
  void pop() { --n; if (!--q.front().nd) q.pop_front(); }
  void add(T x) { lazy += x; }
  void push(T x) {
    ++n;
    x -= lazy;
    int k = 0;
    for (; !q.empty() && q.back().st >= x; q.pop_back()) { k += q.back().nd; }
    q.push_back({x, k + 1});
  }
  T front() { return q.front().st + lazy; }
};

int n, m, v[maxn], b[maxn];
MinQueue<int> q[maxm];
int memo[maxn][maxm];

void rec(int i, int j) {
  if (!i) { return; }
  int v = ::v[i];
  for (int k = 0; ; ++k)
    if (memo[i][j] == memo[i - 1][j - k * v] + k) {
      rec(i - 1, j - k * v);
      if (i > 1) { cout << ' '; }
      cout << k;
      return;
    }
}

int boundedKnapsack() {
  memo[0][0] = 0;
  for (int j = 1; j <= m; ++j) { memo[0][j] = inf; }
  for (int i = 1; i <= n; ++i) {
    int v = ::v[i], b = ::b[i]; // w = v
    for (int j = 0; j <= m; ++j) {
      auto &p = q[j % v];
      if (j < v) { p.clear(); }
      else if (p.size() > b) { p.pop(); }
      p.add(1);
      p.push(memo[i - 1][j]);
      memo[i][j] = p.front();
    }
  }
  return memo[n][m];
}

int main() {
  // freopen("in","r",stdin);
  // freopen("out","w",stdout);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) { cin >> ::v[i]; }
  for (int i = 1; i <= n; ++i) { cin >> ::b[i]; }
  cin >> m;

  int ans = boundedKnapsack();
  if (ans == inf) { cout << "-1\n"; }
  else {
    cout << ans << '\n';
    rec(n, m);
    cout << '\n';
  }

  return 0;
}
