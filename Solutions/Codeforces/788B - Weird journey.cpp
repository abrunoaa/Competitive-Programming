#include <bits/stdc++.h>
using namespace std;

#define gcd __gcd
#define popcnt __builtin_popcount
#define st first
#define nd second
#define pb push_back
#define eps 1e-9
#define zero(x) (abs(x) < eps)
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 1000010

typedef long long ll;
typedef long double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> tri;
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Set;
typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update> Map;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << ' ' << x, db(y...); }

#ifdef LOCAL
__attribute__((destructor))
static void destroy(){
  cerr << "\nTime elapsed: " << (lf)clock() / CLOCKS_PER_SEC << "s.\n";
}

#define db(x...) cerr << " >> [" #x "] = ", db(x)
#else
#warning "JUDGE"
#define db(...) 42
#endif

bool vis[maxn], loop[maxn];
int n, m;
vector<int> g[maxn];

int dfs(int u){
  vis[u] = 1;

  int k = g[u].size();
  for(int v : g[u])
    if(!vis[v])
      k += dfs(v);

  return k;
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  if(m == 1){
    cout << "0\n";
    return 0;
  }

  ll k = 0;
  for(int i = 0, u, v; i < m; ++i){
    cin >> u >> v;
    g[u].pb(v);

    if(u == v){
      loop[u] = 1;
    }
    else{
      g[v].pb(u);
    }
  }

  bool flag = 0;
  for(int u = 1; u <= n; ++u){
    if(!vis[u] && dfs(u) > 0){
      if(flag){
        cout << "0\n";
        return 0;
      }
      flag = 1;
    }

    ll x = g[u].size();
    if(loop[u]){
      k += --m;
      --x;
    }
    db(u, loop[u], x, m, k);
    k += x * (x - 1) / 2;
  }

  cout << k << '\n';
  return 0;
}
