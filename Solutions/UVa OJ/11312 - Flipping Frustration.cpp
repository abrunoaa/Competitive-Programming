#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e7 + 3;

int dis[maxn];

int calc(int n, int l, int r, int k) {
  if (k % r == 0) return k / r;
  int g = __gcd(l, r);
  if (k % g > 0) return -1;
  k /= g;
  l /= g;
  r /= g;
  n /= g;
  if (n / r * r - l < 0) return -1;
  int mx = max(l, r);
  int a = k - mx;
  int b = k + mx;
  if (b >= n) {
    a -= b - n + 1;
    b = n - 1;
  }
  if (a < 0) {
    b += -a;
    a = 0;
  }
  b = min(b, n - 1);
  int d = (a + r - 1) / r;
  int s = d * r - a;
  n = b - a + 1;
  k -= a;
  memset(dis, -1, n * sizeof(*dis));
  dis[s] = d;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int v = u - l;
    if (v >= 0 && dis[v] == -1) {
      dis[v] = dis[u] + 1;
      if (v == k) break;
      q.push(v);
    }
    v = u + r;
    if (v < n && dis[v] == -1) {
      dis[v] = dis[u] + 1;
      if (v == k) break;
      q.push(v);
    }
  }
  return dis[k];
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int c;
  cin >> c;
  while (c--) {
    int n, l, r, t;
    cin >> n >> l >> r >> t;
    int ans = calc(n, l, r, t - 1);
    if (ans == -1) {
      cout << "uh-oh!\n";
    } else {
      cout << ans << '\n';
    }
  }
  return 0;
}
