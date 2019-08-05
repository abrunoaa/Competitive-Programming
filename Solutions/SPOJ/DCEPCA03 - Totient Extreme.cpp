#include <bits/stdc++.h>
using namespace std;

#define maxn 10010

int totient[maxn];
long long h[maxn];

void sieve() {
  int n = maxn;
  for (int i = 0; i < n; ++i) {
    totient[i] = i;
  }
  for (int i = 2; i < n; ++i) {
    if (totient[i] == i) {
      --totient[i];
      for (int j = 2 * i; j < n; j += i) {
        totient[j] -= totient[j] / i;
      }
    }
  }
}

void solve() {
  sieve();

  for (int n = 1; n < maxn; ++n) {
    h[n] = h[n - 1];                    // aproveita a resposta de n-1
    for (int i = 1; i < n; ++i) {       // calcula o que falta em i
      h[n] += totient[i] * totient[n];
    }
    for (int j = 1; j <= n; ++j) {      // calcula o que falta em j
      h[n] += totient[n] * totient[j];
    }
  }
}

int main() {
  solve();

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << h[n] << '\n';
  }

  return 0;
}
