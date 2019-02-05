#include <bits/stdc++.h>
using namespace std;

int main()
{
  int v1, v2, v3;
  while (scanf("%d%d%d", &v1, &v2, &v3), v1 || v2 || v3)
    if (v3 - v2 == v2 - v1)                                       // verifica se é PA
      printf("AP %d\n", v3 + v2 - v1);
    else                                                          // é PG
      printf("GP %d\n", v3 * (v2 / v1));

  return 0;
}
