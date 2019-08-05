#include <bits/stdc++.h>
using namespace std;

#define maxn 110
#define st first
#define nd second

typedef pair<int, int> ii;
typedef long long ll;

vector<int> primes;
bitset<maxn> isprime;

void sieve(int n) {
  isprime.set();
  isprime[0] = isprime[1] = 0;
  primes.reserve(2 * int(n / log(n)));
  for (ll i = 2; i <= n; ++i)
    if (isprime[i]) {
      primes.push_back(i);
      for (ll j = i * i; j <= n; j += i) {
        isprime[j] = 0;
      }
    }
}

map<int, int> fatora(int n) {
  map<int, int> fat;
  for (int p : primes) {
    if (p * p > n) {
      break;
    }
    if (n % p == 0) {
      int e = 0;
      while (n % p == 0) { n /= p, ++e; }
      fat[p] = e;
    }
  }
  if (n > 1) { fat[n] = 1; }
  return fat;
}

map<int, int> fatoraFatorial(int n) {
  map<int, int> fat;
  for (int p : primes) {
    if (p > n) {
      break;
    }
    int e = 0;
    for (int k = p; k <= n; k *= p) { e += n / k; }
    fat[p] = e;
  }
  return fat;
}

int main() {
  sieve(maxn);
  int n, d;

again:
  while (cin >> n >> d && (n || d)) {
    d = abs(d);

    auto u = fatora(d);
    auto v = fatoraFatorial(n);

    // checa se tem divisor
    for (auto x : u)
      if (x.nd > v[x.st]) {
        cout << "0\n";
        goto again;
      }

    ll ans = 1;
    for (auto x : v) { ans *= x.nd + 1 - u[x.st]; }
    cout << ans << '\n';
  }

  return 0;
}
