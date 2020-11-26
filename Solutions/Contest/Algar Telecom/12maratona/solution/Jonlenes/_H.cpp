#include <algorithm>
#include <iostream>
#include <utility>
#include <numeric>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <utility>

using namespace std;


struct Point {
  Point() : x(0), y(0) {}
  Point(double x, double y) : x(x), y(y) {}
  double x, y;
};

/*
    Retangulo: pair<Point, Point>
        first: ponto inferior esquerdo
        second: ponto superior direito

    Retorna true se o retangulo r1 e r2 tiverem area em comum. c representa a area em comum
*/
inline bool quadrilateroIntercecao(pair<Point, Point> r1, pair<Point, Point> r2, pair<Point, Point> &c) {
  /*
  x1 = q1.first.x
  y1 = q1.first.y
  x2 = q1.second.x
  y2 = q1.second.y
  x3 = q2.first.x
  y3 = q2.first.y
  x4 = q2.second.x
  y4 = q2.second.y
  */
  double maxX = max(r1.first.x, r2.first.x);
  double minX = min(r1.second.x, r2.second.x);
  double maxY = max(r1.first.y, r2.first.y);
  double minY = min(r1.second.y, r2.second.y);

  if (maxX >= minX || minY <= maxY) {
    return false;
  }

  c = make_pair(Point(maxX, maxY), Point(minX, minY));
  return true;
}

int main() {

  //freopen("../input.txt","r", stdin);
  //freopen("../out.txt","w", stdout);

  int cases = 1;
  int n;
  pair<Point, Point> r1, r2;

  while (cin >> n && n ) {

    cin >> r1.first.x >> r1.first.y >> r1.second.x >> r1.second.y;
    swap(r1.first.y, r1.second.y);

    bool r = false;

    while (--n) {
      cin >> r2.first.x >> r2.first.y >> r2.second.x >> r2.second.y;
      swap(r2.first.y, r2.second.y);
      r = r || !quadrilateroIntercecao(r1, r2, r1);
    }

    printf("Teste %d\n", cases++);
    if (r) { printf("nenhum\n"); }
    else { printf("%0.lf %0.lf %0.lf %0.lf\n", r1.first.x, r1.second.y, r1.second.x, r1.first.y); }
    printf("\n");
  }

  return 0;
}
