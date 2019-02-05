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
#define maxn 610

int n, m, x[maxn][maxn];
int c[maxn][maxn], len[maxn][maxn];
int maxComp, p[maxn], s[maxn];
ii connect[maxn];

// union find
void build(){
  maxComp = 1;
  for(int i = 0; i < maxn; ++i){
    p[i] = i;
    s[i] = 1;
  }
}

int find(int u){
  return (u == p[u] ? u : p[u] = find(p[u]));
}

void unite(int u, int v){
  u = find(u);
  v = find(v);
  if(u != v){
    p[u] = v;
    s[v] += s[u];
    maxComp = max(maxComp, s[v]);
  }
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  while(cin >> n >> m && (n || m)){
    int ans = 0;
    for(int i = 0; i < n; ++i){
      for(int j = 0, k = 0; j < m; ++j){
        cin >> x[i][j];
        if(j && x[i][j] <= x[i][j - 1]){  // quebrou ordenação
          ++k;  // novo grupo
        }
        c[i][j] = k;  // trecho ordenado
      }
      for(int j = 0; j < m; ++j){ // tam máx que está ordenado na linha i a partir de j
        len[i][j] = upper_bound(c[i] + j, c[i] + m, c[i][j]) - c[i] - j;
        ans = max(ans, len[i][j]);
      }
    }

    for(int j = 0; j < m; ++j){
      for(int i = 0; i < n - 1; ++i){ // qto pode ligar da linha i com a linha i + 1?
        int k = min(len[i + 1][j], (int)(lower_bound(x[i] + j, x[i] + j + len[i][j], x[i + 1][j]) - x[i] - j));
        connect[i] = ii(k, i);
      }
      connect[n - 1] = ii(0, 0);
      sort(connect, connect + n - 1, greater<ii>());

      build();
      for(int k = connect[0].st, i = 0; k > 0; --k){  // varia o tam das colunas
        for(; connect[i].st == k; ++i){ // vai unindo as linhas
          unite(connect[i].nd, connect[i].nd + 1);
        }
        ans = max(ans, k * maxComp);  // tam da coluna * maior qtd de linhas conectadas
      }
    }

    cout << ans << endl;
  }

  return 0;
}
