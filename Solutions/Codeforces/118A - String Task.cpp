#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

int main()
{
  ios::sync_with_stdio(0), cin.tie(0);

  string vowels = "AEIOUYaeiouy", s, t;
  while (cin >> s)
  {
    t.clear();
    for (auto c : s)
      if ((int)vowels.find(c) == -1)
        t.push_back('.'), t.push_back(tolower(c));

    cout << t << endl;
  }

  return 0;
}
