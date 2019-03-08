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

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Set;
typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update> Map;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << ' ' << x, db(y...); }

#ifdef LOCAL
__attribute__((destructor)) static void destroy()
{ cerr << "\nTime elapsed: " << (lf)clock() / CLOCKS_PER_SEC << "s.\n"; }

#define db(x...) cerr << " >> [" #x "] =", db(x)
#else
#warning "JUDGE"
#define NDEBUG
#define db(...) 42
#endif

#define L (k * 2)
#define R (L + 1)
#define M ((l + r) / 2)

int n, m, l[maxn], r[maxn], q[maxn], st[4 * maxn], ans[maxn], s[maxn];

int build(int k = 1, int l = 1, int r = n){
  if(l == r) return st[k] = ans[l];
  return st[k] = build(L, l, M) & build(R, M+1, r);
}

int qry(int i, int j, int k = 1, int l = 1, int r = n){
  if(r < i || j < l) return (1 << 30) - 1;
  if(i <= l && r <= j) return st[k];
  return qry(i, j, L, l, M) & qry(i, j, R, M+1, r);
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= m; ++i){
    cin >> l[i] >> r[i] >> q[i];
  }
  for(int bit = 0; bit < 30; ++bit){
    memset(s, 0, sizeof s);
    for(int i = 1; i <= m; ++i){
      if((1 << bit) & q[i]){
        ++s[l[i]];
        --s[r[i] + 1];
      }
    }
    for(int i = 1; i <= n; ++i){
      s[i] += s[i - 1];
      if(s[i]){
        ans[i] |= 1 << bit;
      }
    }
  }
  build();
  for(int i = 1; i <= m; ++i){
    if(qry(l[i], r[i]) != q[i]){
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for(int i = 1; i <= n; ++i){
    cout << ans[i] << ' ';
  }
  cout << endl;

  return 0;
}
