#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

int correct (int v) { return v < 0 ? -1 : v > 0; }

int casecmp (const char* s, const char* t)
{
  int i;
  for (i = 0; s[i] && tolower(s[i]) == tolower(t[i]); ++i);
  return tolower(s[i]) - tolower(t[i]);
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0);

  string s, t;
  while (cin >> s >> t) cout << correct(casecmp(s.data(), t.data())) << endl;

  return 0;
}
