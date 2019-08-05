#include <bits/stdc++.h>
using namespace std;

int main() {
  //freopen("in", "r", stdin);

  register int n, sum, ans;
  int N, p;

  while (scanf("%d", &N), N) {
    n = N;

    // dp: Max 1D sum
    ans = sum = 0;
    while (n--) {
      scanf("%d", &p);
      if ((sum += p) > ans) {
        ans = sum;
      } else if (sum < 0) {
        sum = 0;
      }
    }
    // \dp

    if (ans > 0) {
      printf("The maximum winning streak is %d.\n", ans);
    } else {
      puts("Losing streak.");
    }
  }

  return 0;
}
