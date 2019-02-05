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
typedef triple<int,int,int> tri;
typedef vector<int> vi;
typedef vector<ii> vii;

#define eps 1e-9
#define mod 1000000007
#define maxn 100003

int n, v[maxn], l[maxn], r[maxn];
vi f[maxn];

void calcRange(){
  vii s = { ii(inf, -1) };
  for(int i = 0; i < n; ++i){
    while(v[i] >= s.back().st){
      s.pop_back();
    }
    l[i] = s.back().nd + 1;
    s.pb(ii(v[i], i));
  }
  s = { ii(inf, n) };
  for(int i = n - 1; i >= 0; --i){
    while(v[i] >= s.back().st){
      s.pop_back();
    }
    r[i] = s.back().nd - 1;
    s.pb(ii(v[i], i));
  }
}

int st[maxn][(int)log2(maxn) + 1];  // sparse table

// constrói a tabela em O(n lg n)
void build(){
  for(int i = 0; i < n; ++i)
    st[i][0] = v[i];
  for(int j = 1; (1 << j) <= n; ++j)
    for(int i = 0; i + (1 << j) <= n; ++i)
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
} // ==> pode armazenar a posição ao invés do valor

// consulta O(1)
int qry(int i, int j){
  int k = log2(j - i + 1) + 1e-9;
  return max(st[i][k], st[j - (1 << k) + 1][k]);
}

int bruto(){
  int ans = 0;
  build();
  for(int i = 0; i < n; ++i)
    for(int j = i; j < n; ++j)
      for(int k = j + 1; k < n; ++k)
        for(int l = k; l < n; ++l)
          if(qry(i, j) == qry(k, l))
            ++ans;
  return ans;
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

while(1){
  cin >> n;
  n = 3;
  map<int,int> mp;
  for(int i = 0; i < n; ++i){
    cin >> v[i];
    v[i] = rand() % 5 + 1;
    mp[v[i]];
  }
  int m = 0;
  for(auto& x : mp){
    x.nd = m++;
  }
  for(auto& x : f){
    x.clear();
  }
  for(int i = 0; i < n; ++i){
    v[i] = mp[v[i]];
    f[v[i]].pb(i);
  }

  calcRange();
  debug(vi(v, v + n));
  debug(vi(l, l + n));
  debug(vi(r, r + n));
  int ans = 0;
  for(int x = 0; x < m; ++x){
    vi v;
    auto& f = ::f[x];
    debug(x, f);
    for(int i = 0, j; i < (int)f.size(); i = j){
      for(j = i + 1; j < (int)f.size() && l[f[i]] == l[f[j]]; ++j);
      int t = (ll)(f[i] - l[f[i]] + 1) * (r[f[i]] - f[i] + 1) % mod;
      vi a = { f[i] - l[f[i]] + 1 };
      for(int k = i + 1; k < j; ++k){
        int d = f[k] - f[k - 1];
        a.pb(((ll)a.back() * d + f[k] - l[f[k]] + 1) % mod);
        t = (t + (ll)d * (r[f[k]] - f[k] + 1)) % mod;
      }
      int b = r[f[j - 1]] - f[j - 1] + 1;
      debug(f[i]);
      for(int k = j - 2; k >= i; --k){
        int d = f[k + 1] - f[k];
        debug(b, d);
        ans = (ans + (ll)(d + 1) * d / 2 % mod * a[k - i] % mod * b) % mod;
        b = ((ll)b * d + r[f[k]] - f[k] + 1) % mod;
      }
      debug(i, j, a, b, t, ans);
      v.pb(t);
    }
    debug(v);
    for(int i = v.size() - 2; i >= 0; --i){
      ans = (ans + (ll)v[i] * v[i + 1]) % mod;
      v[i] = (v[i] + v[i + 1]) % mod;
    }
    debug(x, ans);
  }
  int b = bruto();
  debug(ans, b);
  cout << ans << '\n';
  assert(ans == b);
}
  return 0;
}
