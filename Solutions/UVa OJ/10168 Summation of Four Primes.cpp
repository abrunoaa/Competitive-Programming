#include <bits/stdc++.h>
using namespace std;

#define MAX 10000100

typedef long long ll;

int ans1, ans2;
bitset<MAX> epr;
vector<int> pr;

void sieve (int n = MAX) {
  epr.set();
  epr[0] = epr[1] = 0;

  pr.reserve((int)(n / log(n)) << 1);
  for (ll i = 2; i < n; ++i)
    if (epr[i]) {
      pr.push_back(i);
      for (ll j = i * i; j < n; j += i) { epr[j] = 0; }
    }
}

/*
 * Para ser a soma de 4 primos deve ser:
 *
 * >> 2 + 2 + P1 + P2 , se n for par
 * >> 2 + 3 + P1 + P2 , se n for ímpar
 */
bool goldbach (int n) {
  if (n < 8) { return 0; }
  n -= 4 + (n & 1);                               // remove "2 + 2" ou "2 + 3"

  if ((n & 1) && n > 1) {                         // é ímpar: 2 + ímpar
    if (!epr[n - 2]) { return 0; }
    ans1 = 2, ans2 = n - 2;
    return 1;
  }
  // é par: ímpar + ímpar
  for (int i = 0, p = pr[0]; p < n; p = pr[++i])
    if (epr[n - p]) {
      ans1 = p, ans2 = n - p;
      return 1;
    }

  return 0;
}

int main() {
  sieve();

  int n;
  while (scanf("%d", &n) == 1)
    if (goldbach(n)) { printf("%d %d %d %d\n", 2, 2 + (n & 1), ans1, ans2); }
    else { puts("Impossible."); }

  return 0;
}
