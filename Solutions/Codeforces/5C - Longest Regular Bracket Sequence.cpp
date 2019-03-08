#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define size(x) (int)x.size()

int main()
{
  // freopen("in", "r", stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  int i, ans, qtd;
  string s;
  vector<int> stack, start, open;

  s.reserve(1000010);
  stack.reserve(1000010);

  while (getline(cin, s))
  {
    open.assign(size(s) + 3, -1);
    start.assign(size(s) + 3, -1);
    stack.clear();

    for (i = ans = 0, qtd = 1; i < size(s); ++i)
      if (s[i] == '(')
        stack.push_back(i);
      else if (stack.empty())
        start[i] = open[i] = -1;
      else
      {
        start[i] = open[i] = stack.back();
        stack.pop_back();

        if (s[start[i] - 1] == ')' && start[start[i] - 1] != -1) start[i] = start[start[i] - 1];

        if (i - start[i] + 1 > ans)
          ans = i - start[i] + 1, qtd = 1;
        else if (i - start[i] + 1 == ans)
          ++qtd;
      }

    cout << ans << ' ' << qtd << endl;
  }

  return 0;
}
