#include <bits/stdc++.h>
using namespace std;

#define maxn 100000010

typedef long long ll;

bitset<maxn> isp;
vector<int> primes;

void sieve() {
  int n = maxn;
  isp.set();
  isp[0] = isp[1] = 0;
  primes.reserve(2 * int(n / log(n)));
  for (ll i = 2; i < n; ++i) {
    if (isp[i]) {
      primes.push_back(i);
      for (ll j = i * i; j < n; j += i) {
        isp[j] = 0;
      }
    }
  }
}

int f(int x) {
  return upper_bound(primes.begin(), primes.end(), x) - primes.begin();
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  sieve();

  cout << fixed << setprecision(1);

  int x;
  while (cin >> x && x) {
    int pi = f(x);
    cout << abs(pi - x / log(x)) * 100.0 / pi << '\n';
  }

  return 0;
}
