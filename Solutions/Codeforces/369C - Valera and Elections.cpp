#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define pb push_back

typedef pair<int,int> ii;
typedef vector<ii> vii;

int n;
vector<int> ans;
vector<vii> adj;

bool dfs (int u, int p, bool def)
{
  bool child = 0;
  for (ii v : adj[u])
    if (v.fst != p && dfs(v.fst, u, v.snd == 2))
      child = 1;

  if (!child && def)
  {
    ans.pb(u);
    return 1;
  }

  return child;
}

int main()
{
  // freopen("cin", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int i, u, v, t;

  while (cin >> n)
  {
    adj.assign(n, vii());
    ans.clear();

    for (i = 0; i < n - 1; ++i)
    {
      cin >> u >> v >> t, --u, --v;
      adj[u].pb(ii(v, t));
      adj[v].pb(ii(u, t));
    }

    dfs(0, 0, 0);

    cout << ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); ++i)
    {
      if (i) cout << ' ';
      cout << ans[i] + 1;
    }
    cout << '\n';
  }

  return 0;
}

