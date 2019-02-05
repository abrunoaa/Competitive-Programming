#define maxp 100010

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<int> primes;
bitset<maxp> isp;

// checa se n é primo
bool isprime_slow(int n){     // O(sqrt(n) / 2)
  if(n < 2 || n % 2 == 0) return 0;
  for(int i = 3; i * i <= n; i += 2)
    if(n % i == 0)
      return 0;
  return 1;
}

// checa se n é primo
bool isprime_fast(int n){     // O(sqrt(n) / 3)
  if(n < 5 || n % 2 == 0 || n % 3 == 0)
    return (n == 2 || n == 3);
  for(int i = 5, k = sqrt(n) + 1e-9; i <= k; i += 6)
    if(n % i == 0 || n % (i + 2) == 0)
      return 0;
  return 1;
}

// checa se n é primo usando primos <= sqrt(n)
bool isprime(int n){              // O(sqrt(n) / ln(sqrt(n)))
  if(n < maxp) return isp[n];     // bitset usado no crivo (sieve)
  for(int p : primes){
    if((ll)p * p > n) return 1;
    if(n % p == 0) return 0;
  }
  assert(0);
}

// checa se n é primo
// O(k * log²(n)) ou se usar modMul O(k * log³(n)), k = qtd de primos testados
bool millerRabin(ll n){
  // n <  4e9: bases[] = {2, 7, 61}
  // n < 3e23: bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}
  const char bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};  // se n < 3e18

  for(int p : bases)                    // para não falhar para as bases tentadas
    if(n % p == 0)
      return n == p;

  ll d = n - 1;
  int r = __builtin_ctzll(d);
  d >>= r;

  for(int b : bases){
    ll x = mpow(b, d, n);               // b ** d % n
    if(x == 1 || x == n - 1)
      continue;
    for(int i = 1; i < r && x > 1 && x < n - 1; ++i)
      x = mpow(x, 2, n);                // x * x % n -- pode precisar de modMul
    if(x != n - 1)
      return 0;
  }
  return 1;
}

// fatora n em primos
vii factors(int n){           // O(sqrt(n) / ln(sqrt(n)))
  vii f;
  for(int p : primes){
    if((ll)p * p > n)
      break;
    if(n % p == 0){
      int e = 0;
      while(n % p == 0){
        n /= p;
        ++e;
      }
      f.push_back(ii(p, e));
    }
  }
  if(n > 1)
    f.push_back(ii(n, 1));
  return f;
}

// nº de fatores primos -- 12 = 2² * 3¹ ==> npf = 3
int npf(int n){               // O(sqrt(n) / ln(sqrt(n)))
  int ans = 0;
  for(int p : primes){
    if((ll)p * p > n)
      break;
    while(n % p == 0){
      n /= p;
      ++ans;
    }
  }
  if(n > 1) ++ans;
  return ans;
}

// nº de fatores primos distintos
int ndpf(int n){              // O(sqrt(n) / ln(sqrt(n)))
  int ans = 0;
  for(int p : primes){
    if((ll)p * p > n)
      break;
    if(n % p == 0){
      ++ans;
      while(n % p == 0) n /= p;
    }
  }
  if(n > 1) ++ans;
  return ans;
}

// nº de divisores de n
int ndiv(int n){              // O(sqrt(n) / ln(sqrt(n)))
  int ans = 1;
  for(int p : primes){
    if((ll)p * p > n)
      break;
    if(n % p == 0){
      int e = 1;
      while(n % p == 0){
        n /= p;
        ++e;
      }
      ans *= e;
    }
  }
  if(n > 1) ans *= 2;
  return ans;
}

// soma dos divisores de n
int sumDiv(int n){            // O(sqrt(n) / ln(sqrt(n)))
  int ans = 1;
  for(int p : primes){
    if((ll)p * p > n)
      break;
    if(n % p == 0){
      int e = 1;
      while(n % p == 0){
        n /= p;
        ++e;
      }
      ans *= ((int)pow(p, e) - 1) / (p - 1);
    }
  }
  if(n > 1) ans *= n + 1;
  return ans;
}

// nº de coprimos (< n) com n (Euler phi / totient function)
int phi(int n){               // O(sqrt(n) / ln(sqrt(n)))
  int ans = n;
  for(int p : primes){
    if((ll)p * p > n)
      break;
    if(n % p == 0){
      ans -= ans / p;
      while(n % p == 0) n /= p;
    }
  }
  if(n > 1) ans -= ans / n;
  return ans;
}
