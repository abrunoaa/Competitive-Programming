#include<bits/stdc++.h>
using namespace std;

double f1 (double n, double p, double c) {
  return (n / (p * 1000000000.0)) * pow(log2(n), c * sqrt(2));
}

double f2 (double s, double v, double c) {
  return s * (1 + 1.0 / c) / v;
}


int main() {
  int n;
  double p, s, v, c;


  scanf("%d", &n);
  scanf("%lf", &p);
  scanf("%lf", &s);
  scanf("%lf", &v);



  double i = 0.000000001, f = 30;
  for (f = 1; f1(n, p, f) < 1000000000000ll; f++);
  while (fabs(i - f) >= 0.000001) {
    c = (i + f) / 2.0;
    if (f1(n, p, c) + f2(s, v, c) < f1(n, p, c - 0.000001) + f2(s, v, c - 0.000001)) {
      i = c;
    } else {
      f = c;
    }
  }
  printf ("%.8f %.8f\n", f1(n, p, c) + f2(s, v, c), c);
}
