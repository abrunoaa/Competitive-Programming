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
#define maxn 100002

typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
typedef pair<ii, int> tri;
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> Map;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << ' ' << x, db(y...); }

#ifdef LOCAL
__attribute__((destructor))
static void destroy() {
  cerr << "\nTime elapsed: " << (lf)clock() / CLOCKS_PER_SEC << "s.\n";
}

#define db(x...) cerr << " >> [" #x "] =", db(x)
#else
#warning "JUDGE"
#define db(...) 42
#endif

int n, m, k, s, dis[maxn][102];
vi g[maxn], prod[102];

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  memset(dis, inf, sizeof dis);

  cin >> n >> m >> k >> s;
  for (int i = 0, a; i < n; ++i) {
    cin >> a, --a;
    prod[a].pb(i);
  }
  while (m--) {
    int u, v;
    cin >> u >> v, --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }

  for (int p = 0; p < k; ++p) {
    // bfs
    queue<int> q;
    for (int u : prod[p]) {
      dis[u][p] = 0;
      q.push(u);
    }

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (int v : g[u]) {
        if (dis[v][p] == inf) {
          dis[v][p] = dis[u][p] + 1;
          q.push(v);
        }
      }
    }
  }

  for (int u = 0; u < n; ++u) {
    sort(dis[u], dis[u] + k);
    int ans = 0;
    for (int i = 0; i < s; ++i) {
      ans += dis[u][i];
    }
    if (u) { cout << ' '; }
    cout << ans;
  }
  cout << '\n';

  return 0;
}
