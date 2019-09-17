int lower;          // posição do ponto mais baixo (o mais alto é o 0)
Point poly[maxn];

void process() { // O(n)
  int hi = 0, lo = 0;
  for (int i = 1; i < n; ++i) {
    if (poly[i].y < poly[lo].y) lo = i;
    if (poly[i].y > poly[hi].y) hi = i;
  }
  rotate(poly, poly + hi, poly + n);    // move o ponto alto para posição 0
  lower = (lo - hi + n) % n;
  poly[n] = poly[0];
}

// retorna o valor de x na reta a->b para um dado y
inline lf getx(const Point &a, const Point &b, lf y) {
  return a.x - (a.y - y) / (a.y - b.y) * (a.x - b.x); // dy nunca é 0
}

// comparação para lado esquerdo e direito
bool cmpl(lf y, const Point &p) { return cmp(y, p.y) > 0; }
bool cmpr(lf y, const Point &p) { return cmp(y, p.y) < 0; }

// polígono convexo, anti-horário
bool inConvexPolygon(const Point &p) {  // O(lg(n))
  if (cmp(p.y, poly[0].y) > 0 || cmp(p.y, poly[lower].y) < 0) return 0;
  int pl = (int)(upper_bound(poly, poly + lower, p.y, cmpl) - poly);
  int pr = (int)(upper_bound(poly + lower, poly + n, p.y, cmpr) - poly);
  lf xl = getx(poly[pl - 1], poly[pl], p.y);
  lf xr = getx(poly[pr - 1], poly[pr], p.y);
  return cmp(xl, p.x) <= 0 && cmp(p.x, xr) <= 0;  // se não aceita borda: usar < 0
}
