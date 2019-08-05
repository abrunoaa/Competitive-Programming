#include <cstdio>



int main() {
  int x, y;

  scanf("%d%d", &x, &y);

  if (x > 432 || y > 468 || x < 0 || y < 0) {
    printf("fora");
  } else {
    printf("dentro");
  }

}
