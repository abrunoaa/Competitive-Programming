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
#define maxn 200010

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

int n, v[maxn], cant[32];
vi u, ans;
map<int,bool> tried;

int cnt(){
  int n = u.size();
  memset(cant, 0, sizeof cant);
  for(int i = 0; i < n; ++i){
    for(int j = i + 1; j < n; ++j){
      int d = abs(v[i] - v[j]);
      db(v[i], v[j], d);
      if((d & -d) != 0){
        ++cant[v[i]];
        ++cant[v[j]];
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < n; ++i){
    ans = max(ans, n - cant[i]);
  }
  return ans;
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> v[i];
  }
  sort(v, v + n);

  for(int i = 0; i < n; ++i){
    u.clear();
    u.pb(v[i]);
    for(ll d = 1; d <= (1ll << 30); d *= 2){
      int p = upper_bound(v, v + n, v[i] + d) - v - 1;
      if(v[i] + d == v[p]){
        bool flag = 1;
        for(int x : u){
          int dis = abs(x - v[p]);
          if(dis & (dis - 1)){
            flag = 0;
            break;
          }
        }
        if(flag){
          u.pb(v[p]);
        }
      }
    }
    if(u.size() > ans.size()){
      ans = u;
    }
  }

  cout << ans.size() << endl;
  for(int x : ans){
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}
