#include <bits/stdc++.h>
using namespace std;

#define maxn 200010
#define mod 1000000007

typedef long long ll;

char vis[maxn];
int n, root, a[maxn], two[maxn] = {1};
vector<int> cycles;

void build() {
  for (int i = 1; i < maxn; ++i) {
    two[i] = 2 * two[i - 1] % mod;
  }
}

void dfs2(int u) {
  ++cycles.back();
  vis[u] = 1;
  if (vis[a[u]] != 1) { dfs2(a[u]); }
}

void dfs(int u) {
  if (!vis[u]) {
    vis[u] = 2;
    dfs(a[u]);
  } else if (vis[u] == 2) {
    cycles.push_back(0);
    dfs2(u);
  }

  vis[u] = 1;
}

int main() {
  // freopen("in","r",stdin);
  build();
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) { cin >> a[i]; }

  for (int u = 1; u <= n; ++u)
    if (!vis[u]) {
      dfs(u);
    }
  int ans = 1, e = n;
  for (int c : cycles) {
    e -= c;
    // cerr << " >> " << c << endl;
    ans = ll(ans) * (two[c] - 2 + mod) % mod;
  }
  // cerr << " ## " << e << endl;
  ans = ll(ans) * two[e] % mod;
  cout << ans << '\n';

  return 0;
}
