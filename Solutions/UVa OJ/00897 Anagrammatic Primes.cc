#include <bits/stdc++.h>
using namespace std;

#define MAX 3200    // sqrt(10'000'000) = 3162 >> 3200
#define endl '\n'

int n;
bitset<MAX> bsprimos;
vector<int> primos;

void gera (int n = MAX)
{
  int i, j;

  bsprimos.set();
  bsprimos[0] = bsprimos[1] = 0;
  for (i = 2; i < n; ++i)
    if (bsprimos[i])
    {
      primos.push_back(i);
      for (j = i * i; j < (int)primos.size(); j += i)
        bsprimos[j] = 0;
    }
}

bool ePrimo (int v)
{
  if (v < MAX) return bsprimos[v];

  int i;
  for (i = 0; i < (int)primos.size() && v % primos[i]; ++i);
  return i == (int)primos.size();
}

bool eAnagram (string s)
{
  int v;

  sort(s.begin(), s.end());                         // ordena para permutar
  do
  {
    sscanf(s.data(), "%d", &v);
    if (!ePrimo(v)) return 0;                       // não é primo nem "anagram. prime"
  } while (next_permutation(s.begin(), s.end()));   // permuta todos os números

  return 1;                                         // é "anagrammatic prime"
}

int fstAnagram (int n)
{
  if (n > 1000) return 0;           // se n > 1000 não há respostas
                                    // (gerador foi usado)
  int k, nums = 0;
  char s[10];

  for (k = n; k; k /= 10) ++nums;   // conta qtde de dígitos
  nums = (int)pow(10, nums);        // pega próxima potência de 10

  while (++n < nums)                // vai até a potência de 10
  {
    sprintf(s, "%d", n);
    if (eAnagram(s)) return n;      // retorna "anagrammatic prime"
  }

  return 0;                         // não encontrou
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0);
  gera();

  while (cin >> n && n) cout << fstAnagram(n) << endl;

  return 0;
}
