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
int clz(int x){ return __builtin_clz(x); }
int clz(long x){ return __builtin_clzl(x); }
int clz(long long x){ return __builtin_clzll(x); }

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
typedef pair<int,int> ii;
typedef triple<ull,ull,ull> tri;
typedef vector<int> vi;
typedef vector<ii> vii;

#define eps 1e-9
#define mod 1000000007
#define maxn ((1 << 16) + 10)

int fat[25];
ull sum[maxn];
tri memo[maxn];

tri dfs(int u){
  tri& pd = memo[u];
  if(pd.st != -1ull) return pd;

  pd = tri(infl, 0, 0);
  int f = fat[popcnt(u) - 1];
  for(int k = 0; k < 16; ++k){
    if(u & (1 << k)){
      int v = u ^ (1 << k);
      tri t = dfs(v);
      pd.st = min(pd.st, t.st + sum[v]);
      pd.nd = max(pd.nd, t.nd + sum[v]);
      pd.rd = (pd.rd + t.rd + sum[v] % mod * f) % mod;
    }
  }

  return pd;
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> hex, cerr << hex, cout << hex;

  fat[0] = 1;
  for(int i = 1; i < 25; ++i){
    fat[i] = (ull)i * fat[i - 1] % mod;
  }

  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    ull x;
    cin >> x;
    for(int k = 0; k < (1 << 16); ++k){
      ull y = 0;
      for(int j = 8; j >= 0; --j){
        int d = 0xf & (x >> (4 * j));
        if(k & (1 << d)){
          y = (y << 4) | d;
        }
      }
      sum[k] += y;
    }
  }

  memset(memo, -1, sizeof memo);
  memo[0] = tri(0, 0, 0);
  tri ans = dfs((1 << 16) - 1);
  cout << ans.st << ' ' << ans.nd << ' ' << ans.rd << endl;

  return 0;
}
