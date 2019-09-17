const int maxn = 1000003;

pt p[maxn], b[3];

Circle cover(int np, int nb) {          // O(n)
  if (nb == 3) return Circle(b[0], b[1], b[2]);
  if (np < 0) {
    if (nb == 1) return Circle(b[0]);
    if (nb == 2) return Circle(b[0], b[1]);
    return Circle();                    // retorna raio = -1
  }
  Circle c = cover(np - 1, nb);
  if (cmp(hypot(p[np].x - c.x, p[np].y - c.y), c.r) <= 0) return c;
  b[nb] = p[np];
  return cover(np - 1, nb + 1);
}
