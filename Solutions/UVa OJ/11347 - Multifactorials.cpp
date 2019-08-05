#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define maxn 1010

typedef map<int, int> mii;
typedef long long ll;

ll inf = 1e18;

bitset<maxn> isp;
vector<int> primes;

void sieve() {
  int n = maxn;
  primes.reserve(2 * int(n / log(n)));
  isp.set();
  isp[0] = isp[1] = 0;

  for (int i = 2; i < n; ++i) {
    if (isp[i]) {
      primes.push_back(i);
      for (int j = i * i; j < n; j += i) {
        isp[j] = 0;
      }
    }
  }
}

void merge(mii &x, const mii &y) {
  for (auto z : y) {
    x[z.st] += z.nd;
  }
}

mii fatora(int n) {
  mii f;
  for (int p : primes) {
    if (p * p > n) {
      break;
    }
    if (n % p == 0) {
      int e = 0;
      while (n % p == 0) {
        n /= p;
        ++e;
      }
      f[p] = e;
    }
  }
  if (n > 1) {
    f[n] = 1;
  }
  return f;
}

int main() {
  sieve();

  int t;
  cin >> t;
  for (int cs = 1; cs <= t; ++cs) {
    int n;
    string s;
    cin >> n >> s;
    int nf = s.size();
    int lim = max(1, n % nf);
    mii f;

    for (int i = n; i >= lim; i -= nf) {
      merge(f, fatora(i));
    }
    __int128 ans = 1;
    for (auto x : f) {
      ans *= x.nd + 1;
      if (ans > inf) {
        break;
      }
    }

    cout << "Case " << cs << ": ";
    if (ans <= inf) {
      cout << (long long)ans << '\n';
    } else {
      cout << "Infinity\n";
    }
  }

  return 0;
}
