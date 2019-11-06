#include <bits/stdc++.h>
using namespace std;

int length, tc = 0;
char s[35];

/*
 * abc     ==> checa abc
 * abcd    ==> checa bcd
 * abcde   ==> checa cde
 * abcdef  ==> checa def && abcdef
 * abcdefg ==> checa efg && bcdefg
 *   ...
 */
bool inval (int x, int n)
{
  for (int i = 1; 3 * i <= n; ++i)                          // checa i bits da direita
  {
    int a = (x & (((1 << i) - 1) << (i << 1))) >> (i << 1), // bits à esquerda
      b = (x & (((1 << i) - 1) << i)) >> i,                 // bits do meio
      c = x & ((1 << i) - 1);                               // bits da direita

    if (a == b && a == c) return 1;
  }

  return 0;
}

int tfree (int x = 0, int n = 0)
{
  if (inval(x, n)) return 0;  // é inválido
  if (n == length) return 1;  // formou o número

  if (s[n] != '*') return tfree((x << 1) | (s[n] == '1'), n + 1);
  return tfree((x << 1), n + 1) + tfree((x << 1) | 1, n + 1);
}

int main()
{
  // freopen("in", "r", stdin);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  while (cin >> length >> s && length) cout << "Case " << ++tc << ": " << tfree() << '\n';

  return 0;
}
