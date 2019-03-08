#include <bits/stdc++.h>
using namespace std;

#define gcd __gcd
#define popcnt __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define eps 1e-9
#define zero(x) (abs(x) < eps)
#define pi acos(-1.0l)
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 500010

typedef long long ll;
typedef long double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> tri;
typedef pair<ii,ii> qua;
typedef vector<int> vi;
typedef vector<ii> vii;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class t>
using Set = tree<t,null_type,less<t>,rb_tree_tag,tree_order_statistics_node_update>;
template<class t,class u>
using Map = tree<t,u,less<t>,rb_tree_tag,tree_order_statistics_node_update>;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << ' ' << x, db(y...); }

#ifndef ONLINE_JUDGE
__attribute__((destructor)) static void destroy()
{ cerr << "\nTime elapsed: " << (lf)clock() / CLOCKS_PER_SEC << "s.\n"; }

#define db(x...) cerr << " >> [" #x "] =", db(x)
#else
#warning "JUDGE"
#define NDEBUG
#define db(...) 42
#endif

template<class t> t sq(t x) { return x * x; }

#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)

char st[4 * maxn], lazy[4 * maxn];
int n, m, x[maxn], y[maxn], par[maxn];
vi g[maxn];

void dfs(int u, int p){
  x[u] = ++m;
  par[u] = p;
  for(int v : g[u]){
    if(v != p){
      dfs(v, u);
    }
  }
  y[u] = m;
}

bool merge(bool x, bool y){
  return x && y;
}

void prop(int k, bool child){
  auto &l = lazy[k];
  if(l != -1){
    st[k] = l;
    if(child){
      lazy[L] = lazy[R] = l;
    }
    l = -1;
  }
}

bool upd(int i, int j, bool x, int k = 1, int l = 1, int r = n){
  if(i <= l && r <= j){
    lazy[k] = x;
    prop(k, l < r);
    return st[k];
  }
  prop(k, l < r);
  if(r < i || j < l) return st[k];
  return (st[k] = merge(upd(i, j, x, L, l, M), upd(i, j, x, R, M+1, r)));
}

bool qry(int i, int j, int k = 1, int l = 1, int r = n){
  if(r < i || j < l) return 1;
  prop(k, l < r);
  if(i <= l && r <= j) return st[k];
  return qry(i, j, L, l, M) && qry(i, j, R, M+1, r);
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  memset(lazy, -1, sizeof lazy);

  cin >> n;
  for(int i = 1, a, b; i < n; ++i){
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(1, 1);

  int q;
  cin >> q;
  while(q--){
    int c, v;
    cin >> c >> v;
    if(c == 1){
      if(qry(x[v], y[v]) == 0){
        int u = par[v];
        upd(x[u], x[u], 0);
      }
      upd(x[v], y[v], 1);
    }
    else if(c == 2){
      upd(x[v], x[v], 0);
    }
    else{
      cout << qry(x[v], y[v]) << endl;
    }
  }

  return 0;
}
