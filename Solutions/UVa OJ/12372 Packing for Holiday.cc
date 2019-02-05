#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, x, y, z, cs = 0;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d%d%d", &x, &y, &z);
    printf("Case %d: %s\n", ++cs, (x <= 20 && y <= 20 && z <= 20 ? "good" : "bad"));
  }

  return 0;
}





