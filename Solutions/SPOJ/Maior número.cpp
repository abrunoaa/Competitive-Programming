#include <cstdio>

int main() {
  register long long n, maior = -9999;
  scanf("%lld", &n);
  while (n != 0) {
    if (n > maior) {
      maior = n;
    }

    scanf("%lld", &n);
  }
  printf("%lld", maior);
}
