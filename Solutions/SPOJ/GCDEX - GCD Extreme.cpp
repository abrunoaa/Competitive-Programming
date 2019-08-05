#include <bits/stdc++.h>
using namespace std;

#define maxn 1000010

typedef long long ll;

int phi[maxn];
ll g[maxn];

void sieve() {
  int n = maxn;
  for (int i = 1; i < n; ++i) {
    phi[i] = i;
  }
  for (int i = 2; i < n; ++i)
    if (phi[i] == i) {
      --phi[i];
      for (int j = 2 * i; j < n; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  for (int i = 1; i < n; ++i) {
    for (int j = 2 * i; j < n; j += i) {
      g[j] += (ll)i * phi[j / i];
    }
    g[i] += g[i - 1];
  }
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  sieve();

  int n;
  while (cin >> n && n) { cout << g[n] << '\n'; }

  return 0;
}
