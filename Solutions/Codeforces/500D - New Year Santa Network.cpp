#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define st first
#define nd second

typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;

int n;
ll cost;
vector<ii> g[maxn], e;

ll cross(int nf){
  return 2ll * nf * (n - nf);
}

int dfs(int u, int p){
  int c = 1;

  for(ii v : g[u]){
    if(v.st != p){
      int nf = dfs(v.st, u);
      c += nf;
      e[v.nd].st = nf;
      cost += 3 * cross(nf) * e[v.nd].nd;
    }
  }

  return c;
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  cout << fixed << setprecision(9);

  cin >> n;
  for(int i = 0, u, v, w; i < n - 1; ++i){
    cin >> u >> v >> w, --u, --v;
    e.push_back(ii(0, w));
    g[u].push_back(ii(v, i));
    g[v].push_back(ii(u, i));
  }

  dfs(0, 0);
  ll total = (ll)n * (n - 1);
  // cerr << " ## " << cost << ' ' << total << endl;

  int q;
  cin >> q;
  while(q--){
    int r, w;
    cin >> r >> w, --r;
    cost -= 3 * cross(e[r].st) * (e[r].nd - w);
    e[r].nd = w;

    cout << lf(cost) / total << '\n';
  }

  return 0;
}
