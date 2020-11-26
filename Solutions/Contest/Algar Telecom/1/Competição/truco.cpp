#include <bits/stdc++.h>
using namespace std;

int main() {
  register int i, j;
  int t, v;
  bool fl;

  scanf("%d", &t);
  while (t--) {
    scanf("%d", &v);
    fl = 0;
    for (i = 1, j = 0; i; i <<= 1, ++j)
      if (v & i) {
        printf("%s%d", (fl ? " " : ""), j);
        fl = 1;
      }
    printf("\n");
  }

  return 0;
}
