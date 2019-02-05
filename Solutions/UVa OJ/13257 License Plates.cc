#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

typedef vector<int> vi;

int main()
{
  ios::sync_with_stdio(0), cin.tie(0);

  int tc, n, ans;
  string s;
  vi u;
  vector<vi> v;

  cin >> tc;
again:
  while (tc--)
  {
    cin >> s, n = s.length();
    if (n < 3)
    {                               // trivial ;-)
      cout << '0' << endl;
      goto again;
    }

    v.assign(n, vi());              // armazena as posições de A..Z que são maiores que i
    v[n - 1].assign(26, -1);        // não tem letra após a última (flag = -1)
    for (int i = n - 1; i--; )      // para as outras letras
    {
      v[i] = v[i + 1];              // pega o próximo (são as mesmas letras/posições)
      v[i][s[i + 1] - 65] = i + 1;  // atualiza a próxima letra (única que muda)
    }
    u = v[0];                       // posições das letras na string toda
    u[s[0] - 65] = 0;

    // junta todas as letras possíveis
    ans = 0;
    for (int x : u)
      if (x >= 0)
        for (int y : v[x])
          if (y >= 0)
            for (int z : v[y])
              if (z >= 0)
                ++ans;

    cout << ans << endl;
  }

  return 0;
}
