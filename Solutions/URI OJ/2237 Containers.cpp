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
#define maxn 50000

typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
typedef pair<ii, int> tri;
typedef vector<int> vi;
typedef vector<ii> vii;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> Map;

#ifndef ONLINE_JUDGE
struct _ { _() { assert(freopen("in", "r", stdin)); } } _;
#define db(x...) cerr << " >>", db(x)
#else
#warning "ONLINE_JUDGE"
struct _ { _() { cin.sync_with_stdio(0), cin.tie(0); } } _;
#define db(x...)
#endif

typedef vector<vi> vvi;

bool vis[maxn];
int cnt;
map<vvi, int> K;
map<int, vvi> M;
set<int> edge[maxn];
vii adj[maxn];

void liga(vvi m, int k) {
  // db(k);
  if (vis[k]) { return; }
  vis[k] = 1;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      vvi t = m;
      swap(t[i][j], t[i][j + 1]);
      int &k2 = K[t];
      if (!k2) { k2 = ++cnt; }
      if (!edge[k].count(k2)) {
        int c = t[i][j] + t[i][j + 1];
        edge[k].insert(k2);
        edge[k2].insert(k);
        adj[k].pb(ii(k2, c));
        adj[k2].pb(ii(k, c));
        liga(t, k2);
      }
    }
  }
  for (int i = 0; i < 4; ++i) {
    vvi t = m;
    swap(t[0][i], t[1][i]);
    int &k2 = K[t];
    if (!k2) { k2 = ++cnt; }
    if (!edge[k].count(k2)) {
      int c = t[0][i] + t[1][i];
      edge[k].insert(k2);
      edge[k2].insert(k);
      adj[k].pb(ii(k2, c));
      adj[k2].pb(ii(k, c));
      liga(t, k2);
    }
  }
}

int dijkstra(int so, int si) {
  vi dist(cnt + 10, inf);
  dist[so] = 0;
  priority_queue<ii, vii, greater<ii>> q;
  q.push(ii(0, so));
  while (!q.empty()) {
    ii f = q.top();
    q.pop();
    int d = f.st;
    int u = f.nd;
    if (d > dist[u]) { continue; }
    for (ii v : adj[u]) {
      if (d + v.nd < dist[v.st]) {
        dist[v.st] = d + v.nd;
        q.push(ii(dist[v.st], v.st));
      }
    }
  }
  return dist[si];
}

int main() {
  vvi so, si;

  for (int i = 0; i < 2; ++i) {
    so.pb(vi());
    for (int j = 0, x; j < 4; ++j) {
      cin >> x;
      so[i].pb(x);
    }
  }
  for (int i = 0; i < 2; ++i) {
    si.pb(vi());
    for (int j = 0, x; j < 4; ++j) {
      cin >> x;
      si[i].pb(x);
    }
  }

  K[so] = cnt = 1;
  if (K[si] == 1) {
    cout << "0\n";
    return 0;
  }
  K[si] = cnt = 2;
  liga(so, 1);
  cout << dijkstra(1, 2) << '\n';

  return 0;
}

