#include <cstdio>



int main() {
  register int j, l, menor, n, disp, t;
  int v[1000] = {0}, nl[1000] = {0};

  scanf("%d%d", &n, &l);

  while (l > 0) {
    scanf("%d", &t);
    disp = 0;
    menor = v[0];
    for (j = 1; j < n; j++) {
      if (v[j] < menor) {
        menor = v[j];
        disp = j;
      }
    }
    v[disp] += t;
    nl[disp]++;
    l--;
  }

  for (j = 0; j < n; j++) {
    printf("%d %d\n", j + 1, nl[j]);
  }
}
