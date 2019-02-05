#include <bits/stdc++.h>
using namespace std;

struct point
{
  int x, y;

  point () {}
  point(int x, int y) : x(x), y(y) {}

  point translate (point p) { return point(x + p.x, y + p.y); }
};

struct square
{
  point low, upp;

  square () {}
  square (point l, point u) : low(l), upp(u) {}

  bool intersect (square &s)
  {
    if (low.x > s.low.x) return s.intersect(*this);

    // checa se está entre os dois x e entre os dois y
    return s.low.x < upp.x && upp.y > s.low.y && low.y < s.upp.y;
  }
};

int N, W, H, w, h;
vector<point> check(210 * 210);
vector<square> paint(210);

int main()
{
  // freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    cin >> N >> W >> H;
    paint.resize(N);
    for (square &s : paint) cin >> s.low.x >> s.low.y >> s.upp.x >> s.upp.y;
    paint.push_back(square(point(0,0),point(0,0)));
    cin >> w >> h;

    check.clear();                                  // gera todos os possíveis pontos
    for (square &s : paint)
      for (square &t : paint)
        check.push_back(point(s.upp.x, t.upp.y));

    point ans(W + 1,H + 1);
    for (point &p : check)
    {
      square s(p, p.translate(point(w, h)));        // quadro que a pintura ocupará
      for (square &t : paint)                       // checa se algum outro quadro sobrepõe
        if (s.intersect(t))                         // o que está tentando colocar
          goto failed;

      // checa se é menor e é válido para atualizar a resposta
      if ((p.y < ans.y || (p.y == ans.y && p.x < ans.x)) && p.x + w <= W && p.y + h <= H)
        ans = p;

      failed: continue;
    }

    if (ans.x > W)  cout << "Fail!\n";
    else            cout << ans.x << ' ' << ans.y << '\n';
  }

  return 0;
}
