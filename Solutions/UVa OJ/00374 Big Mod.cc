#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;

ll b, p, m;

ll modPow (ll b, ll p)
{
  if (!p) return 1;

  ll tmp = modPow(b, p >> 1);
  tmp *= tmp;
  if (p & 1) tmp *= b;

  return tmp % m;
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  while (cin >> b >> p >> m) cout << modPow(b % m, p) << endl;

  return 0;
}
