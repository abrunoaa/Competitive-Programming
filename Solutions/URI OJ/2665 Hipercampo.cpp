#include <bits/stdc++.h>
using namespace std;

#define maxn 105
#define x first
#define y second

typedef pair<int, int> point;

int N, memo[maxn];
point A(0, 0), B(0, 0), P[maxn];

inline int ccw(point p, point q, point r)
{ return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x); }

inline bool inside(point p, point a, point b, point c)
{ return ccw(a, b, p) > 0 && ccw(a, c, p) <= 0; }

int campo(int p) {
  int &pd = memo[p];
  if (pd != -1) { return pd; }

  pd = 0;
  for (int i = 0; i < N; ++i)
    if (i != p && inside(P[i], P[p], A, B)) {
      pd = max(pd, campo(i));
    }

  return ++pd;
}

int main() {
  // freopen("br", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  while (cin >> N >> A.x >> B.x) {
    int ans = 0;
    memset(memo, -1, sizeof memo);

    for (int i = 0; i < N; ++i) { cin >> P[i].x >> P[i].y; }
    for (int i = 0; i < N; ++i) { ans = max(ans, campo(i)); }

    cout << ans << '\n';
  }

  return 0;
}
