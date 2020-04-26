#include <bits/stdc++.h>
using namespace std;

struct pt { // using integers
  int x, y, id;
  double dist(const pt& p) const { return hypot(x - p.x, y - p.y); }
  bool operator==(const pt& p) const { return x == p.x && y == p.y; }
  bool operator<(const pt& p) const { return y != p.y ? y < p.y : x != p.x ? x < p.x : id < p.id; }
};

// area2 > 0 => cb is ccw wrt ca; = 0 => collinear; < 0 => cw
// 2 * triangle area = (a-c)x(b-c) = axb + bxc + cxa
int area2(pt &c, pt &a, pt &b) {
  return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}

void monotoneChain(vector<pt> &p) {     // returns p[0] != p[n]
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  if (p.size() <= 2) return;
  vector<pt> up, dn;
  for (int i = 0; i < (int)p.size(); ++i) {
    while (up.size() > 1 && area2(p[i], up[up.size() - 2], up.back()) >= 0) up.pop_back();
    while (dn.size() > 1 && area2(p[i], dn[dn.size() - 2], dn.back()) <= 0) dn.pop_back();
    up.push_back(p[i]);
    dn.push_back(p[i]);
  }
  p = dn;
  p.insert(p.end(), up.rbegin() + 1, up.rend() - 1);
}

double area(const vector<pt> &p) {
  double ans = 0.0;
  for (int i = 0; i < (int)p.size() - 1; ++i) ans += p[i].dist(p[i + 1]);
  return ans;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(2);
  int t;
  cin >> t;
  vector<pt> p(100001);
  while (t--) {
    int n;
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i].x >> p[i].y;
      p[i].id = i + 1;
    }
    monotoneChain(p);
    p.push_back(p[0]);
    cout << area(p) << '\n';
    p.pop_back();
    bool printted = 0;
    for (auto a : p) {
      if (printted) cout << ' ';
      printted = 1;
      cout << a.id;
    }
    cout << '\n';
    if (t) cout << '\n';
  }
  return 0;
}
