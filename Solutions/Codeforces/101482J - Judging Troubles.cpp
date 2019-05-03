
 #include <bits/stdc++.h>
using namespace std;

int main()
{
  // freopen("jin", "r", stdin);

  char s[20];
  int n, i, ans;
  map<string,int> jud;

  scanf("%d", &n);

  for (i = 0; i < n; ++i)
    scanf(" %s", s), ++jud[s];
  for (i = ans = 0; i < n; ++i)
  {
    scanf(" %s", s);
    if (jud[s])
    {
      ++ans;
      --jud[s];
    }
  }

  printf("%d\n", ans);

  jud.clear();
  return 0;
}
