#include <bits/stdc++.h>
using namespace std;

#define zero(x) (fabs(x) < 1e-12L)

typedef double lf;

struct point { int x, y; };

inline bool cmp (lf x, lf y) { return !zero(x - y) && x < y; }

/*
 * retorna x quando y = 0 na reta formada por p -> q
 *
 * ax + by + c = 0
 *
 * a = -(py - qy) / (px - qx)
 * b = 1
 * c = -a * px - py
 * y = 0
 *
 * ax + by + c = 0
 *  ax + b * 0 = -c
 *           x = -c / a
 *             = -(-a * px - py) / a
 *             = (a * px + py) / a
 *             = px + py / a
 *             = px + py / (-(py - qy) / (px - qx))
 *             = px - py / ((py - qy) / (px - qx))
 *             = px - py * (px - qx) / (py - qy)
 *
 * >> caso especial: a = 0, forma linha vertical: x = -c
 */
inline lf getx (point p, point q)
{ return p.x == q.x ? lf(p.x) : (p.x - p.y * (p.x - q.x) / lf(p.y - q.y)); }

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  int N;

  while (cin >> N) {
    set<int> ans;
    set<lf, bool(*)(lf, lf)> rep(cmp);
    map<lf, int, bool(*)(lf, lf)> mp(cmp);

    vector<point> ponto(N);
    for (point &p : ponto) { cin >> p.x >> p.y; }

    for (point p : ponto) {
      rep.clear();
      for (point q : ponto)
        if (p.y > q.y) {                  // p é bloqueado por q
          rep.insert(getx(p, q));  // no ponto "getx"
        }

      // conta ele UMA VEZ no x que ele aparece
      for (auto it : rep) { ++mp[it]; }
    }

    // conta quantas árvores NÃO VIU (é o mesmo resultado)
    for (auto it : mp) { ans.insert(it.second); }

    // qtde de todas que não viu +1 (sempre pode ver todas)
    cout << ans.size() + 1 << '\n';
  }

  return 0;
}
