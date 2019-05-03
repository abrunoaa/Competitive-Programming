#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;

  cin >> n;
  if (n == 1)
  {
    cout << "67\n76\n";
  }
  else
  {
    long long k = 0;
    for (int i = 0; i < n; ++i) k = (k * 10 + 9);
    cout << k-1 << k << '\n' << k << k-1 << '\n';
  }

  return 0;
}
