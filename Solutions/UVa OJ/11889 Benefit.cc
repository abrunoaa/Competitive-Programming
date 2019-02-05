#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define endl '\n'
#define MAXP 3200 // sqrt(10⁷) ≃ 3162.277660168

typedef map<int,int> Fat;

bitset<MAXP> epr;
vector<int> pr;

int mdc(int a, int b) { return b ? mdc(b, a % b) : a; }
int mmc(int a, int b) { return a * (b / mdc(a, b)); }

void sieve (int n = MAXP)
{
  epr.set();
  epr[0] = epr[1] = 0;

  pr.reserve((int)(n / log(n)) << 1);
  for (int i = 2; i < n; ++i)
    if (epr[i])
    {
      pr.push_back(i);
      for (int j = i * i; j < n; j += i)
        epr[j] = 0;
    }
}

Fat fatora (int n)
{
  Fat fatores;

  for (int i = 0, p = pr[0], up = sqrt(n); p <= up; p = pr[++i])
    if (n % p == 0)
    {
      int &f = fatores[p];
      while (n % p == 0) n /= p, ++f;
    }
  if (n > 1) ++fatores[n];

  return fatores;
}

int main()
{
  sieve();
  ios_base::sync_with_stdio(0), cin.tie(0);

  int t, a, c;

  cin >> t;
next_tc:
  while (t--)
  {
    cin >> a >> c;

    Fat fa = fatora(a), fb = fatora(c);
    for (auto x : fa)
    {
      int &f = fb[x.fst];
      if (f < x.snd)
      {
        cout << "NO SOLUTION\n";
        goto next_tc;
      }
      if (f == x.snd)
        f = 0;
    }

    int b = 1;
    for (auto x : fb) for (int k = x.snd; k--; b *= x.fst);
    if (mmc(a, b) != c) cout << "NO SOLUTION\n";
    else                cout << b << endl;
  }

  return 0;
}
