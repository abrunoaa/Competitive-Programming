#include <iostream>
#include <vector>
using namespace std;

#define maxn int(1e5 + 3)
#define infl 0x3f3f3f3f3f3f3f3f

typedef long long ll;

int a[maxn];
ll dp[maxn][2][2];
vector<int> g[maxn];

void setMax(ll* v, ll x){
  if(x > v[0]){
    v[1] = v[0];
    v[0] = x;
  }
  else if(x > v[1]){
    v[1] = x;
  }
}

void dfs(int u, int p){
  dp[u][0][0] = 0;
  dp[u][0][1] = -infl;
  dp[u][1][0] = a[u];
  dp[u][1][1] = -infl;
  for(int v : g[u]) if(v != p){
    dfs(v, u);
    ll x = dp[v][0][0];
    ll y = dp[v][1][0];
    setMax(dp[u][0], max(x, y - a[u]));
    setMax(dp[u][1], max(y, x + a[u]));
  }
}

void dfs2(ll x, ll y, int u, int p){
  setMax(dp[u][0], max(x, y - a[u]));
  setMax(dp[u][1], max(y, x + a[u]));
  for(int v : g[u]) if(v != p){
    x = dp[v][0][0];
    y = dp[v][1][0];
    dfs2(dp[u][0][(dp[u][0][0] == max(x, y - a[u]))],
      dp[u][1][(dp[u][1][0] == max(y, x + a[u]))],
      v,
      u);
  }
}

int main(){
  assert(freopen("in","r",stdin));
	cin.sync_with_stdio(0), cin.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; ++i){
	  cin >> a[i];
	}
	for(int i = 1; i < n; ++i){
	  int u, v;
	  g[u].push_back(v);
	  g[v].push_back(u);
	}
	dfs(0, -1);
	dfs2(-infl, -infl, 0, -1);
	while(q--){
	  int i;
	  cin >> i;
	  cout << dp[i][0][0] << '\n';
	}
	return 0;
}