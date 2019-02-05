#include <cstdio>

int main()
{
  char s[15001];
  int num, i;

  while (scanf(" %[^#]#", s) == 1)
  {
    for (i = num = 0; s[i]; ++i)
      if (s[i] == '0' || s[i] == '1')
        num = (2 * num + s[i] - 48) % 131071;

    puts(num == 0 ? "YES" : "NO");
  }

  return 0;
}
