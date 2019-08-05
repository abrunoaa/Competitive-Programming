#include <bits/stdc++.h>
using namespace std;

int main() {
  long n;
  int teste;

  scanf("%d", &teste);
  while (teste--) {
    scanf("%ld", &n);
    printf("%ld\n", static_cast < long > (sqrtl((n << 1) + 0.25) - 0.5));
  }
  return 0;
}
