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

int n, m, q, uf[2 * maxn], sum[maxn];
vi color[maxn];
vector<tri> edge;
map<int,int> memo[maxn];

int find(int u){ return u == uf[u] ? u : uf[u] = find(uf[u]); }
inline void unite(int u, int v){ uf[find(u)] = find(v); }

int getuf(int u, int c){
  auto &cu = color[u];
  return sum[u - 1] + (lower_bound(cu.begin(), cu.end(), c) - cu.begin());
}

void build(){
  for(int i = 0; i < 2 * maxn; ++i){
    uf[i] = i;
  }
  sum[0] = 0;
  for(int i = 1; i <= n; ++i){
    auto &c = color[i];
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    sum[i] = sum[i - 1] + (int)c.size();
  }
  for(auto e : edge){
    int a = e.st.st;
    int b = e.st.nd;
    int c = e.nd;

    int pa = getuf(a, c);
    int pb = getuf(b, c);
    unite(pa, pb);
  }
}

int main(){
  cin >> n >> m;
  for(int i = 0, a, b, c; i < m; ++i){
    cin >> a >> b >> c;
    edge.pb(tri(ii(a, b), c));
    color[a].pb(c);
    color[b].pb(c);
  }
  build();
  cin >> q;
  while(q--){
    int u, v;
    cin >> u >> v;
    if(color[u].size() > color[v].size()){
      swap(u, v);
    }

    if(memo[u].count(v)){
      cout << memo[u][v] << '\n';
    }
    else{
      int &ans = memo[u][v] = 0;
      auto &cu = color[u];
      auto &cv = color[v];
      for(int i = 0; i < (int)cu.size(); ++i){
        if(binary_search(cv.begin(), cv.end(), cu[i])){
          int pu = getuf(u, cu[i]);
          int pv = getuf(v, cu[i]);
          if(find(pu) == find(pv)){
            ++ans;
          }
        }
      }

      cout << ans << '\n';
    }
  }

  return 0;
}
