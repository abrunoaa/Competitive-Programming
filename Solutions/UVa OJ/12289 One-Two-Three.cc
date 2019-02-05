#include <bits/stdc++.h>
using namespace std;

inline bool cmp (char* s, const char* c)
{
  bool dif = 0;
  for (int i = 0; s[i] && c[i]; ++i)
    if (s[i] != c[i])
    {
      if (dif)
        return 0;
      dif = 1;
    }
  return 1;
}

int main()
{
  int t;
  char s[20];

  scanf("%d", &t);
  while (t--)
  {
    scanf(" %s", s);
    if (cmp(s, "one"))
      puts("1");
    else if (cmp(s, "two"))
      puts("2");
    else
      puts("3");
  }

  return 0;
}





