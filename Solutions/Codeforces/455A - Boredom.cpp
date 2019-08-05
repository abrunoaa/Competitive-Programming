#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;

ll n, m, i, tmp, nums[100010] = {}, memo[100010];

ll boredom (ll i) {
  if (i > m) { return 0; }
  if (memo[i] != -1) { return memo[i]; }
  return memo[i] = max(boredom(i + 1), i * nums[i] + boredom(i + 2));
}

int main() {
  // freopen("in", "r", stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (i = m = 0; i < n; ++i) { cin >> tmp, ++nums[tmp], m = max(m, tmp); }

  memset(memo, -1, sizeof memo);
  cout << boredom(1) << endl;

  return 0;
}
