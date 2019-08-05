#include <bits/stdc++.h>
using namespace std;

#define maxn 4010

typedef long long ll;

int a, f[10 * maxn], s[maxn];
string str;

int main() {
  // freopen("in","r",stdin);

  cin >> a >> str;
  int n = str.size();

  for (int i = 1; i <= n; ++i) {
    s[i] = s[i - 1] + str[i - 1] - '0';
  }
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; ++j) {
      ++f[s[j] - s[i - 1]];
    }

  ll ans = 0;
  if (a == 0) {
    ans = (ll)f[0] * f[0];
    for (int i = 1; i < 10 * maxn; ++i) {
      ans += 2ll * f[0] * f[i];
    }
  } else {
    ans = 0;
    for (int i = 1; i < 10 * maxn; ++i)
      if (a % i == 0 && a / i < 10 * maxn) {
        ans += (ll)f[i] * f[a / i];
      }
  }

  cout << ans << '\n';

  return 0;
}
