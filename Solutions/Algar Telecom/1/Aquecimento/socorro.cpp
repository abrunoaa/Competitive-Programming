#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, i, n, v[30];
  char p, cor[30], c;
  string jul;

  while (scanf("%d", &n), n) {
    for (i = 30; i; ) {
      v[--i] = 0;
      cor[i] = 0;
    }
    while (n--) {
      scanf(" %c %d", &p, &t);
      cin.ignore();
      cin >> jul;
      if (!cor[(int)(p - 65)]) {
        if (jul == "correto") {
          v[(int)(p - 65)] += t;
          cor[(int)(p - 65)] = 1;
        } else {
          v[(int)(p - 65)] += 20;
        }
      }
    }

    t = 0;
    c = 0;
    for (i = 0; i < 26; ++i)
      if (cor[i]) {
        ++c;
        t += v[i];
      }
    printf("%d %d\n", (int)c, t);
  }

  return 0;
}
