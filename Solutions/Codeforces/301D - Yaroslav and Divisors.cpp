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
#define assert(x) 42
#define db(...) 42
#define freopen(...) 42
#endif

template<class t> t sq(t x) { return x * x; }

bool included[maxn];
int n, m, p[maxn], idx[maxn];
ll ans[maxn], ft[maxn];
tri q[maxn];

void upd(int i){
  for(; i < maxn; i += i & -i){
    ++ft[i];
  }
}

ll qry(int i){
  ll s = 0;
  for(; i; i -= i & -i){
    s += ft[i];
  }
  return s;
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  memset(ans, -1, sizeof ans);

  cin >> n >> m;
  for(int i = 1; i <= n; ++i){
    cin >> p[i];
    idx[p[i]] = i;
  }
  for(int i = 0; i < m; ++i){
    cin >> q[i].st.st >> q[i].st.nd;
    q[i].nd = i;
  }
  sort(q, q + m, greater<tri>());

  for(int i = n, j = 0; i; --i){
    int x = p[i];
    included[x] = 1;
    for(int k = 2 * x; k <= n; k += x){
      if(included[k]){
        upd(idx[k]);
      }
    }
    for(int k = 1, sq = sqrt(x); k <= sq; ++k){
      if(x % k == 0){
        if(included[k]){
          upd(idx[k]);
        }
        if(k != x / k && included[x / k]){
          upd(idx[x / k]);
        }
      }
    }
    for(; i == q[j].st.st; ++j){
      ans[q[j].nd] = qry(q[j].st.nd);
    }
  }
  for(int i = 0; i < m; ++i){
    cout << ans[i] << endl;
  }

  return 0;
}
