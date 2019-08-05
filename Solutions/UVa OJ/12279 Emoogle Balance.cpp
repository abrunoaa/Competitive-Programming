#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, v, q, cs = 0;
  while (scanf("%d", &n), n) {
    q = 0;
    while (n--) {
      scanf("%d", &v);
      v ? ++q : --q;
    }
    printf("Case %d: %d\n", ++cs, q);
  }

  return 0;
}





