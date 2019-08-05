struct date {
  int d, m, y;
  static int ms[];  // soma de prefixo na qtde de dias no mês

  // checa se o ano atual é bissexto
  bool leap() { return (y % 4 == 0 && y % 100) || y % 400 == 0; }

  // qtde de dias no mês atual
  int mdays() { return ms[m] - ms[m - 1] + (m == 2 && leap()); }

  // qtde de dias no ano atual
  int ydays() { return 365 + leap(); }

  // qtde de dias do início do ano até o mês anterior (ou 0, se mês = 1)
  int msum() { return ms[m - 1] + (m > 2) * leap(); }

  // qtde de dias do ano 1 até o ano anterior
  int ysum() {
    int k = y - 1;
    return 365 * k + k / 4 - k / 100 + k / 400;
  }

  // diff de dias de 01/01/0001 até o dia atual
  int count() { return ysum() + msum() + d - 1; }

  // retorna 0 = dom, 1 = seg, ..., 6 = sáb
  int weekday() { return (count() + 1) % 7; }

  // avança n dias a partir do atual
  void advance(int n) {
    n += count();
    d = m = 1;
    y = n / 366 + 1;
    n -= count();
    while (n >= ydays()) { n -= ydays(), ++y; }
    while (n >= mdays()) { n -= mdays(), ++m; }
    d += n;
  }
};
int date::ms[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

int weekday(int d, int m, int y) {
  static int v[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};  // v[i] = ms[i] mod 7

  y -= (m <= 2);
  return (d + v[m - 1] + y + y / 4 - y / 100 + y / 400 + 6) % 7;
}
