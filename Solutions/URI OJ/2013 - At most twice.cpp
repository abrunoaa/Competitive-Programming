#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int freq[10], tmp[10];
string s;
ll p10[20];

int main() {
  // assert(freopen("in","r",stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> s;
  p10[0] = 1;
  for (int i = 1; i < 20; ++i) {
    p10[i] = 10 * p10[i - 1];
  }
  bool ok = 1;
  for (char c : s) {
    ++freq[c - '0'];
    ok &= freq[c - '0'] <= 2;
  }
  if (ok) {
    cout << s << '\n';
    return 0;
  }
  ll ans = 0;
  ll x = stoll(s);
  for (int i = (int)s.size() - 1; i >= 0; --i) {
    // prexeca ;)
    int prev = s[i] - '0';
    x -= p10[s.size() - i - 1] * prev;
    --freq[prev];
    ok = 1;
    for (int j = 0; j <= 9; ++j) {
      ok &= freq[j] <= 2;
    }
    int next;
    for (next = prev - 1; next >= 0 && freq[next] == 2; --next);
    ok &= next >= 0;
    if (!ok) { continue; }
    memset(tmp, 0, sizeof(tmp));
    ll y = x + p10[s.size() - i - 1] * next;
    ++tmp[next];
    for (int j = i + 1; j < (int)s.size(); ++j) {
      int k;
      for (k = 9; k > 0 && freq[k] + tmp[k] == 2; --k);
      y += k * p10[s.size() - j - 1];
      ++tmp[k];
    }
    ans = max(ans, y);
  }
  cout << ans << '\n';
  return 0;
}
