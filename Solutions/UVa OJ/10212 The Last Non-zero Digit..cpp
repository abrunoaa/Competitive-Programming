#include <cstdio>

int main() {
  long long i, n, m, ans;

  for (; scanf("%lld%lld", &n, &m) == 2; printf("%lld\n", ans % 10))
    for (i = n, ans = 1; i > n - m; --i) {
      for (ans *= i; ans % 10 == 0; ans /= 10);
      ans %= 1000000000LL;
    }

  return 0;
}
