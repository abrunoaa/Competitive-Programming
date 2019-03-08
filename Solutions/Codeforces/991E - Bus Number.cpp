#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
__attribute__((destructor)) static void destroy() { cerr << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void db(){ cerr << '\n'; }
template<class t, class... u> void db(t x, u... y){ cerr << ' ' << x, db(y...); }

#define db(x...) cerr << " >> [" #x "] =", db(x)
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
#define mod 1000000007
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

int m, rem[10];
ll n, fat[25], memo[10][20];
vi f(10, 0);

ll comb(int n, int r){
  return fat[n] / (fat[r] * fat[n - r]);
}

ll bus(int d, int m){
  if(d == 10) return (m == 0);
  if(f[d] == 0) return bus(d + 1, m);

  ll &pd = memo[d][m];
  if(pd != -1) return pd;

  int up = min(f[d], m - rem[d]);
  pd = 0;
  for(int r = 1; r <= up; ++r){
    pd += comb(m, r) * bus(d + 1, m - r);
  }
  return pd;
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  fat[0] = 1;
  for(int i = 1; i < 25; ++i){
    fat[i] = (ll)i * fat[i - 1];
  }

  cin >> n;
  int diff = 0, tot = 0;
  for(ll k = n; k; k /= 10){
    if(++f[k % 10] == 1){
      ++diff;
    }
    ++tot;
  }

  rem[9] = 0;
  for(int i = 8; i >= 0; --i){
    rem[i] = rem[i + 1] + (f[i + 1] > 0);
  }

  ll ans = 0;
  for(m = diff; m <= tot; ++m){
    if(f[0] > 0){
      int up = min(f[0], m - rem[0]);
      for(int r = 1; r <= up; ++r){
        memset(memo, -1, sizeof memo);
        ans += comb(m - 1, r) * bus(1, m - r);
      }
    }
    else{
      memset(memo, -1, sizeof memo);
      ans += bus(1, m);
    }
  }
  cout << ans << endl;

  return 0;
}
