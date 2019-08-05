#define maxp 100010

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<int> primes;
bitset<maxp> isp;

bool isprime_slow(int n) {    // O(sqrt(n) / 2)
  if (n < 2 || n % 2 == 0) { return 0; }
  for (int i = 3; i * i <= n; i += 2)
    if (n % i == 0) {
      return 0;
    }
  return 1;
}

bool isprime_fast(int n) {    // O(sqrt(n) / 3)
  if (n < 5 || n % 2 == 0 || n % 3 == 0) {
    return (n == 2 || n == 3);
  }
  for (int i = 5, k = sqrt(n) + 1e-9; i <= k; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) {
      return 0;
    }
  return 1;
}

bool isprime(int n) {             // O(sqrt(n) / ln(sqrt(n)))
  if (n < maxp) { return isp[n]; }    // bitset usado no crivo (sieve)
  for (int p : primes) {
    if ((ll)p * p > n) { return 1; }
    if (n % p == 0) { return 0; }
  }
  assert(0);
}

vii primeFactors(int n) {     // O(sqrt(n) / ln(sqrt(n)))
  vii f;
  for (int p : primes) {
    if ((ll)p * p > n) {
      break;
    }
    if (n % p == 0) {
      int e = 0;
      while (n % p == 0) {
        n /= p;
        ++e;
      }
      f.push_back(ii(p, e));
    }
  }
  if (n > 1) { f.push_back(ii(n, 1)); }
  return f;
}

// nº de fatores primos -- 12 = 2 * 2 * 3 ==> npf = 3
int npf(int n) {              // O(sqrt(n) / ln(sqrt(n)))
  int ans = 0;
  for (int p : primes) {
    if ((ll)p * p > n) {
      break;
    }
    while (n % p == 0) {
      n /= p;
      ++ans;
    }
  }
  if (n > 1) { ++ans; }
  return ans;
}

// nº de fatores primos distintos
int ndpf(int n) {             // O(sqrt(n) / ln(sqrt(n)))
  int ans = 0;
  for (int p : primes) {
    if ((ll)p * p > n) {
      break;
    }
    if (n % p == 0) {
      ++ans;
      while (n % p == 0) { n /= p; }
    }
  }
  if (n > 1) { ++ans; }
  return ans;
}

// nº de divisores de n
int ndiv(int n) {             // O(sqrt(n) / ln(sqrt(n)))
  int ans = 1;
  for (int p : primes) {
    if ((ll)p * p > n) {
      break;
    }
    if (n % p == 0) {
      int e = 1;
      while (n % p == 0) {
        n /= p;
        ++e;
      }
      ans *= e;
    }
  }
  if (n > 1) { ans *= 2; }
  return ans;
}

// soma dos divisores de n
int sigma(int n) {            // O(sqrt(n) / ln(sqrt(n)))
  int ans = 1;
  for (int p : primes) {
    if ((ll)p * p > n) {
      break;
    }
    if (n % p == 0) {
      int q = p;
      while (n % p == 0) {
        n /= p;
        q *= p;
      }
      ans *= (q - 1) / (p - 1);
    }
  }
  if (n > 1) { ans *= n + 1; }
  return ans;
}

// nº de coprimos (< n) com n (Euler phi / totient function)
int phi(int n) {              // O(sqrt(n) / ln(sqrt(n)))
  int ans = n;
  for (int p : primes) {
    if ((ll)p * p > n) {
      break;
    }
    if (n % p == 0) {
      ans -= ans / p;
      while (n % p == 0) { n /= p; }
    }
  }
  if (n > 1) { ans -= ans / n; }
  return ans;
}
