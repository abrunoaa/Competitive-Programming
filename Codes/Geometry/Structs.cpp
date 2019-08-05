#include <bits/stdc++.h>
using namespace std;

#define pi acos(-1.0)
#define eps 1e-9
#define torad(x) ((x) * pi / 180.0)
#define todeg(x) ((x) * 180.0 / pi)

typedef long double lf;

inline int cmp(lf x, lf y = 0.0) { return (abs(x - y) < eps ? 0 : x < y ? -1 : 1); }

struct pt {
  lf x, y;
  pt(lf x = 0.0, lf y = 0.0) : x(x), y(y) {}
  pt(pt p, pt q) : x(q.x - p.x), y(q.y - p.y) {}  // cria vetor

  lf dist(pt p) { return hypot(x - p.x, y - p.y); }

  bool operator == (pt p) const { return !cmp(x, p.x) && !cmp(y, p.y); }
  bool operator < (pt p) const { return !cmp(x, p.x) ? cmp(y, p.y) < 0 : cmp(x, p.x) < 0; }

  // roda este ponto r° (radianos) anti-horário em torno da origem
  pt rotate(lf r) { return pt(x * cos(r) - y * sin(r), x * sin(r) + y * cos(r)); }

  pt operator * (lf s) { return pt(x * s, y * s); }
  pt operator / (lf s) { return pt(x / s, y / s); }
  pt operator + (pt p) { return pt(x + p.x, y + p.y); }
  pt operator - (pt p) { return pt(x - p.x, y - p.y); }
  lf operator * (pt v) { return x * v.x + y * v.y; }  // produto escalar
  lf cross(pt v) { return x * v.y - y * v.x; }  // produto vetorial
  lf operator ~ () { return x * x + y * y; }  // norma^2 deste vetor
};

// retorna o ponto da reta a -> b mais próximo de p
pt closest(pt a, pt b, pt p) {
  pt ab(a, b), ap(a, p);
  return a + ab * (ab * ap / ~ab);
}

// retorna o ponto do segmento a -> b mais próximo de p
pt closestSegm(pt a, pt b, pt p) {
  pt ab(a, b), ap(a, p);
  lf u = ab * ap / ~ab;
  return (u < 0.0 ? a : u > 1.0 ? b : a + ab * u);
}

// retorna o angulo entre a e b com origem em o
lf angle(pt a, pt o, pt b) {
  pt oa(o, a), ob(o, b);
  return acos(oa * ob / sqrt(~oa * ~ob));
}

bool ccw(pt p, pt q, pt r) { return cmp(pt(p, q).cross(pt(p, r))) > 0; }
bool collinear(pt p, pt q, pt r) { return cmp(pt(p, q).cross(pt(p, r))) == 0; }

struct Circle {     // (x - a)^2 + (y - b)^2 = r^2
  lf x, y, r;
  Circle(lf x = 0.0, lf y = 0.0, lf r = -1.0) : x(x), y(y), r(r) {}
  Circle(pt p) : x(p.x), y(p.y), r(0.0) {}
  Circle(pt p, pt q) {
    x = (p.x + q.x) / 2.0;
    y = (p.y + q.y) / 2.0;
    r = hypot(x - p.x, y - p.y);
  }
  Circle(pt p, pt q, pt s) : r(-1.0) {
    lf d = 2.0 * ((p.x - q.x) * (q.y - s.y) - (p.y - q.y) * (q.x - s.x));
    if (cmp(d) != 0) {
      lf bc = ~p - ~q, cd = ~q - ~s;
      x = (bc * (q.y - s.y) - cd * (p.y - q.y)) / d;
      y = (cd * (p.x - q.x) - bc * (q.x - s.x)) / d;
      r = hypot(x - q.x, y - q.y);
    }
  }

  lf circumference() { return 2.0 * pi * r; }
  lf area() { return pi * r * r; }
  lf arc(lf ang) { return ang * circumference() / 360.0; }
  lf chord(lf ang) { return 2.0 * r * sin(torad(ang / 2.0)); }
  lf sector(lf ang) { return ang * area() / 360.0; }

  int inside(pt p) {
    int t = cmp(hypot(p.x - x, p.y - y), r);
    return t == 0 ? 2 : t < 0;     // 2 = borda, 1 = dentro, 0 = fora
  }

  // interseção de círculos com raio diferente
  int intersection(Circle c, pt &i1, pt &i2) {
    lf d = hypot(x - c.x, y - c.y);
    if (cmp(d, r + c.r) > 0) { return 0; } // separados
    if (cmp(d, abs(r - c.r)) < 0) { return 0; } // um contem o outro
    if (cmp(d) == 0 && cmp(r, c.r) == 0) { return 0; } // coincidentes (iguais)

    lf a = (r * r - c.r * c.r + d * d) / (2.0 * d);
    lf x2 = x + a * (c.x - x) / d;
    lf y2 = y + a * (c.y - y) / d;
    lf h = sqrt(r * r - a * a);
    if (cmp(h) == 0) {
      i1 = i2 = pt(x2, y2);
      return 1;
    }

    i1 = pt(x2 + h * (c.y - y) / d, y2 - h * (c.x - x) / d);
    i2 = pt(x2 - h * (c.y - y) / d, y2 + h * (c.x - x) / d);
    return 2;
  }
};

#define maxn 1000010

pt p[maxn], b[3];

// retorna o menor círculo que todos os pontos de p estão dentro, ou não existe
Circle cover(int np, int nb) {
  if (nb == 3) { return Circle(b[0], b[1], b[2]); }
  if (np < 0) {
    if (nb == 1) { return Circle(b[0]); }
    if (nb == 2) { return Circle(b[0], b[1]); }
    return Circle();                    // retorna raio = -1
  }

  Circle c = cover(np - 1, nb);
  if (cmp(hypot(p[np].x - c.x, p[np].y - c.y), c.r) <= 0) {
    return c;
  }

  b[nb] = p[np];
  return cover(np - 1, nb + 1);
}

// Raio da Terra: Polar = 6357km, Equatorial = 6378km, Média = 6371km

struct latlon { lf r, lat, lon; }; // lat-lon em radianos!
struct rect { lf x, y, z; };

latlon convert(rect p) {
  lf r = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
  return latlon{ r,
                 asin(p.z / r),
                 acos(p.x / hypot(p.x, p.y)) };
}

rect convert(latlon l) {
  return rect{ l.r * cos(l.lon)* cos(l.lat),
               l.r * sin(l.lon)* cos(l.lat),
               l.r * sin(l.lat) };
}

int main() {
  cout << setprecision(20);
  return 0;
}
