#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

typedef pair<int,int> ii;

int n, b[100010];
vector<ii> a;

int main()
{
  freopen("hell.in", "r", stdin);
  freopen("hell.out", "w", stdout);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i].f, a[i].s = i;

  sort(a.rbegin(), a.rend());

  int s = 0;
  for (int i = 0; i < n; ++i)
  {
    if (s <= 0)
    {
      b[a[i].s] = 1;
      s += a[i].f;
    }
    else
    {
      b[a[i].s] = -1;
      s -= a[i].f;
    }
    // cerr << " >> " << s << endl;
  }

  if (s)
    cout << "No\n";
  else
  {
    cout << "Yes\n";
    for (int i = 0; i < n; ++i)
    {
      if (i) cout << ' ' ;
      cout << b[i];
    }
    cout << '\n';
  }

  return 0;
}
