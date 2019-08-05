Point poly[maxn];

// na reta a->b checa se o ponto p está: -1 = esquerda;  0 = colinear;  1 = direita
inline bool ccw(const Point &a, const Point &b, const Point &p) {
  return cmp((p.y - a.y) * (b.x - p.x) - (p.x - a.x) * (b.y - p.y));
}

// checa se o ponto p está no segmento a->b
inline bool onLine(const Point &a, const Point &b, const Point &p) {
  return ccw(a, p, b) == 0
         && cmp(min(a.x, b.x), p.x) <= 0 && cmp(p.x, max(a.x, b.x)) <= 0
         && cmp(min(a.y, b.y), p.y) <= 0 && cmp(p.y, max(a.y, b.y)) <= 0;
}

// sentido horário ou anti-horário, convexo ou não
bool inPolygon(Point p) {          // O(n)
  assert(poly[0] == poly[n]);
  bool inside = 0;
  for (int i = 0; i < n; ++i) {
    if (cmp(min(poly[i].y, poly[i + 1].y), p.y) <= 0
        && cmp(p.y, max(poly[i].y, poly[i + 1].y)) <= 0) {
      if (onLine(poly[i], poly[i + 1], p)) { // o ponto está na borda
        return 1;
      }
      auto dx = poly[i].x - poly[i + 1].x;
      auto dy = poly[i].y - poly[i + 1].y;
      inside ^= p.x < poly[i + 1].x + (p.y - poly[i + 1].y) / dy * dx;
    }
  }
  return inside;
}
