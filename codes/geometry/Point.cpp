#include <bits/stdc++.h>
using namespace std;

typedef long double lf;
const lf eps = 1e-12;
inline int cmp(lf x, lf y = 0) { return (abs(x - y) < eps ? 0 : x < y ? -1 : 1); }

struct pt {
  lf x, y;
  pt(lf _x = 0.0, lf _y = 0.0) : x(_x), y(_y) {}

  lf dist(pt p) { return hypotl(x - p.x, y - p.y); }

  bool operator==(pt p) const { return !cmp(x, p.x) && !cmp(y, p.y); }
  bool operator<(pt p) const { return cmp(x, p.x) ? cmp(x, p.x) < 0 : cmp(y, p.y) < 0; }

  // ccw rotation
  pt rotate(lf r) { return pt(x * cosl(r) - y * sinl(r), x * sinl(r) + y * cosl(r)); }
};

pt operator*(lf s, const pt& a)        { return pt{a.x * s, a.y * s}; }
pt operator*(const pt& a, lf s)        { return pt{a.x * s, a.y * s}; }
pt operator+(const pt& a, const pt& b) { return pt{a.x + b.x, a.y + b.y}; }
pt operator-(const pt& a, const pt& b) { return pt{a.x - b.x, a.y - b.y}; }
lf operator~(const pt& a)              { return a.x * a.x + a.y * a.y; }
lf operator*(const pt& a, const pt& b) { return a.x * b.x + a.y * b.y; }
lf operator^(const pt& a, const pt& b) { return a.x * b.y - a.y * b.x; }

// ccw comparison
bool cmp_ccw_slow(pt p, pt q) { return atan2l(p.y, p.x) < atan2l(q.y, q.x); }

bool cmp_ccw(pt p, pt q) {
  if (!cmp(p.y) && p.x <= 0) return 0;
  if (!cmp(q.y) && q.x <= 0) return 1;
  if (cmp(p.y) * cmp(q.y) < 0) return cmp(p.y) < 0;
  return (p ^ q) > 0;
}

// closest point of a -> b from p
pt closest(pt a, pt b, pt p) {
  pt ab = b - a, ap = p - a;
  return a + ab * (ab * ap / ~ab);
}

// closest point of segment a -> b from p
pt closestSegm(pt a, pt b, pt p) {
  pt ab = b - a, ap = p - a;
  lf u = ab * ap / ~ab;
  return (u < 0.0 ? a : u > 1.0 ? b : a + ab * u);
}

lf angle_slow(pt a, pt b) {             // more precision
  lf u = fmodl(abs(atan2l(a.y, a.x) - atan2l(b.y, b.x)), 2 * acosl(-1));
  return min(u, 2 * acosl(-1) - u);     // closest: cw or ccw?
}

lf angle(const pt& a, const pt& b) { return acosl(a * b / sqrtl(~a * ~b)); }
bool ccw(const pt& a, const pt& b) { return cmp(a ^ b) > 0; }
bool col(const pt& a, const pt& b) { return cmp(a ^ b) == 0; }  // collinear

int intersect(pt p, pt r, pt q, pt s, pt &r1, pt &r2) { // integer points
  pt pq = q - p;
  pt pr = r - p;
  pt qs = s - q;
  ll c1 = pr ^ qs;
  ll c2 = pq ^ pr;
  ll c3 = pq ^ qs;
  if (!cmp(c1)) {
    if (cmp(c2)) return 0;              // parallel
    lf t0 = pq * pr / (pr * pr);        // collinear
    lf t1 = t0 + qs * pr / (pr * pr);
    if (cmp(t0, t1) > 0) swap(t0, t1);
    if (cmp(t1, 0) < 0 || cmp(1, t0) < 0) return 0;
    r1 = p + max((lf)0, t0) * pr;
    r2 = p + min((lf)1, t1) * pr;
    return cmp(t0, t1) == 0 ? 1 : 2;
  }
  lf t = c3 / c1;
  lf u = c2 / c1;
  r1 = r2 = p + t * pr;
  return cmp(0, t) <= 0 && cmp(t, 1) <= 0 && cmp(0, u) <= 0 && cmp(u, 1) <= 0;
}

int intersect(pt p, pt r, pt q, pt s, pt &r1, pt &r2) {
  pt pq = q - p;
  pt pr = r - p;
  pt qs = s - q;
  lf c1 = pr ^ qs;
  lf c2 = pq ^ pr;
  lf c3 = pq ^ qs;
  if (!cmp(c1)) {
    if (cmp(c2)) return 0;              // parallel
    lf t0 = pq * pr / (pr * pr);    // collinear
    lf t1 = t0 + qs * pr / (pr * pr);
    if (cmp(t0, t1) > 0) swap(t0, t1);
    if (cmp(t1, 0) < 0 || cmp(1, t0) < 0) return 0;
    r1 = p + max((lf)0, t0) * pr;
    r2 = p + min((lf)1, t1) * pr;
    return cmp(t0, t1) == 0 ? 1 : 2;
  }
  lf t = c3 / c1;
  lf u = c2 / c1;
  r1 = r2 = p + t * pr;
  return cmp(0, t) <= 0 && cmp(t, 1) <= 0 && cmp(0, u) <= 0 && cmp(u, 1) <= 0;
}

int main() {
  typedef double tp;

  cerr << fixed << setprecision(30);
  tp step = 1;
  tp n = 30 * step;
  for (tp x = -n; x <= n; x += step) {
    for (tp y = -n; y <= n; y += step) {
      if (cmp(x) || cmp(y)) {
        for (tp u = -n; u <= n; u += step) {
          for (tp v = -n; v <= n; v += step) {
            if (cmp(u) || cmp(v)) {
              pt p(x, y);
              pt q(u, v);
              // cerr << " -- " << x << ' ' << y << ' ' << u << ' ' << v << endl;
              // cerr << " >> " << angle(p, q) << '\n';
              // cerr << " ## " << angle_slow(p, q) << '\n';
              // assert(cmp(angle(p, q), angle_slow(p, q)) == 0);

              assert(cmp_ccw(p, q) == cmp_ccw_slow(p, q));
            }
          }
        }
      }
    }
  }
  return 0;
}
