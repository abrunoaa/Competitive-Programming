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

typedef long long ll;
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
#define NDEBUG
#define db(...) 42
#endif

template<class t> t sq(t x) { return x * x; }

#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)

struct ant{
  int g, m, n;
};

int n, s[maxn];
ant st[4 * maxn];

ant merge(ant x, ant y){
  if(x.n == -1) return y;
  if(y.n == -1) return x;
  return ant{ gcd(x.g, y.g), min(x.m, y.m), (x.m == y.m ? x.n + y.n : x.m < y.m ? x.n : y.n) };
}

ant build(int k = 1, int l = 0, int r = n - 1){
  if(l == r) return st[k] = ant{ s[l], s[l], 1 };
  return st[k] = merge(build(L, l, M), build(R, M+1, r));
}

ant qry(int i, int j, int k = 1, int l = 0, int r = n - 1){
  if(r < i || j < l) return ant{ -1, -1, -1 };
  if(i <= l && r <= j) return st[k];
  return merge(qry(i, j, L, l, M), qry(i, j, R, M+1, r));
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> s[i];
  }
  build();

  int m;
  cin >> m;
  while(m--){
    int l, r;
    cin >> l >> r, --l, --r;
    ant q = qry(l, r);
    cout << r - l + 1 - (q.g == q.m ? q.n : 0) << endl;
  }

  return 0;
}
