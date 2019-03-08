#include <bits/stdc++.h>
using namespace std;

#define gcd __gcd
#define popcnt __builtin_popcount
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
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Set;
typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update> Map;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << ' ' << x, db(y...); }

#ifdef LOCAL
__attribute__((destructor))
static void destroy(){
  cerr << "\nTime elapsed: " << (lf)clock() / CLOCKS_PER_SEC << "s.\n";
}

#define db(x...) cerr << " >> [" #x "] =", db(x)
#else
#warning "JUDGE"
#define db(...) 42
#endif

int a[maxn];

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;

  map<int,int> f;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    ++f[a[i]];
  }

  int rep = 0;
  for(int i = 0, x; i < n; ++i){
    cin >> x;
    ++f[x];
    if(x == a[i]){
      ++rep;
    }
  }

  int m;
  cin >> m;

  int ans = 1;
  for(auto it : f){
    for(int i = 2; i <= it.nd; ++i){
      int x = i;
      int z = min(rep, __builtin_ctz(x));
      x >>= z;
      rep -= z;
      ans = (ll)ans * x % m;
    }
  }
  cout << ans << '\n';

  return 0;
}
