#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define eps 1e-9
#define maxn 100003

typedef double lf;
typedef pair<lf,lf> Point;

int n, lower;
Point poly[maxn];

inline int cmp(lf x, lf y = 0.0){ return (fabs(x - y) < eps ? 0 : x < y ? -1 : 1); }

/** apenas um ponto **/
// cria a reta a->b e checa o ponto p: -1 = esquerda;  0 = colinear;  1 = direita
inline bool ccw(const Point& a, const Point& b, const Point& p){
  return cmp((p.y - a.y) * (b.x - p.x) - (p.x - a.x) * (b.y - p.y));
}

inline bool onLine(const Point& a, const Point& b, const Point& p){
  return ccw(a, p, b) == 0
      && cmp(min(a.x, b.x), p.x) <= 0 && cmp(p.x, max(a.x, b.x)) <= 0
      && cmp(min(a.y, b.y), p.y) <= 0 && cmp(p.y, max(a.y, b.y)) <= 0;
}

// sentido horário ou anti-horário, convexo ou não
bool inPolygon_slow(Point p){           // O(n)
  assert(poly[0] == poly[n]);
  bool inside = 0;
  for(int i = 0; i < n; ++i){
    if(cmp(min(poly[i].y, poly[i + 1].y), p.y) <= 0 && cmp(p.y, max(poly[i].y, poly[i + 1].y)) <= 0){
      if(onLine(poly[i], poly[i + 1], p))   // o ponto está na borda
        return 1;
      auto dx = poly[i].x - poly[i + 1].x;
      auto dy = poly[i].y - poly[i + 1].y;
      inside ^= p.x < poly[i + 1].x + (p.y - poly[i + 1].y) / dy * dx;
    }
  }
  return inside;
}

/** vários pontos **/
// 1. divide o polígono em esquerda e direita
// 2. busca à esquerda e à direita qual segmento intersecta p.y
// 3. verifica se p.x está entre os x's encontrados
void process(){
  int hi = 0, lo = 0;
  for(int i = 1; i < n; ++i){
    if(poly[i].y < poly[lo].y) lo = i;
    if(poly[i].y > poly[hi].y) hi = i;
  }
  rotate(poly, poly + hi, poly + n);
  lower = (lo - hi + n) % n;
  poly[n] = poly[0];
}

inline lf getx(const Point& a, const Point& b, lf y){
  return a.x - (a.y - y) / (a.y - b.y) * (a.x - b.x); // dy nunca é 0
}

bool cmpl(lf y, const Point& p){ return cmp(y, p.y) > 0; }
bool cmpr(lf y, const Point& p){ return cmp(y, p.y) < 0; }

// polígono convexo, anti-horário
bool inConvexPolygon(const Point& p){   // O(lg(n))
  if(cmp(p.y, poly[0].y) > 0 || cmp(p.y, poly[lower].y) < 0) return 0;
  int pl = (int)(upper_bound(poly, poly + lower, p.y, cmpl) - poly);
  int pr = (int)(upper_bound(poly + lower, poly + n, p.y, cmpr) - poly);
  assert(0 < pl && pl <= lower);
  assert(lower < pr && pr <= n);
  assert(poly[pl].y <= p.y && p.y <= poly[pl - 1].y);
  assert(poly[pr - 1].y <= p.y && p.y <= poly[pr].y);
  lf xl = getx(poly[pl - 1], poly[pl], p.y);
  lf xr = getx(poly[pr - 1], poly[pr], p.y);
  return cmp(xl, p.x) <= 0 && cmp(p.x, xr) <= 0;  // se não aceita borda: usar < 0
}

int main(){
  assert(freopen("in","r",stdin));
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> poly[i].x >> poly[i].y;
  }
  reverse(poly, poly + n);
  process();
  int q;
  cin >> q;
  while(q--){
    Point p;
    cin >> p.x >> p.y;
    cout << inPolygon_slow(p) << ' ' << inConvexPolygon(p) << endl;
  }
  return 0;
}
