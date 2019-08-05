#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d, tot = 0;
  char s[20];

  scanf("%d", &n);
  while (n--) {
    scanf(" %s", s);
    if (*s == 'd') {
      scanf("%d", &d);
      tot += d;
    } else {
      printf("%d\n", tot);
    }
  }

  return 0;
}





