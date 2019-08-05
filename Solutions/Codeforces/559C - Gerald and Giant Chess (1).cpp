#include <bits/stdc++.h>
using namespace std;

#define maxn 2010
#define maxf 200010
#define mod 1000000007
#define x first
#define y second

typedef pair<int, int> ii;
typedef long long ll;

int h, w, n, d[maxn];
int f[maxf] = {1}, finv[maxf] = {1};
ii p[maxn];

int mpow(int b, int e, int m) {
  int x = 1;
  while (e) {
    if (e % 2) { x = (ll)x * b % m; }
    e /= 2;
    b = (ll)b * b % m;
  }
  return x;
}

void build() {
  for (int i = 1; i < maxf; ++i) {
    f[i] = (ll)i * f[i - 1] % mod;
    finv[i] = (ll)finv[i - 1] * mpow(i, mod - 2, mod) % mod;
  }
}

int C(int n, int k) {
  return (ll)f[n] * finv[k] % mod * (ll)finv[n - k] % mod;
}

int paths(ii p, ii q) {
  return C(q.x + q.y - p.x - p.y, q.x - p.x);
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  build();

  while (cin >> h >> w >> n) {
    for (int i = 0; i < n; ++i) {
      cin >> p[i].x >> p[i].y;
    }
    p[n] = ii(h, w);
    sort(p, p + n);

    for (int i = 0; i <= n; ++i) {
      d[i] = paths(ii(1, 1), p[i]);
      // cerr << " ---------- " << p[i].x << ' ' << p[i].y << endl;
      // cerr << " >> 1,1 -> " << p[i].x << ',' << p[i].y << " == " << d[i] << endl;
      for (int j = 0; j < n && p[j].x <= p[i].x; ++j) {
        // cerr << " >> " << i << ' ' << j << " :: " << p[i].x << ',' << p[i].y << " -> " << p[j].x << ',' << p[j].y << endl;
        if (p[j].y <= p[i].y && i != j) {
          // cerr << " ## " << p[j].x << ',' << p[j].y << " -> " << p[i].x << ',' << p[i].y << " == " << paths(p[j], p[i]) << endl;
          d[i] = (d[i] - (ll)d[j] * paths(p[j], p[i]) % mod + mod) % mod;
        }
      }
    }

    cout << d[n] << '\n';
  }

  return 0;
}
