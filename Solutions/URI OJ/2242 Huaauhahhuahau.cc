// Ad Hoc - muito fácil

#include <bits/stdc++.h>
using namespace std;

bool vogal(char c)
{ return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }

int main()
{
  char s[55], ans[55];
  int i, k;

  while (scanf(" %[^\n]", s) > 0)
  {
    for (i = k = 0; s[i]; ++i)
      if (vogal(s[i]))
        ans[k++] = s[i];

    for (i = 0; i < k/2 && ans[i] == ans[k - i - 1]; ++i);
    puts(i < k/2 ? "N" : "S");
  }

  return 0;
}
