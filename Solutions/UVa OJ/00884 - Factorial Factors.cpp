#include <bits/stdc++.h>
using namespace std;

#define maxn 1000010

int ans[maxn];

void sieve() {
  int n = maxn;
  for (int i = 2; i < n; ++i) {
    if (ans[i] == 0) {                        // i é primo
      ans[i] = 1;                             // i divide ele mesmo
      for (int j = 2 * i; j < n; j += i) {    // pega todos os multiplos j
        for (int k = j; k % i == 0; k /= i) { // conta quantas vezes i divide j
          ++ans[j];                           // i divide j
        }
      }
    }
    ans[i] += ans[i - 1];                     // conta todos fatoriais < i
  }
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  sieve();

  int n;
  while (cin >> n) {
    cout << ans[n] << '\n';
  }

  return 0;
}
