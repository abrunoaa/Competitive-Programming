#include <bits/stdc++.h>
using namespace std;

#define pi M_PIl
#define eps 1e-9
#define sq(x) ((x) * (x))
#define torad(x) ((x) * pi / 180.0)
#define todeg(x) ((x) * 180.0 / pi)
#define zero(x) (abs(x) < eps)

typedef long double lf;

struct pt{
  lf x, y;

  pt() {}
  pt(lf x, lf y) : x(x), y(y) {}
  pt(pt p, pt q) : x(q.x - p.x), y(q.y - p.y) {}  // cria vetor

  lf dist(pt p) { return hypot(x - p.x, y - p.y); }

  bool operator == (pt p) const { return zero(x - p.x) && zero(y - p.y); }
  bool operator < (pt p) const { return zero(x - p.x) ? y <= p.y - eps : x < p.x; }

  // roda este ponto r° (radianos) anti-horário em torno da origem
  pt rotate(lf r) { return pt(x * cos(r) - y * sin(r), x * sin(r) + y * cos(r)); }

  pt operator * (lf s) { return pt(x * s, y * s); } // redimensionar vetor
  pt operator + (pt p) { return pt(x + p.x, y + p.y); } // somar vetores
  lf operator * (pt v) { return x * v.x + y * v.y; }  // produto escalar
  lf cross(pt v) { return x * v.y - y * v.x; }  // produto vetorial
  lf operator ~ () { return x * x + y * y; }  // norma^2 deste vetor
};

// retorna o ponto da reta a -> b mais próximo de p
pt closest(pt a, pt b, pt p){
  pt ab(a, b), ap(a, p);
  return a + ab * (ab * ap / ~ab);
}

// retorna o ponto do segmento a -> b mais próximo de p
pt closestSegm(pt a, pt b, pt p){
  pt ab(a, b), ap(a, p);
  lf u = ab * ap / ~ab;
  return (u < 0.0 ? a : u > 1.0 ? b : a + ab * u);
}

// retorna o angulo entre a e b com origem em o
lf angle(pt a, pt o, pt b){
  pt oa(o, a), ob(o, b);
  return acos(oa * ob / sqrt(~oa * ~ob));
}

bool ccw(pt p, pt q, pt r) { return pt(p, q).cross(pt(p, r)) > 0.0; }
bool collinear(pt p, pt q, pt r) { return zero(pt(p, q).cross(pt(p, r))); }

struct circle{      // (x - a)² + (y - b)² = r²
  lf a, b, r;

  circle() : r(-1.0) {}
  circle(lf a, lf b, lf r) : a(a), b(b), r(r) {}
  circle(pt p) : a(p.x), b(p.y), r(0.0) {}
  circle(pt p, pt q){
    a = (p.x + q.x) / 2.0;
    b = (p.y + q.y) / 2.0;
    r = hypot(a - p.x, b - p.y);
  }
  circle(pt p, pt q, pt s) : r(-1.0) {
    lf d = 2.0 * ((p.x - q.x) * (q.y - s.y) - (p.y - q.y) * (q.x - s.x));
    if(!zero(d)){
      lf bc = ~p - ~q, cd = ~q - ~s;
      a = (bc * (q.y - s.y) - cd * (p.y - q.y)) / d;
      b = (cd * (p.x - q.x) - bc * (q.x - s.x)) / d;
      r = hypot(a - q.x, b - q.y);
    }
  }

  lf circumference() { return 2.0 * pi * r; }
  lf area() { return pi * r * r; }
  lf arc(lf ang) { return ang * circumference() / 360.0; }
  lf chord(lf ang) { return 2.0 * r * sin(torad(ang / 2.0)); }
  lf sector(lf ang) { return ang * area() / 360.0; }

  int inside(pt p){
    lf k = hypot(p.x - a, p.y - b);
    return zero(k - r) ? 2 : k < r;     // borda = 2, dentro = 1, fora = 0
  }
};

#define maxn 1000010

pt p[maxn], b[3];

// retorna o menor círculo que todos os pontos de p estão dentro, ou não existe
circle cover(int np, int nb){
  if(nb == 3) return circle(b[0], b[1], b[2]);
  if(np < 0){
    if(nb == 1) return circle(b[0]);
    if(nb == 2) return circle(b[0], b[1]);
    return circle();                    // retorna raio = -1
  }

  circle c = cover(np - 1, nb);
  if(hypot(p[np].x - c.a, p[np].y - c.b) < c.r + eps)
    return c;

  b[nb] = p[np];
  return cover(np - 1, nb + 1);
}

// Raio da Terra: Polar = 6357km, Equatorial = 6378km, Média = 6371km

struct latlon { lf r, lat, lon; }; // lat-lon em radianos!
struct rect { lf x, y, z; };

latlon convert(rect p){
  lf r = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
  return latlon{ r,
                  asin(p.z / r),
                  acos(p.x / hypot(p.x, p.y)) };
}

rect convert(latlon l){
  return rect{ l.r * cos(l.lon) * cos(l.lat),
               l.r * sin(l.lon) * cos(l.lat),
               l.r * sin(l.lat) };
}

int main(){
  cout << setprecision(20);
  return 0;
}
