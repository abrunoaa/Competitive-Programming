#include <bits/stdc++.h>
using namespace std;

#define maxn 200010

int n, c;
int p[maxn], memo[maxn][2];

int lucro (int i, bool tem_acao) {
  if (i == n - 1) { return (tem_acao ? p[i] : 0); }

  int &pd = memo[i][tem_acao];
  if (pd != -1) { return pd; }

  if (tem_acao) { return pd = max(lucro(i + 1, 1), lucro(i + 1, 0) + p[i]); }
  return pd = max(lucro(i + 1, 0), lucro(i + 1, 1) - p[i] - c);
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> c;
  for (int i = 0; i < n; ++i) { cin >> p[i]; }

  memset(memo, -1, sizeof memo);
  cout << lucro(0, 0) << '\n';

  return 0;
}
