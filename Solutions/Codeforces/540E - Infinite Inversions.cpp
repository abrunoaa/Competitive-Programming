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

#define y0 asdf1
#define y1 asdf2
#define yn asdf3
#define j1 asdf4
#define tm asdf5
#define lr asdf6

typedef long long ll;
typedef unsigned long long ull;
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
#define assert(x) 42
#define db(...) 42
#define freopen(...) 42
#endif

template<class t> t sq(t x) { return x * x; }

int n, a[maxn], b[maxn], s[2 * maxn], gap[2 * maxn];
ll ft[2 * maxn];

void upd(int i, ll x){
  for(; i < 2 * maxn; i += i & -i){
    ft[i] += x;
  }
}

ll qry(int i){
  ll s = 0;
  for(; i; i -= i & -i){
    s += ft[i];
  }
  return s;
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  map<int,int> mp;

  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i] >> b[i];
    mp[a[i]];
    mp[b[i]];
  }
  int last = 0, m = 0;
  for(auto &p : mp){
    p.nd = ++m;
    gap[m] = p.st - (last + 1);
    last = p.st;
  }
  for(int i = 1; i <= m; ++i){
    s[i] = i;
  }
  for(int i = 0; i < n; ++i){
    swap(s[mp[a[i]]], s[mp[b[i]]]);
  }

  ll ans = 0;
  for(int i = m; i; --i){
    ans += qry(s[i]);
    upd(s[i], +1);
    if(gap[i]){
      ans += gap[i] * qry(i - 1);;
      upd(i, gap[i]);
    }
  }
  cout << ans << endl;

  return 0;
}
