#include <bits/stdc++.h>
using namespace std;

#define maxn 1010
#define inf 0x3f3f3f3f

int sabor[maxn], memo[maxn][maxn];

int mentos(int i, int j)
{
  if (i > j) return 0;
  if (i == j) return 1;

  int &pd = memo[i][j];
  if (pd != inf) return pd;

  if (sabor[i] == sabor[j]) pd = 1 + mentos(i + 1, j - 1);

  int x = 1 + min(mentos(i + 1, j), mentos(i, j - 1));
  return pd = min(pd, x);
}

int main()
{
  // freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int T, N, cs = 0;

  cin >> T;
  while (T--)
  {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> sabor[i];

    memset(memo, inf, sizeof memo);
    cout << "Caso #" << ++cs << ": " << mentos(0, N - 1) << '\n';
  }

  return 0;
}
