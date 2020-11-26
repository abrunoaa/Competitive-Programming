#include <bits/stdc++.h>
using namespace std;

#define maxn 200003

typedef long long ll;

struct Point {
  ll x, y;
  Point(ll x = 0, ll y = 0) : x(x), y(y) {}
  inline ll operator ~ () { return x * x + y * y; }
  inline Point operator + (const Point &p) const { return Point{ x + p.x, y + p.y }; }
  inline Point operator - (const Point &p) const { return Point{ x - p.x, y - p.y }; }
  inline ll operator * (const Point &p) const { return x * p.x + y * p.y; }
};

inline ll cross(const Point &p, const Point &q) { return p.x * q.y - p.y * q.x; }

bool operator < (const Point &p, const Point &q) {
  if (!q.y && q.x >= 0) { return 0; }
  if (!p.y && p.x >= 0) { return 1; }
  if (p.y * q.y < 0) { return p.y > 0; }
  return cross(p, q) > 0;
}

bool sameAngle(const Point &a, const Point &b) {
  return cross(a, b) == 0 && a * b >= 0;
}

int n;
Point vec[2 * maxn];

void pre() {
  sort(vec, vec + n);
  int m = 0;
  for (int i = 1; i < n; ++i) {
    if (sameAngle(vec[m], vec[i])) {
      vec[m] = vec[m] + vec[i];
    } else {
      vec[++m] = vec[i];
    }
  }
  n = m + 1;
  memcpy(vec + n, vec, n * sizeof(*vec));
}

ll solve() {
  ll ans = 0;
  Point cur;
  for (int l = 0, r = 0; l < n; ++l) {
    if (l == r) {
      cur = cur + vec[l];
      ++r;
    }
    for (; ans = max(ans, ~cur), r - l < n && cross(vec[l], vec[r]) > 0; ++r) {
      cur = cur + vec[r];
    }
    cur = cur - vec[l];
  }
  return ans;
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) { cin >> vec[i].x >> vec[i].y; }
  pre();
  cout << solve() << '\n';
  return 0;
}
