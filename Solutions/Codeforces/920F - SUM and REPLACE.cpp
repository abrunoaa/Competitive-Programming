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
#define maxn 300010

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

#if !defined ONLINE_JUDGE || defined LOCAL
__attribute__((destructor)) static void destroy()
{ cerr << "\nTime elapsed: " << (lf)clock() / CLOCKS_PER_SEC << "s.\n"; }

#define db(x...) cerr << " >> [" #x "] =", db(x)
#else
#warning "JUDGE"
#define NDEBUG
#define db(...) 42
#endif

template<class t> t sq(t x) { return x * x; }

#define maxa 1000010
#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)

int n, m, a[maxn], d[maxa], p[maxn];
ll st[4 * maxn];

void build_d(){
  for(int i = 1; i < maxa; ++i){
    d[i] = 1;
  }
  for(int i = 2; i < maxa; ++i){
    if(d[i] == 1){
      ++d[i];
      for(int j = 2 * i; j < maxa; j += i){
        int e = 1;
        for(int k = j; k % i == 0; k /= i){
          ++e;
        }
        d[j] *= e;
      }
    }
  }
}

int find(int u){
  // db(u);
  assert(u <= n && u <= p[u]);
  return u == p[u] ? u : p[u] = find(p[u]);
}

ll build(int k = 1, int l = 0, int r = n - 1){
  if(l == r) return st[k] = a[l];
  return st[k] = build(L, l, M) + build(R, M+1, r);
}

ll upd(int i, int x, int k = 1, int l = 0, int r = n - 1){
  if(r < i || i < l) return st[k];
  if(l == r && l == i) return st[k] = x;
  return st[k] = upd(i, x, L, l, M) + upd(i, x, R, M+1, r);
}

ll qry(int i, int j, int k = 1, int l = 0, int r = n - 1){
  if(r < i || j < l) return 0;
  if(i <= l && r <= j) return st[k];
  return qry(i, j, L, l, M) + qry(i, j, R, M+1, r);
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  build_d();

  cin >> n >> m;
  for(int i = 0; i < maxn; ++i){
    p[i] = i;
  }
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    if(a[i] <= 2){
      p[i] = i + 1;
    }
  }

  build();
  while(m--){
    int t, l, r;
    cin >> t >> l >> r, --l, --r;
    if(t == 1){
      int j = -1;
      for(int i = find(l); i <= r; i = find(i + 1)){
        assert(i > j);
        j = i;
        a[i] = d[a[i]];
        upd(i, a[i]);
        if(i == p[i] && a[i] <= 2){
          p[i] = find(i + 1);
        }
      }
    }
    else{
      cout << qry(l, r) << endl;
    }
  }

  return 0;
}
