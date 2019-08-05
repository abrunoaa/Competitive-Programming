#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef pair < int, int > ii;
typedef pair < int, ii > iii;

int t, n, k, i, num[50];
map < iii, int > dp;

int getMax (int k, int id, int v) {
  if (!k) { return v; }
  if (id == n) { return 0; }

  if (dp.find(iii(k, ii(id, v))) != dp.end()) {
    return dp[iii(k, ii(id, v))];
  }

  return dp[iii(k, ii(id, v))] = max(getMax(k, id + 1, v), getMax(k - 1, id + 1, v & num[id]));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> t;
  while (t-- && cin >> n >> k) {
    for (i = 0; i < n; ++i) {
      cin >> num[i];
    }
    cout << getMax(k, 0, (-1u) >> 1) << endl;
    dp.clear();
  }

  return 0;
}
