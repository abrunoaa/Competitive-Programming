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
#define pi M_PIl
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 100010

typedef long long ll;
typedef long double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> tri;
typedef pair<ii,ii> qua;
typedef vector<int> vi;
typedef vector<ii> vii;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Set;
typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update> Map;

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

#define maxb 20
#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)

struct no{
  ll ans;
  int n, lazy, bit[maxb];
};

int n, a[maxn];
no st[4 * maxn];

no merge(const no& x, const no& y){
  no z = { x.ans + y.ans, x.n + y.n, 0, {} };
  for(int b = 0; b < maxb; ++b){
    z.bit[b] = x.bit[b] + y.bit[b];
  }
  return z;
}

void prop(int k){
  int &lazy = st[k].lazy;
  if(lazy){
    if(R < 4 * maxn){
      st[L].lazy ^= lazy;
      st[R].lazy ^= lazy;
    }
    for(int b = 0; b < maxb; ++b){
      if(lazy & (1 << b)){
        int n1 = st[k].bit[b];
        int n2 = st[k].n - n1;
        st[k].bit[b] = n2;
        st[k].ans += (ll)(n2 - n1) * (1 << b);
      }
    }
    lazy = 0;
  }
}

no build(int k = 1, int l = 1, int r = n){
  if(l == r){
    st[k].ans = a[l];
    st[k].lazy = 0;
    st[k].n = 1;
    for(int b = 0, x = a[l]; b < maxb; ++b){
      st[k].bit[b] = ((x >> b) & 1);
    }
    return st[k];
  }
  return st[k] = merge(build(L, l, M), build(R, M+1, r));
}

no upd(int i, int j, int x, int k = 1, int l = 1, int r = n){
  prop(k);
  if(j < l || r < i) return st[k];
  if(i <= l && r <= j){
    st[k].lazy = x;
    prop(k);
    return st[k];
  }
  return st[k] = merge(upd(i, j, x, L, l, M), upd(i, j, x, R, M+1, r));
}

ll qry(int i, int j, int k = 1, int l = 1, int r = n){
  if(j < l || r < i) return 0;
  prop(k);
  if(i <= l && r <= j) return st[k].ans;
  return qry(i, j, L, l, M) + qry(i, j, R, M+1, r);
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }
  build();

  int m;
  cin >> m;
  while(m--){
    int t, l, r;
    cin >> t >> l >> r;
    if(t == 1){
      cout << qry(l, r) << endl;
    }
    else{
      int x;
      cin >> x;
      upd(l, r, x);
    }
  }

  return 0;
}
