#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, i, sum, val, ans, diff, vet[100005];
  map < int, int > mp;

  while (scanf("%d", &n) == 1) {
    mp.clear();

    for (i = sum = 0; i < n; ++i) {
      scanf("%d", &val);
      vet[i] = sum += val;
      mp[sum] = 1;
    }

    ans = 0;
    if (sum % 3 == 0) {
      diff = sum / 3;
      for (i = 0; i < n; ++i)
        if (mp[vet[i] + diff] && mp[vet[i] + 2 * diff]) {
          ++ans;
        }
    }

    printf("%d\n", ans);
  }

  return 0;
}
