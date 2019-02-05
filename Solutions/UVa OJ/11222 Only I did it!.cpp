#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  register int i;
  int teste, s1, s2, s3, n[10005], a1, a2, a3, o1[1005], o2[1005], o3[1005], count = 0;

  scanf("%d", &teste);
  while (teste--)
  {
    scanf("%d", &s1);
    vector < int > p1(s1);
    for (i = s1; i--; scanf("%d", &p1[i]));

    scanf("%d", &s2);
    vector < int > p2(s2);
    for (i = s2; i--; scanf("%d", &p2[i]));

    scanf("%d", &s3);
    vector < int > p3(s3);
    for (i = s3; i--; scanf("%d", &p3[i]));

    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());
    sort(p3.begin(), p3.end());

    for (i = 10005; i--; n[i] = 1);

    a1 = a2 = a3 = 0;
    for (i = -1; ++i < s1; )
      if (*find(p2.begin(), p2.end(), p1[i]) != p1[i] &&
          *find(p3.begin(), p3.end(), p1[i]) != p1[i])
      {
        o1[a1++] = p1[i];
        //printf(" * %d\n", p1[i]);
      }
      else
      {
        n[p1[i]] = 0;
        //printf(" # %d %d\n", *find(p2.begin(), p2.end(), p1[i]), *find(p3.begin(), p3.end(), p1[i]));
      }
/*
    printf(" !");
    for (i = -1; ++i < 20; printf("%2d", n[i]));
    printf("\n");
//*/
    for (i = -1; ++i < s2; )
      if (n[p2[i]])
      {
        if (*find(p3.begin(), p3.end(), p2[i]) != p2[i])
          o2[a2++] = p2[i];
        else
          n[p2[i]] = 0;
      }

    for (i = -1; ++i < s3; )
      if (n[p3[i]])
        o3[a3++] = p3[i];

/*
    printf(" !");
    for (i = -1; ++i < 20; printf("%2d", n[i]));
    printf("\n 1 :");
    for (i = -1; ++i < a1; printf("%2d", o1[i]));
    printf("\n 2 :");
    for (i = -1; ++i < a2; printf("%2d", o2[i]));
    printf("\n 3 :");
    for (i = -1; ++i < a3; printf("%2d", o3[i]));
    printf("\n");

    printf(" > %d %d %d\n", a1, a2, a3);
//*/
    printf("Case #%d:\n", ++count);
    if (a1 == a2 && a1 == a3)
    {
      printf("1 %d", a1);
      for (i = -1; ++i < a1; printf(" %d", o1[i]));
      printf("\n2 %d", a2);
      for (i = -1; ++i < a2; printf(" %d", o2[i]));
      printf("\n3 %d", a3);
      for (i = -1; ++i < a3; printf(" %d", o3[i]));
    }
    else if (a1 == a2 && a1 > a3)
    {
      printf("1 %d", a1);
      for (i = -1; ++i < a1; printf(" %d", o1[i]));
      printf("\n2 %d", a2);
      for (i = -1; ++i < a2; printf(" %d", o2[i]));
    }
    else if (a1 == a3 && a1 > a2)
    {
      printf("1 %d", a1);
      for (i = -1; ++i < a1; printf(" %d", o1[i]));
      printf("\n3 %d", a3);
      for (i = -1; ++i < a3; printf(" %d", o3[i]));
    }
    else if (a2 == a3 && a2 > a1)
    {
      printf("2 %d", a2);
      for (i = -1; ++i < a2; printf(" %d", o2[i]));
      printf("\n3 %d", a3);
      for (i = -1; ++i < a3; printf(" %d", o3[i]));
    }
    else if (a1 > a2 && a1 > a3)
    {
      printf("1 %d", a1);
      for (i = -1; ++i < a1; printf(" %d", o1[i]));
    }
    else if (a2 > a1 && a2 > a3)
    {
      printf("2 %d", a2);
      for (i = -1; ++i < a2; printf(" %d", o2[i]));
    }
    else
    {
      printf("3 %d", a3);
      for (i = -1; ++i < a3; printf(" %d", o3[i]));
    }

    printf("\n");
  }

  return 0;
}
