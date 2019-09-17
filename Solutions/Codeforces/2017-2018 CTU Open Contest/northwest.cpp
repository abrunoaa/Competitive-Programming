#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef pair<int,int> ii;

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(9);
  int n;
  while (cin >> n) {
    map<ii,int> point;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      ++point[{x, y}];
    }
    long long ans = 0;
    map<int,int> l, r;
    for (auto p : point) {
      ans += l[p.x.x - p.x.y];
      ans += r[p.x.x + p.x.y];
      l[p.x.x - p.x.y] += p.y;
      r[p.x.x + p.x.y] += p.y;
    }
    cout << (double)(2 * ans) / (double)((long long)n * n) << '\n';
  }
  return 0;
}
