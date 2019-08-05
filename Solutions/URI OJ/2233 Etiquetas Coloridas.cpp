// Ad Hoc - muito fácil

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll r, g, b, etiq;

  while (scanf("%llx%llx%llx", &r, &g, &b) == 3) {
    etiq = pow(r / g, 2);
    etiq += etiq * pow(g / b, 2);
    printf("%llx\n", etiq + 1);
  }

  return 0;
}
