#include <bits/stdc++.h>
using namespace std;

int main()
{
  char s[100];
  string str;

  scanf("%*[_]");
  while (scanf(" %[^\n]", s) == 1 && *s != '_')
  {
    char c = 0;
    for (int i = 0; s[i]; ++i)
      if (s[i] == 'o' || s[i] == ' ')
        c = (c << 1) + (s[i] == 'o');

    str.push_back(c);
  }

  cout << str;

  return 0;
}
