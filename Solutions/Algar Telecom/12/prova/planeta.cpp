#include <bits/stdc++.h>
using namespace std;

int main() {
  //freopen("planeta.in", "r", stdin);

  char no;
  int n, v;
  map < int, char > mp;

  while (scanf("%d", &n) > 0 && n) {
    scanf("%*d");
    no = 0;
    while (n--) {
      scanf("%d", &v);
      if (mp[v]++) {
        no = 1;
        break;
      }
    }
    if (no && n >= 0) {
      while (n--) {
        scanf("%*d");
      }
      printf("1\n");
    } else {
      printf("0\n");
    }
    mp.clear();
  }
  return 0;
}
