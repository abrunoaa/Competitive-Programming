// Ad Hoc - muito fácil

#include <bits/stdc++.h>
using namespace std;

int main() {
  int v[3], i;
  while (scanf("%d%d%d", v, v + 1, v + 2) == 3) {
    sort(v, v + 3);
    for (i = 1; i < 3 && v[i] != v[i - 1]; ++i);  // checa se tem iguais
    if (i < 3 || v[0] + v[1] == v[2]) {
      puts("S");  // tem iguais ou volta usando 3
    } else {
      puts("N");
    }
  }

  return 0;
}
