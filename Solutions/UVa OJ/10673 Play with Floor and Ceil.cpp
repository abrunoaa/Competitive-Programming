#include <cstdio>
#include <cmath>

typedef long long ll;

ll p, q, d, x, k, t;

void euclid (ll a, ll b) {
  if (!b) {
    p = 1, q = 0, d = a;
  } else {
    euclid(b, a % b);

    ll temp = p - a / b * q;
    p = q;
    q = temp;
  }
}

int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld", &x, &k);
    euclid((ll)floor((double)x / k), (ll)ceil((double)x / k));
    p *= x / d;
    q *= x / d;
    printf("%lld %lld\n", p, q);
  }

  return 0;
}
