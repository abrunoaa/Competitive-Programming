struct pt {
  lf x, y;
  pt(lf x = 0.0, lf y = 0.0) : x(x), y(y) {}
  pt(pt p, pt q) : x(q.x - p.x), y(q.y - p.y) {}  // cria vetor

  lf dist(pt p) { return hypot(x - p.x, y - p.y); }

  bool operator == (pt p) const { return !cmp(x, p.x) && !cmp(y, p.y); }
  bool operator < (pt p) const { return cmp(x, p.x) ? cmp(x, p.x) < 0 : cmp(y, p.y) < 0; }

  // roda este ponto r° (radianos) anti-horário em torno da origem
  pt rotate(lf r) { return pt(x * cos(r) - y * sin(r), x * sin(r) + y * cos(r)); }

  pt operator * (lf s) { return pt(x * s, y * s); }
  pt operator / (lf s) { return pt(x / s, y / s); }
  pt operator + (pt p) { return pt(x + p.x, y + p.y); }
  pt operator - (pt p) { return pt(x - p.x, y - p.y); }
  lf operator * (pt v) { return x * v.x + y * v.y; }    // produto escalar
  lf cross(pt v) { return x * v.y - y * v.x; }          // produto vetorial
  lf operator ~ () { return x * x + y * y; }            // norma^2
};

// ordena os pontos em anti-horário
bool cmp_counter(const pt &p, const pt &q) {
  if (!q.y && q.x >= 0) return 0;
  if (!p.y && p.x >= 0) return 1;
  if (p.y * q.y < 0) return p.y > 0;
  return cross(p, q) > 0;
}

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
