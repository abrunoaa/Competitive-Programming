#include <bits/stdc++.h>
using namespace std;

#define maxn 60

typedef long long ll;

string s;
ll memo[maxn][maxn];

ll ways(int i, int j)
{
  if (i > j) return 0;
  if (i == j) return 1;

  ll &pd = memo[i][j];
  if (pd != -1) return pd;

  pd = 0;
  if (s[i] == s[j]) pd = 1 + ways(i + 1, j - 1);
  return pd += ways(i + 1, j) + ways(i, j - 1) - ways(i + 1, j - 1);
}

int main()
{
  // freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int T;

  cin >> T;
  while (T--)
  {
    memset(memo, -1, sizeof memo);
    cin >> s;
    cout << ways(0, s.size() - 1) << '\n';
  }

  return 0;
}
