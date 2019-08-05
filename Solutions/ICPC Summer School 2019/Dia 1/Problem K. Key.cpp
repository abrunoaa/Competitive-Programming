#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll sum9[20], memo[20][10];
string ans;

// ABdCD -> ABdCD + ABdC+D + ABd+CD + AB+dCD + A+BdCD
ll calc(int i, int d) {
  ll &pd = memo[i][d];
  if (pd != -1) { return pd; }

  pd = 0;
  ll p10 = 1;
  for (int j = 0; j < i; ++j) {
    pd += p10 * d;
    p10 *= 10;
  }
  return pd += i * p10 / 10 * d;
}

bool f(int i, ll k) {
  if (k == 0) {
    while (i < n) {
      ans.push_back('0');
      ++i;
    }
    return 1;
  }
  if (i == n || k < 0) { return 0; }

  // cerr << " -- " << i << ' ' << k << " == " << sum9[i] << ' ' << sum0[i] << endl;
  if (sum9[i] < k) { return 0; }

  for (int d = i == 0; d < 10; ++d) {
    // cerr << " ## " << i << ' ' << k << ' ' << d << " == " << calc(i, d) << endl;
    if (f(i + 1, k - calc(n - i, d))) {
      ans.push_back(d + '0');
      return 1;
    }
  }

  return 0;
}

void start() {
  memset(memo, -1, sizeof memo);

  sum9[15] = calc(0, 9);
  for (int i = 14; i >= 0; --i) {
    sum9[i] = sum9[i + 1] + calc(n - i, 9);
  }
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  ll k;
  cin >> k;

  ll t = k;
  n = 0;
  while (t) { t /= 10, ++n; }

  start();
  while (start(), n > 0 && !f(0, k)) { --n; }
  reverse(ans.begin(), ans.end());
  if (!n) { ans = "-1"; }
  cout << ans << '\n';

  return 0;
}
