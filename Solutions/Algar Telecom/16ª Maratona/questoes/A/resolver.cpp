#include <bits/stdc++.h>
using namespace std;

int main() {
  long n1, n2, n3, x;
  while (scanf("%ld%ld%ld", &n1, &n2, &n3), n1 || n2 || n3)
    if (--n3 % 5) {
      printf("Nao achou.\n");
    } else {
      printf((x = n3 / 5) >= n1 && x <= n2 ? "Achou.\n" : "Nao achou.\n");
    }

  return 0;
}
