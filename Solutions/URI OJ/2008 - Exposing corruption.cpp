#include <iostream>
#include <set>
using namespace std;

#define maxn 203
#define maxb 10003

int d, p, r, b, m;
int cost[maxn];
int uf[maxn];
int dp[maxb];
int v1[maxn], v2[maxn], w[maxn];
int dsp[maxn], ppp[maxn];

int find(int u) {
  return (u == uf[u] ? u : uf[u] = find(uf[u]));
}

void unite(int u, int v) {
  u = find(u);
  v = find(v + d);
  if (u != v) {
    cost[u] += cost[v];
    dsp[u] += dsp[v];
    ppp[u] += ppp[v];
    uf[v] = u;
  }
}

int ks() {
  int sum = 0;
  for (int i = 0; i < m; ++i) { sum += v1[i]; }
  for (int j = 0; j <= b; ++j) { dp[j] = sum; }
  for (int i = 0; i < m; ++i)
    for (int j = b; j >= w[i]; --j) {
      dp[j] = max(dp[j], dp[j - w[i]] + v2[i] - v1[i]);
    }
  return dp[b];
}

int main() {
  //assert(freopen("in","r",stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  while (cin >> d >> p >> r >> b) {
    for (int i = 1; i <= d + p; ++i) {
      cin >> cost[i];
      uf[i] = i;
      dsp[i] = i <= d;
      ppp[i] = i > d;
    }
    while (r--) {
      int u, v;
      cin >> u >> v;
      unite(u, v);
    }
    m = 0;
    set<int> cnt;
    for (int i = 1; i <= d + p; ++i) {
      int k = find(i);
      if (!cnt.count(k)) {
        cnt.insert(k);
        v1[m] = dsp[k];
        v2[m] = ppp[k];
        w[m] = cost[k];
        ++m;
      }
    }
    cout << ks() << ' ';
    for (int i = 0; i < m; ++i) { swap(v1[i], v2[i]); }
    cout << ks() << '\n';
  }
  return 0;
}
