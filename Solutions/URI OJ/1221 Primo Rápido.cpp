#include <bits/stdc++.h>
using namespace std;

bool checa(uint n) {
  if (n == 2) {
    return 1;
  }
  if (n < 2 || n % 2 == 0) {
    return 0;
  }
  register int i = 0, m = sqrt(n) + 1;
  for (i = 3; i <= m; i += 2)
    if (n % i == 0) {
      return 0;
    }
  return 1;
}

int main() {
  uint T, n;
  scanf("%u", &T);
  while (T--) {
    scanf("%u", &n);
    printf("%s\n", checa(n) ? "Prime" : "Not Prime");
  }

  return 0;
}
