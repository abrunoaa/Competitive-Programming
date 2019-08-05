#include <bits/stdc++.h>
using namespace std;

#define maxn 2010
#define eps 1e-9
#define zero(z) (fabs(z) < eps)
#define x first
#define y second

typedef long long ll;
typedef pair<int, int> point;
typedef double lf;

struct line {
  lf a, b, c;

  line(point p, point q) {
    if (p.x == q.x) {
      a = 1.0;
      b = 0.0;
      c = -p.x;
    } else {
      a = -lf(p.y - q.y) / (p.x - q.x);
      b = 1.0;
      c = -a * p.x - p.y;
    }
  }

  bool operator < (const line &l) const {
    return !zero(a - l.a) ? a < l.a : !zero(b - l.b) ? b < l.b : c <= l.c - eps;
  }
};

int n, cnt2[2 * maxn * maxn];
point p[maxn];

void build() {
  for (int i = 2; i < maxn; ++i) {
    cnt2[2 * i * (i - 1)] = i;
  }
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  build();

  while (cin >> n) {
    map<line, int> cnt;

    for (int i = 0; i < n; ++i) {
      cin >> p[i].x >> p[i].y;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i != j) {
          cnt[line(p[i], p[j])] += 2;
        }
      }
    }

    ll ans = (ll)n * (n - 1) * (n - 2) / 6;
    for (auto &k : cnt) {
      int c = cnt2[k.y];
      ans -= (ll)c * (c - 1) * (c - 2) / 6;
    }
    cout << ans << '\n';
  }

  return 0;
}
