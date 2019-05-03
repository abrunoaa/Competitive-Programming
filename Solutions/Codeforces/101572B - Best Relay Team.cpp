#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second

typedef pair<double,double> ii;
typedef pair<ii,string> cor;

int main()
{
  //~ freopen("bin", "r", stdin);

  int n, i, j, lim;
  double t, me, a, b;
  char nom[50];
  string nomes, ans;
  vector<cor> c1, c2;

  scanf("%d", &n);
  c1.reserve(n), c2.reserve(n);

  for (i = 0; i < n; ++i)
    scanf(" %s%lf%lf", nom, &a, &b), c1.push_back(cor(ii(a, b), nom)), c2.push_back(cor(ii(b, a), nom));

  sort(c1.begin(), c1.end());
  sort(c2.begin(), c2.end());

  me = 1e9;
  for (i = 0; i < 4; ++i)
  {
    //~ cerr << i << " " << c1[i].snd << endl;
    t = c1[i].fst.fst;
    nomes = c1[i].snd + "\n";
    for (j = 0, lim = 3; j < lim; ++j)
      if (c2[j].snd == c1[i].snd)
        ++lim;
      else
      {
        t += c2[j].fst.fst;
        nomes += c2[j].snd + "\n";
      }

    if (t < me)
    {
      me = t;
      ans = nomes;
    }
  }

  cout << me << '\n' << ans;

  return 0;
}
