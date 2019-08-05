#include <bits/stdc++.h>
using namespace std;

string convert (int val, int b) {
  string num;

  while (val) {
    num.push_back(val
  }

  return num;
}

int main() {
  freopen("in", "r", stdin);

  char str[30][105];
  int n, q, i, k, num, rep[50];

  rep[0] = 0;
  while (scanf("%d%d", &n, &q), n || q) {
    for (i = 0; i < n; ++i) {
      scanf(" %s", str[i]);
    }

    if (n == 1)
      while (q--) {
        scanf("%*d");
        puts(str[0]);
      } else {
      for (i = 1; rep[i - 1] <= 100000000; ++i) {
        rep[i] = rep[i - 1] + pow(n, i);
      }

      while (q--) {
        scanf("%d", &k);
        for (i = 1; k > rep[i]; ++i);
        num = k - rep[i - 1];
        printf(" >> %d\n", num);
        puts(str[num - 1]);
      }
    }

    puts("");
  }

  return 0;
}
