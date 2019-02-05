#include <bits/stdc++.h>
using namespace std;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << " " << x, db(y...); }

#define gcd __gcd
#define st first
#define nd second
#define pb push_back
#define eps 1e-9
#define zero(x) (abs(x) < eps)
#define inf 0x3f3f3f3f
#define mod 1000000009
#define maxn 50010

typedef long long ll;
typedef long double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> tri;
typedef vector<int> vi;
typedef vector<ii> vii;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Set;
typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update> Map;

#ifndef ONLINE_JUDGE
struct _ { _() { assert(freopen("in","r",stdin)); } } _;
#define db(x...) cerr << " >>", db(x)
#else
#warning "ONLINE_JUDGE"
struct _ { _() { cin.sync_with_stdio(0), cin.tie(0); } } _;
#define db(x...)
#endif

int n, q, minx[maxn], p[maxn], bit[maxn], ans[100010];
bool vis[maxn];
vector<tri> qry;

int buildmin(int x){
  int &m = minx[x];
  if(m) return m;
  
  if(vis[x]){
    m = x;
    for(int u = p[x]; u != x; u = p[u]){
      m = min(m, u);
    }
  }
  else{
    vis[x] = 1;
    m = min(x, buildmin(p[x]));
  }
  
  return m;
}

void build(){
  for(int i = 1; i <= n; ++i){
    buildmin(i);
  }
}

void bitadd(int i, int v){
  for(; i <= n; i += i & -i) bit[i] += v;
}

int bitsum(int i){
  int s = 0;
  for(; i; i -= i & -i) s += bit[i];
  return s;
}

inline void add(int k){
  bitadd(k, 2);
}

inline void rem(int k){
  bitadd(k, -2);
}

int current(int d){
  int i = 1, j = n;

  while(i < j){
    int m = (i + j) / 2;
    if(bitsum(m) < d){
      i = m + 1;
    }
    else{
      j = m;
    }
  }
  if(i == 1 or abs(bitsum(i) - d) < abs(bitsum(i - 1) - d)) return i;
  return current(bitsum(i - 1));
}

void mo(){
  int bs = sqrt(n);
  sort(qry.begin(), qry.end(),
    [bs](const tri& x, const tri& y){
      int bx = x.st.st / bs, by = y.st.st / bs;
      return bx != by ? bx < by : x.st.nd < y.st.nd;
    }
  );

  int ml = 1, mr = 0;
  for(auto q : qry){
    int l = q.st.st;
    int r = q.st.nd;
    int id = q.nd;

    while(mr < r) add(minx[++mr]);
    while(mr > r) rem(minx[mr--]);
    while(ml < l) rem(minx[ml++]);
    while(ml > l) add(minx[--ml]);

    ans[id] = current(r - l + 1);
  }
}

int main(){
  cin >> n >> q;
  for(int i = 1; i <= n; ++i) cin >> p[i];

  qry.reserve(q);
  for(int i = 0, l, r; i < q; ++i){
    cin >> l >> r;
    qry.pb(tri(ii(l,r), i));
  }

  build();
  mo();
  for(int i = 0; i < q; ++i) cout << ans[i] << '\n';

  return 0;
}

