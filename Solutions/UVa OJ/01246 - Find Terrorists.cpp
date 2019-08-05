#include <bits/stdc++.h>
using namespace std;

#define maxn 10010

vector<int> ans, ndiv;

void sieve() {
  int n = maxn;
  ndiv.assign(n, 1);                          // 1 divide todos (e é neutro na mult.)
  for (int i = 2; i < n; ++i) {
    if (ndiv[i] == 1) {                       // i é primo
      ++ndiv[i];                              // 1 e i dividem i
      for (int j = 2 * i; j < n; j += i) {    // todos os multiplos j
        int e = 0;
        for (int k = j; k % i == 0; k /= i) { // conta quantas vezes i divide j
          ++e;
        }
        ndiv[j] *= e + 1;                     // conta num divisores
      }
    }
  }
}

bool isprime(int n) {
  return ndiv[n] == 2;
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  sieve();
  for (int i = 1; i < maxn; ++i) {
    if (isprime(ndiv[i])) {
      ans.push_back(i);
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int l, h;
    cin >> l >> h;

    int a = lower_bound(ans.begin(), ans.end(), l) - ans.begin();
    int b = upper_bound(ans.begin(), ans.end(), h) - ans.begin() - 1;

    if (a > b) {
      cout << "-1\n";
    } else {
      for (int i = a; i <= b; ++i) {
        cout << ans[i] << " \n"[i == b];
      }
    }
  }

  return 0;
}
