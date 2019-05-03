#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define maxn 100010
#define EPS 1e-12
#define zero(x) (fabs(x) < EPS)

typedef long long ll;
typedef long double lf;
typedef pair<ll,ll> point;

inline ll square(ll x) { return x * x; }

struct circle
{
  lf x, y, r;

  circle () : x(0.0), y(0.0), r(-1.0) {}
  circle (point a) : x(a.x), y(a.y), r(0.0) {}
  circle (point a, point b) : x((a.x + b.x) / 2.0), y((a.y + b.y) / 2.0), r(hypot(x - a.x, y - a.y)) {}
  circle (point a, point b, point c) : x(0.0), y(0.0), r(-1.0)
  {
    ll d = (a.x - b.x) * (b.y - c.y) - (a.y - b.y) * (b.x - c.x);
    if (!zero(d))
    {
      ll k = square(b.x) + square(b.y);
      lf ab = (square(a.x) + square(a.y) - k) / 2.0;
      lf bc = (k - square(c.x) - square(c.y)) / 2.0;

      x = (ab * (b.y - c.y) - bc * (a.y - b.y)) / d;
      y = (bc * (a.x - b.x) - ab * (b.x - c.x)) / d;
      r = hypot(x - b.x, y - b.y);
    }
  }
};

point p[maxn], b[3];

circle cover(int np, int nb)
{
  if (nb == 3) return circle(b[0], b[1], b[2]);
  if (np < 0)
  {
    if (nb == 0) return circle();
    if (nb == 1) return circle(b[0]);
    return circle(b[0], b[1]);
  }

  circle c = cover(np - 1, nb);
  lf d = hypot(p[np].x - c.x, p[np].y - c.y);
  if (d <= c.r) return c;

  b[nb] = p[np];
  return cover(np - 1, nb + 1);
}

int main()
{
  // freopen("br", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n;

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;

  srand(19988991);
  random_shuffle(p, p + n);

  circle c = cover(n - 1, 0);

  cout << fixed << setprecision(9);
  cout << c.x << ' ' << c.y << '\n';
  cout << c.r << '\n';

  return 0;
}
