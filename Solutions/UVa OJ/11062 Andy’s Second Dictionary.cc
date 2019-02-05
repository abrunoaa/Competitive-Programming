#include <bits/stdc++.h>
using namespace std;

int main()
{
  int i, len;
  char s[201], c = 0;
  set<string> dict;
  set<string>::iterator it;

  scanf("%*[^A-Za-z]");
  while (scanf("%[A-Za-z]", s) == 1)
  {
    while (scanf("%1c", &c) == 1 && c == '-' && scanf("%1c", &c) == 1)
    {
      len = strlen(s);
      if (c == '\n')
        scanf("%[A-Za-z]", s + len);
      else
      {
        s[len] = '-';
        s[len + 1] = c;
        scanf("%[A-Za-z]", s + len + 2);
      }
    }
    for (i = 0; s[i]; ++i) s[i] = tolower(s[i]);
    dict.insert(s);
    scanf("%*[^A-Za-z]");
  }
  for (it = dict.begin(); it != dict.end(); ++it)
    printf("%s\n", it->data());

  return 0;
}
