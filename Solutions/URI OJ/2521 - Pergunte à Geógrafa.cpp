#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9
#define zero(x) (fabs(x) < eps)
#define pr(x) (zero(x) ? 0.0 : x)
#define torad(d) (acos(-1.0) / 180.0 * d)

typedef long double lf;

struct latlon { lf r, lat, lon; };  // lat e lon em radianos!
struct pt { lf x, y, z; };          // ponto cartesiano

pt convert(latlon l) {
  return pt{ l.r * cos(l.lon)* cos(l.lat),
             l.r * sin(l.lon)* cos(l.lat),
             l.r * sin(l.lat) };
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  cout << setprecision(2) << fixed;

  latlon ll;
  while (cin >> ll.r >> ll.lat >> ll.lon) {
    ll.lat = torad(ll.lat);
    ll.lon = torad(ll.lon);
    pt r = convert(ll);
    cout << pr(r.y) << ' ' << pr(r.z) << ' ' << pr(-r.x) << '\n';
  }

  return 0;
}
