#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__() { cerr << "\nElapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void debug() {}
template<class t, class... u> void debug(const t &x, const u &...y) { cerr << ' ' << x, debug(y...); }
#define debug(x...) cerr<<"\x1b[91m[" #x "] =",debug(x),cerr<<"\x1b[0m\n"
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

#define null nullptr
#define st first
#define nd second
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 100003
#define maxl 17

typedef long long ll;
typedef double lf;
typedef pair<int, int> ii;

bool black[maxn];
int chainNum, pt, depth[maxn], p[maxn], head[maxn], chain[maxn], pos[maxn], node[maxn], size[maxn];
set<int> st[maxn];
vector<int> g[maxn];

void dfs(int u, int par = 0, int d = 0) {
  depth[u] = d;
  p[u] = par;
  size[u] = 1;
  for (int v : g[u]) {
    if (v != par) {
      dfs(v, u, d + 1);
      size[u] += size[v];
    }
  }
}

void hld(int u, int par = 0) {
  if (!head[chainNum]) { head[chainNum] = u; }
  chain[u] = chainNum;
  pos[u] = pt;
  node[pt] = u;
  ++pt;
  int pref = 0;
  for (int v : g[u])
    if (v != par && size[v] > size[pref]) {
      pref = v;
    }
  if (pref != 0) { hld(pref, u); }
  for (int v : g[u]) {
    if (v != par && v != pref) {
      ++chainNum;
      hld(v, u);
    }
  }
}

void change(int u) {
  black[u] ^= 1;
  auto &s = st[chain[u]];
  if (black[u]) { s.insert(pos[u]); }
  else { s.erase(pos[u]); }
}

int ask(int u) {
  int ans = -1;
  while (u) {
    int k = *st[chain[u]].begin();
    if (k <= pos[u]) { ans = node[k]; }
    u = p[head[chain[u]]];
  }
  return ans;
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  for (auto &s : st) { s.insert(inf); }

  int n, q;
  cin >> n >> q;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1);
  hld(1);
  while (q--) {
    int a, b;
    cin >> a >> b;
    if (a == 0) {
      change(b);
    } else {
      cout << ask(b) << '\n';
    }
  }

  return 0;
}
