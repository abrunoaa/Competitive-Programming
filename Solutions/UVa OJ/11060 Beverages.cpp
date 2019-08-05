#include <bits/stdc++.h>
using namespace std;

vector < bool > vis;
vector < int > ts, ind;
vector < vector < int > > adj;

/*
void dfs(int u)
{
  vis[u] = 1;
  int size = adj[u].size();
  for (int i = -1; ++i < size; )
    if (!vis[adj[u][i]])
      dfs(adj[u][i]);

  ts.push_back(u);
}
*/

int main() {
  register int i, u;
  int m, n, c = 0;
  char name[105], name2[105], names[105][105];

  map < string, int > mp;

  queue < int > q;

  while (scanf("%d", &n) > 0) {
    vis.assign(105, 0);
    ind.assign(105, 0);
    adj.assign(105, vector < int >());

    for (i = -1; ++i < n; ) {
      scanf(" %s", name);
      mp[name] = i;
      strcpy(names[i], name);
    }

    scanf("%d", &m);
    for (i = m; i--; ) {
      scanf(" %s %s", name, name2);
      adj[mp[name]].push_back((m = mp[name2]));
      ++ind[m];
    }

    for (i = -1; ++i < n; )
      if (!ind[i]) {
        q.push(i);
      }

    while (!q.empty()) {
      u = q.front();
      q.pop();

      ts.push_back(u);
      for (i = adj[u].size(); i--; )
        if (!vis[adj[u][i]] && !--ind[adj[u][i]]) {
          q.push(adj[u][i]);
        }
      vis[u] = 1;
    }

    /*
    for (i = -1; ++i < n; )
      if (!vis[i])
        dfs(i);
    */
    printf("Case #%d: Dilbert should drink beverages in this order:", ++c);
    for (i = -1; ++i < n; ) {
      printf(" %s", names[ts[i]]);
    }
    printf("\n");

    mp.clear();
    vis.clear();
    ind.clear();
    adj.clear();
  }

  return 0;
}
