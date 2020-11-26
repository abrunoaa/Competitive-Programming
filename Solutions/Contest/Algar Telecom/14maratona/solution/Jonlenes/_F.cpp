#include <iostream>

using namespace std;

inline bool isBissexto(int ano) {
  return (ano % 400 == 0 || (ano % 100 != 0 && ano % 4 == 0));
}

struct data {
  int dia, mes, ano;
};

int countDiaMens[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int  main() {

  //freopen("../input.txt","r", stdin);
  //freopen("../out.txt","w", stdout);

  data d1, d2;
  int n, i, diff;

  cin >> n;
  while (n--) {
    scanf("%d-%d-%d %d-%d-%d", &d1.ano, &d1.mes, &d1.dia, &d2.ano, &d2.mes, &d2.dia);

    if (d1.ano > d2.ano || (d1.ano == d2.ano && d1.mes > d2.mes)
        || (d1.ano == d2.ano && d1.mes == d2.mes && d1.dia > d2.dia)) {
      swap(d1, d2);
    }

    diff = 0;
    for (i = d1.ano; i < d2.ano; ++i)
      if (isBissexto(i)) { diff += 366; }
      else { diff += 365; }

    for (i = 1; i < d1.mes; ++i) {
      diff -= countDiaMens[i];
    }

    if (isBissexto(d1.ano) && d1.mes > 2) {
      diff -= 1;
    }

    diff -= d1.dia;

    for (i = 1; i < d2.mes; ++i) {
      diff += countDiaMens[i];
    }

    if (isBissexto(d2.ano) && d2.mes > 2) {
      diff += 1;
    }

    diff += d2.dia;

    printf("%d\n", diff);
  }


  return 0;
}
