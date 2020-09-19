#include <bits/stdc++.h>
using namespace std;

typedef long double lf;
const lf eps = 1e-12;
inline int cmp(lf x, lf y = 0) { return (abs(x - y) < eps ? 0 : x < y ? -1 : 1); }

struct pt {
  lf x, y;
  pt(lf _x = 0.0, lf _y = 0.0) : x(_x), y(_y) {}

  lf dist(pt p) { return hypotl(x - p.x, y - p.y); }

  bool operator == (pt p) const { return !cmp(x, p.x) && !cmp(y, p.y); }
  bool operator < (pt p) const { return cmp(x, p.x) ? cmp(x, p.x) < 0 : cmp(y, p.y) < 0; }

  // ccw rotation
  pt rotate(lf r) { return pt(x * cosl(r) - y * sinl(r), x * sinl(r) + y * cosl(r)); }

  pt operator * (lf s) { return pt(x * s, y * s); }
  pt operator / (lf s) { return pt(x / s, y / s); }

  pt operator + (pt p) { return pt(x + p.x, y + p.y); }
  pt operator - (pt p) { return pt(x - p.x, y - p.y); }
  lf operator * (pt v) { return x * v.x + y * v.y; }    // scalar product
  lf operator ^ (pt v) { return x * v.y - y * v.x; }    // cross product
  lf operator ~ () { return x * x + y * y; }            // norm^2
};

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

lf angle_slow(pt p, pt q) {             // more precision
  lf a = fmodl(abs(atan2l(p.y, p.x) - atan2l(q.y, q.x)), 2 * acosl(-1));
  return min(a, 2 * acosl(-1) - a);     // cw or ccw
}

lf angle(pt p, pt q) { return acosl(p * q / sqrtl(~p * ~q)); }
bool ccw(pt p, pt q) { return cmp(p ^ q) > 0; }
bool collinear(pt p, pt q) { return cmp(p ^ q) == 0; }

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
