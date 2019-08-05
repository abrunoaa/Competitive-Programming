#include <bits/stdc++.h>
using namespace std;

#define MAX 2000100
#define pb push_back
#define reg register ll

typedef long long ll;

ll t, n, m, phi[MAX], depth[MAX] = {};

// pd para calcular depthphi(i)
ll depthphi (ll v) {
  if (v <= 1) { return 0; }
  ll &ref = depth[v];
  return ref ? ref : (ref = depthphi(phi[v]) + 1);
}

// calcula número de coprimos de n < MAX (eulerPhi(n))
void totient () {
  reg i, j;
  for (i = MAX; --i; phi[i] = i);                         // reseta
  for (i = 2; i < MAX; ++i)                               // todos os números
    if (phi[i] == i)                                      // i é primo
      for (j = i; j < MAX; j += i) {                      // todos os múltiplos de i
        phi[j] = phi[j] / i * (i - 1);
      }

  for (i = MAX; --i > 1; depthphi(i));                    // calcula para todo nº
  for (reg i = 2; i < MAX; ++i) { depth[i] += depth[i - 1]; } // 1D range sum
}

int main () {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  totient();                                              // pré calcula tudo

  cin >> t;
  while (t--) {                                           // O(t)
    cin >> m >> n, cout << depth[n] - depth[m - 1] << endl;
  }

  return 0;
}
