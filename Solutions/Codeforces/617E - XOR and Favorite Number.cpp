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
#define mod 1000000007
#define maxn 100010

typedef long long ll;
typedef long double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> tri;
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Set;
typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update> Map;

#ifndef ONLINE_JUDGE
struct _ { _() { assert(freopen("in","r",stdin)); } } _;
#define db(x...) cerr << " >>", db(x)
#else
struct _ { _() { cin.sync_with_stdio(0), cin.tie(0); } } _;
#define db(x...)
#endif

int n, m, k, a[maxn], f[1 << 20];
ll current, ans[maxn];
vector<tri> qry;

void add(int x){
  current += f[x ^ k];
  ++f[x];
}

void rem(int x){
  --f[x];
  current -= f[x ^ k];
}

void mo(){
  int bs = sqrt(n);
  sort(qry.begin(), qry.end(),
    [bs](const tri& x, const tri& y){
      int bx = x.st.st / bs, by = y.st.st / bs;
      return bx != by ? bx < by : x.st.nd < y.st.nd;
    }
  );

  int ml = 0, mr = -1;
  for(auto q : qry){
    int l = q.st.st - 1;
    int r = q.st.nd;
    int i = q.nd;

    while(mr < r) add(a[++mr]);
    while(mr > r) rem(a[mr--]);
    while(ml < l) rem(a[ml++]);
    while(ml > l) add(a[--ml]);

    ans[i] = current;
  }
}

int main(){
  cin >> n >> m >> k;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
    a[i] ^= a[i - 1];
  }

  qry.reserve(m);
  for(int i = 0, l, r; i < m; ++i){
    cin >> l >> r;
    qry.pb(tri(ii(l, r), i));
  }

  mo();
  for(int i = 0; i < m; ++i) cout << ans[i] << '\n';

  return 0;
}