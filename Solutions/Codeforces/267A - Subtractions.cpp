#include <bits/stdc++.h>
using namespace std;

int main() {
  int T, a, b;
  long long n;

  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &a, &b);
    if (a > b) { swap(a, b); }

    n = 0;
    while (a && b) {
      n += (b - b % a) / a;
      b = b % a;
      swap(a, b);
    }

    cout << n << '\n';
  }

  return 0;
}
