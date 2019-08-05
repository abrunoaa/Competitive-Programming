#define maxn 1000010

pt p[maxn], b[3];

// retorna o menor círculo que todos os pontos de p estão dentro
circle cover(int np, int nb) {
  if (nb == 3) { return circle(b[0], b[1], b[2]); }
  if (np < 0) {
    if (nb == 1) { return circle(b[0]); }
    if (nb == 2) { return circle(b[0], b[1]); }
    return circle();                    // retorna raio = -1
  }

  circle c = cover(np - 1, nb);
  if (hypot(p[np].x - c.a, p[np].y - c.b) < c.r + eps) {
    return c;
  }

  b[nb] = p[np];
  return cover(np - 1, nb + 1);
}
