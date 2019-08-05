#include <bits/stdc++.h>
#define INF 1e60
#define EPS 1e-9
#define MAXN 100900
using namespace std;


typedef pair<int, int> Point;
#define x first
#define y second


Point P[MAXN];
Point ans[2];
long double menor;

long double dist(Point a, Point b) {

  long double temp = hypot(a.x - b.x, a.y - b.y);

  if (menor > temp) {
    menor  = temp;
    ans[0] = a;
    ans[1] = b;
  }

  return temp;
}

int cmpX(const void* a, const void* b) {
  Point* p1 = (Point*)a,  *p2 = (Point*)b;
  return (p1->x - p2->x);
}

int cmpY(const void* a, const void* b) {
  Point* p1 = (Point*)a,   *p2 = (Point*)b;
  return (p1->y - p2->y);
}

long double VerificaFaixa(Point faixa[], int size, long double d) {
  long double TamFaixa = d, temp;
  qsort(faixa, size, sizeof(Point), cmpY);

  for (int i = 0; i < size; ++i)
    for (int j = i + 1; j < size && (faixa[j].y - faixa[i].y) < TamFaixa; ++j) {
      temp = dist(faixa[i], faixa[j]);
      if (temp < TamFaixa) { TamFaixa = temp; }
    }
  return TamFaixa;
}

long double ClosestPairPoints(int l, int r) {

  if ((r - l) <= 3) { //fb
    long double distmin = INF;
    for (int i = l; i < r; ++i)
      for (int j = i + 1; j < r; ++j)
        if (dist(P[i], P[j]) < distmin) { distmin = dist(P[i], P[j]); }
    return distmin;
  }

  int mid = (l + r) / 2,    pos = 0;
  Point midPoint = P[mid],    faixa[r - l + 2];

  long double dl = ClosestPairPoints(l, mid);
  long double dr = ClosestPairPoints(mid + 1, r);
  long double d = min(dl, dr);

  for (int i = l; i < r; i++) {
    if ( abs(P[i].x - midPoint.x)  < d) {
      faixa[pos++] = P[i];
    }
  }
  return min(d, VerificaFaixa(faixa, pos, d) );
}


int main() {

  //~ freopen("fin","r",stdin);

  int n, i;
  menor = INF;

  scanf(" %d", &n);
  for (i = 0 ; i < n ; ++i) { scanf(" %d %d", &P[i].x, &P[i].y); }


  qsort(P, n, sizeof(Point), cmpX);
  ClosestPairPoints(0, n);
  printf("%d %d\n%d %d\n", (int)ans[0].x, (int)ans[0].y, (int)ans[1].x, (int)ans[1].y);
  return 0;
}
