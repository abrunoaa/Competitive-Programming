#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define sz(x) (int)x.size()

string s;

ll fexp (int b, int n, int m)
{
  ll ans = 1;
  while (1)
  {
    if (n & 1) ans = ans * b % m;
    if ((n >>= 1) == 0) return ans;
    b = (long long)b * b % m;
  }
}

int palindrome ()
{
  int i = 0, j = sz(s) - 1, p = 0, h1f, h2f, h1s, h2s, n = 0;
  h1f = h2f = h1s = h2s = 0;

  while (i <= j)
  {
    h1f = (31LL * h1f + s[i] - 'A' + 1) % 1000000007;
    h2f = (37LL * h2f + s[i] - 'A' + 1) % 1000000009;
    h1s = (h1s + (s[j] - 'A' + 1) * fexp(31, n, 1000000007)) % 1000000007;
    h2s = (h2s + (s[j] - 'A' + 1) * fexp(37, n, 1000000009)) % 1000000009;

    if (h1f == h1s && h2f == h2s)
    {
      p += 1 + (i < j);
      n = h1f = h2f = h1s = h2s = 0;
    }
    else
      ++n;

    ++i, --j;
  }

  return p + (n > 0);
}

int main()
{
  // freopen("fin", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int t, cs = 0;

  cin >> t;
  while (t--)
    cin >> s,
    cout << "Case #" << ++cs << ": " << palindrome() << '\n';

  return 0;
}
