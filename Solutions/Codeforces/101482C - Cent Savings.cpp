#include <bits/stdc++.h>
using namespace std;

int n, d, i;
int p[2002], dp[22][2002], sum[2002];

int arred (int v) {
  int k = v % 10;
  return k < 5 ? v - k : v + 10 - k;
}

int buy (int d, int pos) {
  if (pos == n) { return 0; }

  int &ref = dp[d][pos];
  if (ref != -1) { return ref; }

  if (!d) {
    return ref = sum[pos];
    ref = 0;
    for (int i = pos; i < n; ++i) { ref += p[i]; }
    // cerr << " >> " << arred(ref) << endl;
    return ref;
  }
  // cerr << " ## " << pos << " " << buy(d, pos + 1) + p[pos] << endl;
  // cerr << " $$ " << pos << " " << arred(buy(d - 1, pos + 1) + p[pos]) << endl;
  return ref = min(buy(d, pos + 1) + p[pos], arred(buy(d - 1, pos + 1) + p[pos]));
}

int main() {
  // freopen("cin", "r", stdin);

  scanf("%d%d", &n, &d);
  for (i = 0; i < n; ++i) {
    scanf("%d", p + i);
  }
  sum[n - 1] = p[n - 1];
  for (i = n; --i; sum[i - 1] = sum[i] + p[i - 1]);

  memset(dp, -1, sizeof dp);
  printf("%d\n", arred(buy(d, 0)));

  return 0;
}
