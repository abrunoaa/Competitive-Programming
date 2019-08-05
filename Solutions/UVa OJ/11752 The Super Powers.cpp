#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define endl '\n'

typedef unsigned long long ull;

ull i, j, k, lim, up = 1 << 16;
double l10 = log10(-1ull);
set<ull> sup;
bitset<70> bs;

void gera(ull n) {
  ull i, j;

  bs.set();
  bs[0] = bs[1] = 0;
  for (i = 2; i < n; ++i)
    if (bs[i])
      for (j = i * i; j < n; j += i) {
        bs[j] = 0;
      }
}

int main() {
  cout.sync_with_stdio(0), cout.tie(0);
  gera(70);                                                   // maior 2^64 >> 70

  sup.insert(1);
  for (i = 2; i < up; ++i)                                    // 2 .. 2^16
    for (j = 4, k = i * i * i * i, lim = (ull)ceil(l10 / log10(i)); j < lim; ++j, k *= i)
      if (!bs[j]) {                                           // i ^ j, j não primo
        sup.insert(k);
      }

  for (auto b = sup.begin(), e = sup.end(); b != e; ++b) {
    cout << *b << endl;
  }

  return 0;
}

/*
 * ex.:
 * 2^4 = 2^2^2  >>  2^4 = 4^2
 * 3^6 = 3^2^3 = 3^3^2  >>  3^6 = 9^3 = 27^2
 *
 * >> não tem outra representação:
 * 3^3 = 27
 * 5^2 = 25
 *
 * nota:
 * lim = ceil(log10(MAX_VAL) / log10(k))
 * k ^ lim >= 2 ^ 64  >>  estoura ull
 */
