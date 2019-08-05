#include <bits/stdc++.h>
using namespace std;

#define maxn 12

bool vis[maxn][maxn];
int n, s[maxn], ns[maxn];

bool valid(int i, int j) {
  return 0 <= i && i < n && s[i] <= j && j < s[i] + ns[i];
}

int f(int i, int j) {
  if (!valid(i, j) || vis[i][j]) { return 0; }

  vis[i][j] = 1;
  int ans = 0;
  for (int k = 0; k < 8; ++k) {
    static const int I[] = {-2, -2, -1, -1, 1, 1, 2, 2}, J[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    ans = max(ans, f(i + I[k], j + J[k]));
  }
  vis[i][j] = 0;
  return ans + 1;
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int cs = 0;
  while (cin >> n && n) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      cin >> s[i] >> ns[i];
      ans += ns[i];
    }
    memset(vis, 0, sizeof vis);
    ans -= f(0, 0);
    cout << "Case " << ++cs << ", " << ans << " square" << (ans == 1 ? "" : "s") << " can not be reached.\n";
  }

  return 0;
}
