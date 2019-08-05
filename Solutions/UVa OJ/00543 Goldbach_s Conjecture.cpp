#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100
#define endl '\n'

int i, n, falta, ans;
bitset<MAX> bsprimos;
vector<int> primos;

void gera () {
  long long i, j;

  bsprimos.set();
  bsprimos[0] = bsprimos[1] = 0;
  for (i = 2; i < MAX; ++i)
    if (bsprimos[i]) {
      primos.push_back(i);
      for (j = i * i; j < MAX; j += i) {
        bsprimos[j] = 0;
      }
    }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  gera();
  while (cin >> n && n) {
    for (i = ans = 0; n / 2 >= primos[i]; ++i)
      if (bsprimos[n - primos[i]]) {
        cout << n << " = " << primos[i] << " + " << n - primos[i] << endl;
        break;
      }

    if (n / 2 < primos[i]) {
      cout << "Goldbach's conjecture is wrong.\n";
    }
  }

  return 0;
}

/*   n = p1 + p2
    p2 = n - p1
 */

