#include <stdio.h>
#include <map>
using namespace std;

int mes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool ehbissexto(int ano) {return (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0));}

int main() {
  int q, a, a1, m, m1, d, d1, dias;
  scanf("%d", &q);
  while (q--) {
    scanf(" %d %*c %d %*c %d %d %*c %d %*c %d", &a, &m, &d, &a1, &m1, &d1);

    if (a1 < a || (a == a1 && m1 < m) || (a1 == a && m1 == m && d1 < d)) {
      swap(a, a1), swap(m, m1), swap(d, d1);
    }

    dias = 0;
    if (d1 >= d) { dias += d1 - d; }
    else {
      if (m == 2 && ehbissexto(a)) { dias++; }
      dias += mes[m++] - d + d1;
    }
    if (m == 13) { m = 1, a++; }

    while (m != m1 || a != a1) {
      if (m == 2 && ehbissexto(a)) { dias++; }
      dias += mes[m++];
      if (m == 13) { m = 1, a++; }
    }
    printf("%d\n", dias);
  }
  return 0;
}
