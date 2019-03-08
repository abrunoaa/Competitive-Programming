#include <bits/stdc++.h>
using namespace std;

#define MAX 10010

int n;
int p[MAX], c[MAX], cor[MAX] = {};
vector<vector<int>> adj;

int pinta(int u = 0, int pai = 0)
{
  int ans = 0;
  cor[u] = cor[pai];
  if (cor[u] != c[u])
  {
    cor[u] = c[u];
    ++ans;
  }

  for (int x : adj[u])
    ans += pinta(x, u);

  return ans;
}

int main()
{
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;

  p[0] = 0;
  adj.assign(n, vector<int>());
  for (int i = 1; i < n; ++i) cin >> p[i], --p[i], adj[p[i]].push_back(i);
  for (int i = 0; i < n; ++i) cin >> c[i];

  cor[0] = c[0];

  cout << pinta() + 1 << '\n';

  return 0;
}
