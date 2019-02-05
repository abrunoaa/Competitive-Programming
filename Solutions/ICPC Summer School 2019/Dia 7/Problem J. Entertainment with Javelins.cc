#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
__attribute__((destructor)) static void __destroy__() { cerr << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void debug(){}
template<class t, class... u> void debug(t x, u ...y){ cerr << ' ' << x, debug(y...); }
#define debug(x...) cerr << "\x1b[91m[" #x "] =", debug(x), cerr << "\x1b[0m\n"
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

#define gcd __gcd
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define zero(x) (abs(x) < eps)
#define pi acos(-1.0l)
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f

#define popcnt __builtin_popcountll
#define ctz __builtin_ctzll
// int clz(int x){ return __builtin_clz(x); }
// int clz(long x){ return __builtin_clzl(x); }
// int clz(long long x){ return __builtin_clzll(x); }

#define y0 asdf1
#define y1 asdf2
#define yn asdf3
#define j1 asdf4
#define tm asdf5
#define lr asdf6
#define div asdf7

template<class t1, class t2, class t3> struct triple{
  t1 st; t2 nd; t3 rd;

  triple() : st(), nd(), rd() {}
  triple(const t1& a, const t2& b, const t3& c) : st(a), nd(b), rd(c) {}

  bool operator == (const triple& t) const { return st == t.st && nd == t.nd && rd == t.rd; }
  bool operator != (const triple& t) const { return !(*this == t); }
  bool operator <  (const triple& t) const { return st != t.st ? st < t.st : nd != t.nd ? nd < t.nd : rd < t.rd; }
  bool operator <= (const triple& t) const { return !(t < *this); }
  bool operator >  (const triple& t) const { return t < *this; }
  bool operator >= (const triple& t) const { return !(*this < t); }
};

template<class t> using tset = tree<t,null_type,less<t>,rb_tree_tag,tree_order_statistics_node_update>;
template<class t,class u> using tmap = tree<t,u,less<t>,rb_tree_tag,tree_order_statistics_node_update>;
template<class t,class u = greater<t>> using pqueue = priority_queue<t,vector<t>,u>;

template<class t1, class t2> ostream& operator << (ostream& out, const pair<t1,t2>& x){ return out << '(' << x.st << ", " << x.nd << ')'; }
template<class t1, class t2, class t3> ostream& operator << (ostream& out, const triple<t1,t2,t3>& x){ return out << '(' << x.st << ", " << x.nd << ", " << x.rd << ')'; }

#define PRINT_DS bool flag = 0; out << '['; for(auto& x : ds){ if(flag) out << ", "; else flag = 1; out << x; } return out << ']'
template<class t> ostream& operator << (ostream& out, const vector<t>& ds){ PRINT_DS; }
template<class t> ostream& operator << (ostream& out, const set<t>& ds){ PRINT_DS; }
template<class t> ostream& operator << (ostream& out, const tset<t>& ds){ PRINT_DS; }
template<class t1, class t2> ostream& operator << (ostream& out, const map<t1,t2>& ds){ PRINT_DS; }
template<class t1, class t2> ostream& operator << (ostream& out, const tmap<t1,t2>& ds){ PRINT_DS; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double lf;
typedef pair<ll,int> ii;
typedef triple<int,int,int> tri;
typedef vector<int> vi;
typedef vector<ii> vii;

#define eps 1e-9
#define mod 1000000007
#define maxn 2003

int d[maxn], s[maxn], c[maxn], best[maxn][maxn];
ii ft[maxn][maxn];
vi ans;

ii qry(ii* ft, int i){
  ii r(infl, 0);
  for(; i < maxn; i += i & -i){
    r = min(r, ft[i]);
  }
  return r;
}

void upd(ii* ft, int i, ii x){
  for(; i; i -= i & -i){
    ft[i] = min(ft[i], x);
  }
}

void rec(int i, int j){
  if(i == 0) return;
  rec(best[i][j], j - s[i]);
  ans.pb(i);
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  memset(ft, inf, sizeof ft);
  upd(ft[0], maxn - 1, ii(0, 0));

  int n, m;
  cin >> n >> m;

  map<int,int> mp;
  for(int i = 1; i <= n; ++i){
    cin >> d[i] >> s[i] >> c[i];
    mp[d[i]];
  }
  int cnt = 1;
  for(auto& x : mp){
    x.nd = cnt++;
  }
  for(int i = 1; i <= n; ++i){
    d[i] = mp[d[i]];
  }

  for(int i = 1; i <= n; ++i){
    for(int j = m; j; --j){
      ii q = qry(ft[max(0, j - s[i])], d[i]);
      ll r = q.st + c[i];
      best[i][j] = q.nd;
      upd(ft[j], d[i], ii(r, i));
    }
  }

  ii r = qry(ft[m], 1);
  if(r.st == infl){
    cout << "-1\n";
    return 0;
  }
  rec(r.nd, m);
  cout << r.st << ' ' << ans.size() << endl;
  for(int x : ans) cout << x << ' ';
  cout << endl;

  return 0;
}
