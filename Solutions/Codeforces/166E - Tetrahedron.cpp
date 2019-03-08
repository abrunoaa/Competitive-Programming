#include <bits/stdc++.h>
using namespace std;

#define maxd 4
#define mod 1000000007

typedef long long ll;

struct matrix
{
  int m[maxd][maxd];

  matrix operator * (matrix &mat) const
  {
    matrix ans;

    int i, j, k;
    for (i = 0; i < maxd; ++i)
      for (j = 0; j < maxd; ++j)
      {
        int &t = ans.m[i][j] = 0;
        for (k = 0; k < maxd; ++k)
          t = (t + (ll)m[i][k] * mat.m[k][j]) % mod;
      }

    return ans;
  }
};

int fexp (int n)
{
  matrix ans, b;

  for (int i = 0; i < maxd; ++i)
    for (int j = 0; j < maxd; ++j)
      ans.m[i][j] = (i == j),
      b.m[i][j] = (i != j);

  while (1)
  {
    if (n & 1) ans = ans * b;
    if ((n >>= 1) == 0) return ans.m[3][3];
    b = b * b;
  }
}

int main()
{
  cin.sync_with_stdio(0), cin.tie(0);

  int n;
  while (cin >> n) cout << fexp(n) << '\n';

  return 0;
}
