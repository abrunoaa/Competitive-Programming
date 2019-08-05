#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;

  while (scanf("%d%d%d%d", &a, &b, &c, &d) > 0) {
    if (b && c && a == c && b == d) {
      printf("E um retangulo\n");
    } else {
      printf("Nao e um retangulo\n");
    }
  }
  return 0;
}
