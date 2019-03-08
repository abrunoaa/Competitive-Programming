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

#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)

int n, a, b;
ii st[4 * maxn];

ii operator + (ii x, ii y){
  return ii(x.st + y.st, x.nd + y.nd);
}

ii upd(int i, int x, int k = 1, int l = 1, int r = n){
  if(r < i || i < l) return st[k];
  if(l == r && l == i) return st[k] = ii(min(b, st[k].st + x), min(a, st[k].nd + x));
  return st[k] = upd(i, x, L, l, M) + upd(i, x, R, M+1, r);
}

ii qry(int i, int j, int k = 1, int l = 1, int r = n){
  if(r < i || j < l) return ii(0, 0);
  if(i <= l && r <= j) return st[k];
  return qry(i, j, L, l, M) + qry(i, j, R, M+1, r);
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int q, k;
  cin >> n >> k >> a >> b >> q;
  while(q--){
    int t;
    cin >> t;
    if(t == 1){
      int d, x;
      cin >> d >> x;
      upd(d, x);
    }
    else{
      int d;
      cin >> d;
      cout << (d == 1 ? 0 : qry(1, d - 1).st)  + (d + k > n ? 0 : qry(d + k, n).nd) << endl;
    }
  }

  return 0;
}
