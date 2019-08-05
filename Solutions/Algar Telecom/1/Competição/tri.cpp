#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  float ans;

  while (scanf("%d%d%d", &a, &b, &c), a || b || c) {
    if (a == -1) {
      ans = sqrt(c * c - b * b);
    } else if (b == -1) {
      ans = sqrt(c * c - a * a);
    } else {
      ans = sqrt(a * a + b * b);
    }
    ans *= 1000;

    printf("%.3f\n", trunc(ans) / 1000);
  }

  return 0;
}
