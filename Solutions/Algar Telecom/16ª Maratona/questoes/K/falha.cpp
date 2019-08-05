#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("falha.in", "r", stdin);
  freopen("out", "w", stdout);

  register int i, j;
  char r, v[500], a[500];

  while (scanf(" %1c %[^\n ]s", &r, v), r != '0' || *v != '0') {
    for (i = j = 0; v[i]; ++i)
      if (v[i] != r) {
        a[j++] = v[i];
      }
    a[j] = 0;
    for (i = 0; a[i] && a[i] == '0'; ++i);
    if (a[i]) {
      printf("%s\n", a + i);
    } else {
      printf("0\n");
    }
  }
  return 0;
}
