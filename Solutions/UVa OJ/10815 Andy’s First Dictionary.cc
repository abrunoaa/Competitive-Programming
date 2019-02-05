#include <bits/stdc++.h>
using namespace std;

int main()
{
  int i;
  char s[201];
  set<string> dict;
  set<string>::iterator it;

  scanf("%*[^A-Za-z]");
  while (scanf("%[A-Za-z]%*[^A-Za-z]", s) > 0)
  {
    for (i = 0; s[i]; ++i) s[i] = tolower(s[i]);
    dict.insert(s);
  }
  for (it = dict.begin(); it != dict.end(); ++it)
    printf("%s\n", it->data());

  return 0;
}
