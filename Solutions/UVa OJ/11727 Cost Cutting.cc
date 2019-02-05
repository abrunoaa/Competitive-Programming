#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, a[4], cs = 0;
  a[3] = 1e9;

  scanf("%d", &t);
  while (t--)
  {
    scanf("%d%d%d", a, a+1, a+2);
    sort(a, a+3);
    printf("Case %d: %d\n", ++cs, a[1]);
  }

  return 0;
}
