#include <bits/stdc++.h>
using namespace std;

#define zero(x) (fabs(x) < 1e-12L)

typedef long double lf;

struct point { int x, y; };

bool cmp (lf x, lf y) { return !zero(x - y) && x < y; }

lf getx (point p, point q)
{ return p.x == q.x ? lf(p.x) : (lf(p.x) - lf(p.y) * lf(p.x - q.x) / lf(p.y - q.y)); }

int main() {
  // freopen("in", "r", stdin);

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
        if (p.y > q.y) {                  // p Ã© bloqueado por q
          rep.insert(getx(p, q));
        }

      for (auto it : rep) { ++mp[it]; }
    }

    for (auto it : mp) { ans.insert(it.second); }
    // for (auto it : ans) cerr << " >> " << it << endl;

    cout << ans.size() + 1 << '\n';
  }

  return 0;
}
