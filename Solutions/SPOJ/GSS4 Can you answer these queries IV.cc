/*
 * You are given a sequence A of N (N <= 100,000) positive integers. There sum will be
 * less than 10^18. On this sequence you have to apply M (M <= 100,000) operations for
 * given x,y (1 <= x,y <= N):
 * - for each element between x and y (inclusively), modify it to its square root.
 * - query the sum of all the elements between x and y (inclusively).
 */

#include <bits/stdc++.h>
using namespace std;

#define maxn 100010

typedef long long ll;

int n, cs = 0, prox[maxn];
ll ft[maxn];

int find (int k) { return k == prox[k] ? k : prox[k] = find(prox[k]); }

ll soma (int i)
{
  ll s = 0;
  for (++i; i; i -= i & -i) s += ft[i];
  return s;
}

ll soma (int i, int j) { return soma(j) - soma(i - 1); }

void add (int i, ll v) { for (++i; i <= n; i += i & -i) ft[i] += v; }

void att (int i, int j)
{
  for (i = find(i); i <= j; i = find(i + 1))
  {
    ll k = soma(i,i);
    ll r = (ll)sqrt(k);
    add(i, r - k);
    if (r == 1) prox[i] = find(i + 1);
  }
}

int main()
{
  cin.sync_with_stdio(0), cin.tie(0);

  while (cin >> n)
  {
    cout << "Case #" << ++cs << ":\n";

    for (int i = 0; i <= n; ++i) ft[i] = 0, prox[i] = i;
    for (int i = 0; i < n; ++i)
    {
      ll tmp;
      cin >> tmp;
      add(i, tmp);
      if (tmp <= 1) prox[i] = i + 1;
    }

    int m;
    cin >> m;
    while (m--)
    {
      int i, x, y;
      cin >> i >> x >> y, --x, --y;
      if (x > y) swap(x, y);
      if (i)  cout << soma(x, y) << '\n';
      else    att(x, y);
    }

    cout << '\n';
  }

  return 0;
}
