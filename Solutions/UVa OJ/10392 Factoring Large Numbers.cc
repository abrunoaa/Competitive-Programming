#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAX ((1 << 16) + 10)

typedef long long ll;
typedef vector<ll> vi;

ll n, s;
bitset<MAX> bs;
vi ans, pr;

void gera (ll n = MAX)
{
  ll i, j;

  bs.set();
  bs[0] = bs[1] = 0;
  for (i = 0; i < n; ++i)
    if (bs[i])
    {
      pr.pb(i);
      for (j = i * i; j < n; j += i)
        bs[j] = 0;
    }
}

void fatora (ll v)
{
  for (ll i = 0, pf = pr[i]; i < (ll)pr.size() && pf * pf <= v; pf = pr[++i])
    while (v % pf == 0)
      v /= pf, ans.pb(pf);
  if (v > 1) ans.pb(v);
}

int main()
{
  gera();

  while (scanf("%lld", &n) == 1 && n >= 0)
  {
    ans.clear();

    for (s = (ll)sqrt(n); s && n > 1; --s)
      if (n % s == 0)
        fatora(s), n /= s;
    if (n > 1) ans.pb(n);

    sort(ans.begin(), ans.end());
    for (ll i = 0; i < (ll)ans.size(); ++i)
      printf("    %lld\n", ans[i]);
    puts("");
  }

  return 0;
}
