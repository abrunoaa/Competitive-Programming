#include < bits / stdc++.h >
using namespace std;

#define maxw (2 * 10003)

typedef long long ll;

int can[103][2 * maxw];

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, l, w, r;
  cin >> n >> l >> w >> r;
  w *= 2;
  r *= 2;
  can[0][0 + maxw] = 1;
  can[0][0 + maxw + 1] = -1;
  for (int i = 1; i <= n; ++i) {
    int m;
    cin >> m;
    for (int x = -w; x <= w; ++x) {
      can[i - 1][x + maxw] += can[i - 1][x - 1 + maxw];
      if (can[i - 1][x + maxw]) {
        can[i][max((ll) - w, x - (ll)l * m) + maxw] += 1;
        can[i][max((ll) - w, x - (ll)r * m + 1) + maxw] -= 1;
        can[i][min((ll)w + 1, x + (ll)r * m) + maxw] += 1;
        can[i][min((ll)w + 1, x + (ll)l * m + 1) + maxw] -= 1;
      }
    }
  }
  bool ans = 0;
  for (int x = -w; x <= w; ++x) {
    ans |= can[n][x + maxw] += can[n][x - 1 + maxw];
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
