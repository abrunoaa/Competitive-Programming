#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define MAX 1000010

typedef pair<int, int> ii;

int n, m = 0;
long long ant = 1;
bitset<MAX> epr;
vector<int> pr, entrada;
vector<ii> fatores;
map<int, int> fatorAnt;

void crivo (int n) {                              // gera primos < n < 2^15
  epr.set();
  epr[0] = epr[1] = 0;

  pr.reserve((int)((double)n / log(n)) << 1);
  for (int i = 2; i < n; ++i)
    if (epr[i]) {
      pr.push_back(i);
      for (int j = i * i; j < n; j += i) { epr[j] = 0; }
    }
}

void fatora (int k) {                             // fatora (k) em números primos
  int i = 0, fp;
  while (fp = pr[i++], fp * fp <= k) {
    if (k % fp == 0) { fatores.push_back(ii(fp, 0)); }
    while (k % fp == 0) { k /= fp, ++fatores.back().snd; }
  }
  if (k > 1) { fatores.push_back(ii(k, 1)); }
}

int lcm() {                                       // lcm (fatores, fat_anteriores) mod 10
  for (int i = 0; i < (int)fatores.size(); ++i) {
    int &ref = fatorAnt[fatores[i].fst];
    if (ref < fatores[i].snd) {
      for (int j = fatores[i].snd - ref; j--; ant = (ant * fatores[i].fst) % 1000000000);
      ref = fatores[i].snd;
    }
  }

  while (ant % 10 == 0) { ant /= 10; }
  return ant % 10;
}

int main() {
  entrada.reserve(1010), fatores.reserve(1010);
  while (scanf("%d", &n) == 1 && n) { entrada.push_back(n), m = max(m, n); }

  crivo((int)sqrt(m) + 10);
  int ans[m + 10];

  for (int i = 1; i <= m; ++i) {
    fatores.clear(), fatora(i);
    ans[i] = lcm();
  }
  for (int i = 0; i < (int)entrada.size(); ++i) { printf("%d\n", ans[entrada[i]]); }

  return 0;
}
