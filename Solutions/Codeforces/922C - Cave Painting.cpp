#include <bits/stdc++.h>
using namespace std;

bitset<10000000> qtd;

int main()
{
  cin.sync_with_stdio(0), cin.tie(0);

  long long n, k;
  cin >> n >> k;

  for (long long i = 1; i <= k; ++i)
  {
    if (qtd[n % i])
    {
      cout << "No\n";
      return 0;
    }
    qtd[n % i] = 1;
  }

  cout << "Yes\n";

  return 0;
}
