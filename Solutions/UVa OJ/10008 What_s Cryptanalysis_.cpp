#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second

typedef pair<int, int> ii;

bool cmp (ii i1, ii i2) { return i1.fst > i2.fst || (i1.fst == i2.fst && i1.snd < i2.snd); }

int main() {
  int t;
  char s[1000000];
  vector<ii> v;
  map<char, int> mp;

  scanf("%d", &t);
  while (t-- && scanf("%*1c%[^\n]", s) == 1)
    for (int i = 0; s[i]; ++i)
      if (isalpha(s[i])) {
        ++mp[toupper(s[i])];
      }

  v.reserve(mp.size());
  for (auto p : mp) { v.push_back(ii(p.snd, p.fst)); }
  sort(v.begin(), v.end(), cmp);
  for (auto p : v) { printf("%c %d\n", p.snd, p.fst); }

  return 0;
}
