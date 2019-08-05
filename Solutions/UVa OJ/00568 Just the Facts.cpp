#include <bits/stdc++.h>
using namespace std;

#define MAX 10010
#define MOD 1000000000

int main() {
  int n, ans[MAX];

  for (long long i = 1, fat = 1; i < MAX; ++i) {
    ans[i - 1] = fat % 10;
    fat *= i;
    while (fat % 10 == 0) { fat /= 10; }
    fat %= MOD;
  }

  while (scanf("%d", &n) == 1) { printf("%5d -> %d\n", n, ans[n]); }

  return 0;
}
