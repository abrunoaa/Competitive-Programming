#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

int main()
{
  ios::sync_with_stdio(0), cin.tie(0);

  string s;

  while (cin >> s)
  {
    int qtd[4] = {};

    for (char c : s)
      if (isdigit(c))
        ++qtd[c - 48];

    for (int i = 1, flag = 0; i <= 3; ++i)
      while (qtd[i]--)
      {
        if (flag) cout << '+';
        else flag = 1;
        cout << i;
      }
    cout << endl;
  }

  return 0;
}
