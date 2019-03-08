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
#define maxn ((1 << 17) + 10)

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

#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)

int n, m, v[maxn];
ii st[4 * maxn];

ii merge(ii x, ii y){
  assert(x.nd == y.nd);
  return ii(x.nd ? x.st ^ y.st : x.st | y.st, !x.nd);
}

ii build(int k = 1, int l = 0, int r = (1 << n) - 1){
  if(l == r) return st[k] = ii(v[l], 0);
  return st[k] = merge(build(L, l, M), build(R, M+1, r));
}

ii upd(int p, int x, int k = 1, int l = 0, int r = (1 << n) - 1){
  if(p < l || r < p) return st[k];
  if(l == r) return st[k] = ii(x, 0);
  return st[k] = merge(upd(p, x, L, l, M), upd(p, x, R, M+1, r));
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < (1 << n); ++i){
    cin >> v[i];
  }
  build();
  while(m--){
    int p, b;
    cin >> p >> b, --p;
    upd(p, b);
    cout << st[1].st << endl;
  }

  return 0;
}
