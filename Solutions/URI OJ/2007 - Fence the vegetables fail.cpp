#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define maxn 100003

typedef pair<int, int> Point;

struct Plant { int x, y, cost; };
struct Seg { int lo, hi, x; };

int n, m;
vector<int> bit;
vector<Point> poly;
vector<Plant> plant;
vector<Seg> seg;

void upd(int i, int x) {
  for (; i < (int)bit.size(); i += i & -i) {
    bit[i] += x;
  }
}

int qry(int i) {
  int s = 0;
  for (; i; i -= i & -i) {
    s += bit[i];
  }
  return s;
}

void remap() {
  map<int, int> mpx, mpy;
  for (Plant &p : plant) {
    mpx[p.x];
    mpy[p.y];
  }
  for (Point &p : poly) {
    mpx[p.x];
    mpy[p.y];
  }
  int cntx = 0, cnty = 0;
  for (auto &x : mpx) { x.second = ++cntx; }
  for (auto &y : mpy) { y.second = ++cnty; }
  for (Plant &p : plant) {
    p.x = mpx[p.x];
    p.y = mpy[p.y];
  }
  for (Point &p : poly) {
    p.x = mpx[p.x];
    p.y = mpy[p.y];
  }
  bit.resize(cntx + 1);
}

void calcSeg() {
  seg.reserve(n / 2);
  for (int i = 0; i < n; ++i) {
    if (poly[i].x == poly[(i + 1) % n].x) {
      int lo = min(poly[i].y, poly[(i + 1) % n].y);
      int hi = max(poly[i].y, poly[(i + 1) % n].y);
      seg.push_back({ lo, hi, poly[i].x });
    }
  }
  sort(seg.begin(), seg.end(), [](const Seg & a, const Seg & b) { return a.lo < b.lo; });
}

long long calcAns() {
  struct Cmp { bool operator() (const Seg &a, const Seg &b) { return a.hi > b.hi; } };
  priority_queue<Seg, vector<Seg>, Cmp> pq;
  long long ans = 0;
  int i = 0, j = 0, y = 0;
  while (j < m) {
    ++y;
    for (; i < (int)seg.size() && seg[i].lo == y; ++i) {
      upd(seg[i].x, +1);
      pq.push(seg[i]);
    }
    for (; !pq.empty() && pq.top().hi == y; pq.pop()) {
      upd(pq.top().x, -1);
    }
    for (; j < m && plant[j].y == y; ++j) {
      if (qry(plant[j].x) % 2 == 0) {
        ans += plant[j].cost;
      }
    }
  }
  return ans;
}

int main() {
  // assert(freopen("in","r",stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> m >> n;
  plant.resize(m);
  int cost = 0;
  for (Plant &p : plant) {
    cin >> p.x >> p.y;
    p.cost = ++cost;
  }
  sort(plant.begin(), plant.end(), [](const Plant & a, const Plant & b) { return a.y < b.y; });
  poly.resize(n);
  for (Point &p : poly) {
    cin >> p.x >> p.y;
  }
  remap();
  calcSeg();
  cout << calcAns() << '\n';
  return 0;
}
