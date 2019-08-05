#include <bits/stdc++.h>
using namespace std;

int main() {
  float n;
  int q;
  scanf(" %d", &q);
  while (q--) {
    scanf(" %f", &n);
    printf("%.2f ", trunc(n *= 100) / 100);
    printf("%.2f ", trunc(n *= 1.5) / 100);
    printf("%.2f ", trunc(n *= 0.75) / 100);
    printf("%.2f ", trunc(n *= 1.5) / 100);
    printf("%.2f \n", trunc(n *= 0.75) / 100);
  }
  return 0;
}
