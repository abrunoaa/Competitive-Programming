#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
__attribute__((destructor)) static void destroy() { cerr << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void db(){ cerr << '\n'; }
template<class t, class... u> void db(t x, u... y){ cerr << ' ' << x, db(y...); }
#define db(x...) cerr << "\x1b[91m >> [" #x "] =", db(x), cerr << "\x1b[0m"
#else
#warning "JUDGE"
#define assert(x) 42
#define db(...) 42
#define freopen(...) 42
#endif

#define gcd __gcd
#define popcnt __builtin_popcountll
#define ctz __builtin_ctzll
#define clz __builtin_clzll
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define eps 1e-9
#define zero(x) (abs(x) < eps)
#define pi acos(-1.0l)
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 10000
#define maxn -1

#define y0 asdf1
#define y1 asdf2
#define yn asdf3
#define j1 asdf4
#define tm asdf5
#define lr asdf6

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

typedef long long ll;
typedef unsigned long long ull;
typedef long double lf;
typedef pair<int,int> ii;
typedef triple<int,int,int> tri;
typedef vector<int> vi;
typedef vector<ii> vii;

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

struct mat{
  int m[2][2];

  int *operator [] (int p){ return m[p]; }
  const int *operator [] (int p) const{ return m[p]; }
};

mat operator * (const mat& a, const mat& b){
  mat ans;
  for(int i = 0; i < 2; ++i){
    for(int j = 0; j < 2; ++j){
      ans[i][j] = 0;
      for(int k = 0; k < 2; ++k){
        ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % mod;
      }
    }
  }
  return ans;
}

mat matpow(mat b, int e){
  mat ans = {{
    {1, 0},
    {0, 1}
  }};
  while(1){
    if(e % 2) ans = ans * b;
    if((e /= 2) == 0) return ans;
    b = b * b;
  }
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int a, b, n, k;
  cin >> a >> b >> n >> k;

  int ans;
  if(n == 1){
    ans = 2 * a;
  }
  else{
    mat m = {{
      {2 * a % mod, (b - a * a + mod) % mod},
      {1, 0}
    }};
    mat e = matpow(m, n - 1);
    ans = ((ll)e[0][0] * 2 * a + (ll)e[0][1] * 2) % mod;
  }
  if(a * a > b || (a * a < b && n % 2 == 0)){
    ans = (ans - 1 + mod) % mod;
  }
  while(--k){
    ans /= 10;
  }
  cout << ans % 10 << endl;

  return 0;
}
