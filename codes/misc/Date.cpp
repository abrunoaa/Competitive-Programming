struct date {
  int d, m, y;
  static int ms[];  // prefix sum of days by month

  inline bool leap() { return (y % 4 == 0 && y % 100) || y % 400 == 0; }

  inline int count() { return ysum() + msum() + d - 1; }

  // 0 = Sunday
  inline int weekday() { return (count() + 1) % 7; }

  void advance(int ndays) {
    if (ndays == 0) return;
    ndays += count();
    d = m = 1;
    y = ndays / 366 + 1;
    ndays -= count();
    for (; ndays >= ydays(); ndays -= ydays()) ++y;
    for (; ndays >= mdays(); ndays -= mdays()) ++m;
    d += ndays;
  }

private:

  inline int mdays() { return ms[m] - ms[m - 1] + (m == 2 && leap()); }

  inline int ydays() { return 365 + leap(); }

  inline int msum() { return ms[m - 1] + (m > 2) * leap(); }

  inline int ysum() {
    int k = y - 1;
    return 365 * k + k / 4 - k / 100 + k / 400;
  }
};
int date::ms[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

int weekday(int d, int m, int y) {
  static int v[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};  // v[i] = ms[i] mod 7

  y -= (m <= 2);
  return (d + v[m - 1] + y + y / 4 - y / 100 + y / 400 + 6) % 7;
}
