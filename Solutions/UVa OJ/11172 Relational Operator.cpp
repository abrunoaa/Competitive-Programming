#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;

  scanf("%d", &n);
  while (n--) {
    scanf("%d%d", &a, &b);
    printf("%c\n", (a < b ? '<' : (a > b ? '>' : '=')));
  }

  return 0;
}
