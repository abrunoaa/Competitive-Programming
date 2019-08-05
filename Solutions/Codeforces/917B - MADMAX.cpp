#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define maxn 102

typedef pair<int, int> ii;

char memo[2][maxn][maxn][26];
int n, m;
vector<ii> g[maxn];

bool f(bool turn, int i, int j, char last) {
  auto &pd = memo[turn][i][j][last - 'a'];
  if (pd != -1) { return pd; }

  pd = 0;
  for (auto v : g[(!turn ? i : j)]) {
    if (v.nd >= last && !f(!turn, (!turn ? v.st : i), (turn ? v.st : j), v.nd)) {
      return (pd = 1);
    }
  }

  return pd;
}

int main() {
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  while (m--) {
    char c;
    int u, v;
    cin >> u >> v >> c;
    g[u].push_back(ii(v, c));
  }

  memset(memo, -1, sizeof memo);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << (f(0, i, j, 'a') ? 'A' : 'B');
    }
    cout << '\n';
  }

  return 0;
}
