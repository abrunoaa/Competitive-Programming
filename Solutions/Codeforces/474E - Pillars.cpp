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

int p[maxn];
ll h[maxn];
ii gft[maxn], lft[maxn];

void gupd(int i, ii x){
  for(; i; i -= i & -i){
    gft[i] = max(gft[i], x);
  }
}

ii gqry(int i){
  ii s(0, inf);
  for(; i < maxn; i += i & -i){
    s = max(s, gft[i]);
  }
  return s;
}

void lupd(int i, ii x){
  for(; i < maxn; i += i & -i){
    lft[i] = max(lft[i], x);
  }
}

ii lqry(int i){
  ii s(0, inf);
  for(; i; i -= i & -i){
    s = max(s, lft[i]);
  }
  return s;
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  for(int i = 0; i < maxn; ++i){
    lft[i] = gft[i] = ii(0, inf);
  }

  int n, d;
  cin >> n >> d;

  map<ll,int> mp;
  for(int i = 1; i <= n; ++i){
    cin >> h[i];
    mp[h[i]];
  }
  mp[infl];

  int m = 0;
  for(auto &p : mp){
    p.nd = ++m;
  }

  int ans = 0, ansbeg = inf;
  for(int i = n; i; --i){
    auto it = mp.upper_bound(h[i] - d);
    ii g = gqry(mp.lower_bound(h[i] + d)->nd);
    ii l = (it == mp.begin() ? ii(-1, -1) : lqry((--it)->nd));
    ii k = max(g, l);

    ++k.st;
    p[i] = k.nd;
    k.nd = i;
    gupd(mp[h[i]], k);
    lupd(mp[h[i]], k);

    if(k.st > ans){
      ans = k.st;
      ansbeg = i;
    }
  }

  cout << ans << endl;
  for(int i = ansbeg; i <= n; i = p[i]){
    cout << i << ' ';
  }
  cout << endl;

  return 0;
}
