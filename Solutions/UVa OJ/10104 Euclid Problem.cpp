#include <cstdio>

typedef long long ll;

ll a, b, x, y, d;

void euclid (ll a, ll b) {
  if (!b) {
    x = 1, y = 0, d = a;
  } else {
    euclid(b, a % b);
    ll temp = x - (a / b) * y;
    x = y;
    y = temp;
  }
}

int main() {
  while (scanf("%lld%lld", &a, &b) == 2) {
    euclid(a, b), printf("%lld %lld %lld\n", x, y, d);
  }

  return 0;
}
