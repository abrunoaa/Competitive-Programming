#include <bits/stdc++.h>
using namespace std;

int main() {
  int teste, i;
  float s, v;

  scanf("%d", &teste);
  while (teste--) {
    s = 0;
    for (i = 12; i; --i) {
      scanf(" %f", &v);
      s += v;
    }
    printf("$%.2f\n", s / 12);
  }

  return 0;
}
