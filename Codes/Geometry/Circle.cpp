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
      x =  (bc * (q.y - s.y) - cd * (p.y - q.y)) / d;
      y = -(bc * (q.x - s.x) - cd * (p.x - q.x)) / d;
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
