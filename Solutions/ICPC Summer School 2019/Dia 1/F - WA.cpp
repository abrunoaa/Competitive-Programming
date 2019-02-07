/// ************ WA ************

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
#define clz __builtin_clzll
#define lg(x) (63 - clz(x))

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
typedef triple<int,int,int> tri;
typedef vector<int> vi;
typedef vector<ii> vii;

template<class T> T sq(T x){ return x * x; }

#define eps 1e-9
#define mod 1000000007
#define maxn 21

int n;
int lin, col, memo[maxn][maxn][1 << maxn];

int f(int i, int j, int m){
  // debug(i, j, m, memo[i][j][m]);
  // assert(m != 12);
  if(j == col - 1) return 1;
  int &pd = memo[i][j][m];
  if(pd != -1) return pd;
  if(i == lin - 1) return pd = f(0, j + 1, (m << 1) & ((1 << (n + 1)) - 1));
  pd = f(i + 1, j, m & ~(1 << (i + 1)));
  if(!(m & (7 << i))) pd = (pd + f(i + 1, j, m | (7 << i))) % mod;
  // debug(i, j, m, pd);
  return pd;
}

int solve(int n){
  ::n = n;
  int ans = 0;

  memset(memo, -1, sizeof memo);
  lin = col = n;
  ans = (ans + f(0, 0, 0)) % mod;
  debug(f(0, 0, 0));

  memset(memo, -1, sizeof memo);
  lin = col = (n + 1) / 2;
  ans = (ans + 2ll * f(0, 0, 0)) % mod; // faltando alguns
  debug(f(0, 0, 0));

  memset(memo, -1, sizeof memo);
  lin = (n + 1) / 2;
  col = n;
  ans = (ans + f(0, 0, 0)) % mod; // faltando alguns
  debug(f(0, 0, 0));

  debug(ans);
  assert(ans % 4 == 0);
  return ans * 250000002ll % mod; // 4^-1 = 250000002
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  cout << solve(n) << endl;

  return 0;
}
