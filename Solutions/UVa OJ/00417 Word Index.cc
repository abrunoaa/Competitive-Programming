#include <bits/stdc++.h>
using namespace std;

bool comp (string a, string b)
{ return a.length() < b.length() || (a.length() == b.length() && a < b); }

int i;
map<string,int,bool(*)(string,string)> words(comp);
map<string,int,bool(*)(string,string)>::iterator it;

void gera (string s = "", char l = 'a')
{
  if (s.length() == 5) return;

  int last = s.length();
  s.push_back(l);
  for (int i = l - 'a'; i < 26; ++i, ++s[last])
  {
    words[s] = 0;
    gera(s, s[last] + 1);
  }
}

int main()
{
  gera();
  for (it = words.begin(), i = 1; it != words.end(); ++it, ++i)
    it->second = i;

  char s[10];
  while (scanf(" %s", s) == 1)
    printf("%d\n", words[s]);

  return 0;
}
