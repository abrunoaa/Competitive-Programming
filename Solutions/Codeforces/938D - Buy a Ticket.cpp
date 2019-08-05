#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

#define maxn 200005

vector<ii> g[maxn];

ll dp[maxn];

int main() {
  //~ freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;

    g[a].push_back(ii(b, 2 * c));
    g[b].push_back(ii(a, 2 * c));
  }

  for (int i = 1; i <= n; i++) {
    cin >> dp[i];
  }


  priority_queue<ii> pq;
  for (int i = 1; i <= n; i++) {
    pq.push(ii(-dp[i], i));
  }

  while (!pq.empty()) {
    int u = pq.top().second;
    auto d = -pq.top().first;
    pq.pop();

    if (d > dp[u]) { continue; }

    for (int i = 0; i < (int)g[u].size(); i++) {
      int v = g[u][i].first;
      ll w = g[u][i].second;

      if (dp[v] > dp[u] + w) {
        dp[v] = dp[u] + w;
        pq.push(ii(-dp[v], v));
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << dp[i] << ' ';
  }
  cout << '\n';
}
