#include <bits/stdc++.h>
using namespace std;

#define maxn 3200 // sqrt(10^7)

bitset<maxn> isp;
vector<int> primes;

void sieve() {
  int n = maxn;
  isp.set();
  isp[0] = isp[1] = 0;
  primes.reserve(2 * int(n / log(n)));

  for (int i = 2; i < n; ++i) {
    if (isp[i]) {
      primes.push_back(i);
      for (int j = i * i; j < n; j += i) {
        isp[j] = 0;
      }
    }
  }
}

void fatora(int n) {
  cout << '1';
  for (int p : primes) {
    if (p * p > n) {
      break;
    }
    while (n % p == 0) {
      cout << " x " << p;
      n /= p;
    }
  }
  if (n > 1) {
    cout << " x " << n;
  }
  cout << '\n';
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  sieve();

  int n;
  while (cin >> n) {
    fatora(n);
  }

  return 0;
}
