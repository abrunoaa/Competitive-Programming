//A
//12:22
//12:23

//B
//12:24
//12:25
//13:39

#include <iostream>
#include <math.h>

const double EPS = 1e-10;

using namespace std;

struct Point {
  double x, y, z;

  Point() { x = y = 0; }
  Point(double _x, double _y) : x(_x), y(_y) {}
  Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

  bool operator < (const Point &other) const {
    if (fabs(x - other.x) > EPS) {
      return x < other.x;
    }
    return y < other.y;
  }

  bool operator == (Point &other) {
    return (fabs(x - other.x) < EPS && fabs(y - other.y) < EPS);
  }

  bool operator != (Point &other) {
    return (fabs(x - other.x) > EPS || fabs(y - other.y) > EPS);
  }

  inline Point operator - (Point p) {
    return Point(x - p.x, y - p.y);
  }

  inline Point operator + (Point p) {
    return Point(x + p.x, y + p.y);
  }

  Point operator *(const double &m) const { return Point(m * x, m * y); }
  Point operator /(const double &m) const { return Point(x / m, y / m); }
  // Dot Product
  double operator *(const Point &o) const { return x * o.x + y * o.y; }
  // Cross Product
  double operator ^(const Point &o) const { return x * o.y - y * o.x; }
};

/** Is c inside the rectangle formed by left-top a and right-bottom b? */
bool isInsideRectangle(Point a, Point b, Point c) {
  return (c.x <= max(a.x, b.x)
          && c.x >= min(a.x, b.x)
          && c.y <= max(a.y, b.y)
          && c.y >= min(a.y, b.y));
}


int main() {

  //freopen("../input.txt","r", stdin);
  //freopen("../out.txt","w", stdout);

  int n;
  int ax, bx, cx, dx, ay, by, cy, dy;
  Point p;

  int count = 1;

  cin >> n;

  while (n--) {
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy >> p.x >> p.y;

    if (ax > bx || ay > dy) {
      printf("0\n");
      continue;
    }
    if (isInsideRectangle(Point(ax, ay), Point(cx, cy), p)) { printf("1\n"); }
    else { printf("0\n"); }

    count++;
  }

  return 0;
}
