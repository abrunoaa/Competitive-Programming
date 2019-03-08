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
#define maxn 200010

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

int n, m, st[4 * maxn], x[maxn], y[maxn];
bool t[maxn], lazy[4 * maxn];
vi g[maxn];

void dfs(int u = 1){
  x[u] = ++m;
  for(int v : g[u]){
    dfs(v);
  }
  y[u] = m;
}

int build(int k = 1, int l = 1, int r = n){
  if(l == r) return st[k] = t[l];
  return st[k] = build(L, l, M) + build(R, M+1, r);
}

void prop(int k, int n){
  if(lazy[k]){
    st[k] = n - st[k];
    if(n > 1){
      lazy[L] ^= 1;
      lazy[R] ^= 1;
    }
    lazy[k] = 0;
  }
}

int upd(int i, int j, int k = 1, int l = 1, int r = n){
  if(i <= l && r <= j){
    lazy[k] ^= 1;
    prop(k, r - l + 1);
    return st[k];
  }
  prop(k, r - l + 1);
  if(r < i || j < l) return st[k];
  return st[k] = upd(i, j, L, l, M) + upd(i, j, R, M+1, r);
}

int qry(int i, int j, int k = 1, int l = 1, int r = n){
  if(r < i || j < l) return 0;
  prop(k, r - l + 1);
  if(i <= l && r <= j) return st[k];
  return qry(i, j, L, l, M) + qry(i, j, R, M+1, r);
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for(int i = 2, p; i <= n; ++i){
    cin >> p;
    g[p].pb(i);
  }
  dfs();
  for(int i = 1; i <= n; ++i){
    cin >> t[x[i]];
  }
  build();

  int q;
  cin >> q;
  while(q--){
    string op;
    int v;
    cin >> op >> v;
    if(op[0] == 'p'){
      upd(x[v], y[v]);
    }
    else{
      cout << qry(x[v], y[v]) << endl;
    }
  }

  return 0;
}
