#include <bits/stdc++.h>
using namespace std;

#define maxn 510

unordered_set<int> is[maxn], has[maxn];
bool vis_is[maxn], vis_has[maxn];

bool is_a(int a, int b) {
  if (vis_is[a]) {
    return 0;
  }
  if (is[a].count(b)) {
    return 1;
  }
  vis_is[a] = 1;
  for (int x : is[a]) {
    if (is_a(x, b)) {
      return 1;
    }
  }
  return 0;
}

bool has_a(int a, int b) {
  if (vis_has[a]) {
    return 0;
  }
  if (has[a].count(b)) {
    return 1;
  }
  vis_has[a] = 1;
  for (int x : is[a]) {
    if (has_a(x, b)) {
      return 1;
    }
  }
  for (int x : has[a]) {
    if (has_a(x, b) || is_a(x, b)) {
      return 1;
    }
  }
  return 0;
}

int main() {
  // freopen("ein","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  cout << boolalpha;

  int n, m;
  while (cin >> n >> m) {
    map<string, int> id;
    for (auto &i : is) { i.clear(); }
    for (auto &h : has) { h.clear(); }

    int cnt = 1;
    for (int i = 0; i < n; ++i) {
      string c1, c2, r;

      cin >> c1 >> r >> c2;
      int &a = id[c1], &b = id[c2];
      if (!a) { a = cnt++; }
      if (!b) { b = cnt++; }

      if (r == "is-a") {
        is[a].insert(b);
      } else {
        has[a].insert(b);
      }
    }
    for (int q = 1; q <= m; ++q) {
      string c1, c2, r;

      cin >> c1 >> r >> c2;
      int a = id[c1], b = id[c2];

      memset(vis_is, 0, cnt);
      memset(vis_has, 0, cnt);
      cout << "Query " << q << ": " << (r == "is-a" ? a == b || is_a(a, b) : has_a(a, b)) << '\n';
    }
  }

  return 0;
}
