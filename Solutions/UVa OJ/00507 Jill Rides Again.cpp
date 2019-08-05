#include <bits/stdc++.h>
using namespace std;

int main() {
  //freopen("in", "r", stdin);

  int t, s, pi = 0, pj = 0, i, sum, ans, route = 0, ini, a[20100];

  scanf("%d", &t);
  while (t--) {
    scanf("%d", &s);
    --s;

    for (i = 0; i < s; ++i) {
      scanf("%d", a + i);
    }

    sum = ans = 0;
    ini = i;

    while (i) {                   // percorre invertido para achar o menor i possivel
      // dp
      sum += a[--i];
      if (sum > ans) {
        ans = sum;
        pi = i;
        pj = ini;
      } else if (sum == ans) {    // empate
        if (pj - pi <= ini - i) { // pega a maior diff e menor i
          pi = i;
          pj = ini;
        }
      } else if (sum < 0) {
        sum = 0;
        ini = i;
      }
      // \dp
    }

    if (!ans) {
      printf("Route %d has no nice parts\n", ++route);
    } else {
      printf("The nicest part of route %d is between stops %d and %d\n", ++route, pi + 1, pj + 1);
    }
  }

  return 0;
}
