#include <bits/stdc++.h>
using namespace std;

#define MAX 110

int main() {
  int t, last, i, j, f, serie[MAX];
  long long fib[MAX], limit;
  char s[MAX], ans[MAX];
  map<int, bool> used;
  map<int, int> fibPos;

  fibPos[1] = 0;
  fib[0] = 1;
  fib[1] = 2;
  for (i = 1, limit = 1ll << 31; fib[i] < limit; ++i) {
    fibPos[fib[i]] = i;
    fib[i + 1] = fib[i] + fib[i - 1];
  }

  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) { scanf("%d", serie + i); }
    scanf(" %[^\n]", s);

    memset(ans, -1, sizeof ans);
    for (i = j = 0, last = -1; s[i]; ++i)
      if (isupper(s[i])) {
        f = fibPos[serie[j++]];
        last = max(last, f);
        ans[f] = s[i];

        if (j == n) { break; }
      }

    for (i = 0; i <= last; ++i)
      if (ans[i] == -1) {
        ans[i] = ' ';
      }
    ans[last + 1] = 0;
    printf("%s\n", ans);
  }

  return 0;
}
