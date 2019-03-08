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
#define pi acosl(-1.0l)
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 100010

typedef long long ll;
typedef long double lf;
typedef pair<ll,int> ii;
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

int n, idx[maxn];
ll ft[maxn], v[maxn], c[maxn];

void upd(int i, ll x){
  for(++i; i < maxn; i += i & -i){
    ft[i] = max(ft[i], x);
  }
}

ll qry(int i){
  ll x = 0;
  for(++i; i; i -= i & -i){
    x = max(x, ft[i]);
  }
  return x;
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for(int i = 0, r, h; i < n; ++i){
    cin >> r >> h;
    c[i] = v[i] = (ll)r * r * h;
  }
  sort(c, c + n);

  for(int i = 0; i < n; ++i){
    idx[i] = lower_bound(c, c + n, v[i]) - c;
  }
  for(int i = 0; i < n; ++i){
    upd(idx[i], v[i] + qry(idx[i] - 1));
  }
  cout << setprecision(10) << fixed << pi * qry(n) << endl;

  return 0;
}
