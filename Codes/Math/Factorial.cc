typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;

// retorna quantos zeros a direita tem em n!
int ctzFact(int n){           // O(log_5(n))
  int z = 0;
  for(int k = 5; k <= n; k *= 5) z += n / k;
  return z;
}

// retorna quantos zeros a direita tem em n! na base b
// b = p1^e1 * p2^e2 * ...
// z = min((n/p1 + n/p1^2 + ...)/e1, (n/p2 + n/p2^2 + ...)/e2, ...)
int ctzFact(int n, int b){    // O(b) ==> pode otimizar percorrendo apenas primos
  int z = 1e9;
  for(int p = 2; p <= b; ++p) if(b % p == 0){
    int e = 0, s = 0;
    for(; b % p == 0; b /= p) ++e;
    for(int k = n; k / p; k /= p) s += k / p;
    z = min(z, s / e);
  }
  return z;
}

// retorna qtos dígitos tem em n! na base b
// ans = 1 + log(n!) / log(b) = 1 + (log(2) + log(3) + ... + log(n)) / log(b)
// n! ≃ sqrt(2pi * n) * (n/e)^n
int digitsFact(int n, int b){
  double d = 0.0;
  for(int i = 2; i <= n; ++i) d += log(i);
  return 1 + (int)(d / log(b) + 1e-9);

  // aproximação (bom para b = 10):
  return 1 + (int)(((n + .5) * log(n) + log(2 * acos(-1)) * .5 - n) / log(b) + 1e-9);
}

// retorna o último dígito != 0 em n!
int lastDigit(int n){
  static int x[] = {1,1,2,6,4};
  static int y[] = {6,2,4,8};

  int ans = 1;
  while(n >= 5){
    ans = ans * y[n / 5 % 4] * x[n % 5] % 10;
    n /= 5;
  }
  return ans * x[n] % 10;
}

// fatora n! em primos de forma fácil de codar
vii factorialFactors(int n){            // Legendre's Theorem
  vii f;
  for(int p : primes){
    if(p > n)
      break;

    int e = 0;
    for(ll k = p; k <= n; k *= p)
      e += n / k;
    f.push_back(ii(p, e));
  }
  return f;
}

/** Coeficientes Binomiais **/
#define maxn 100010
#define mod 1000000007

int fat[maxn], finv[maxn];

// combinação
int nCr(int n, int r){
  return (ll)fat[n] * finv[r] % mod * finv[n - r] % mod;
  return fat[n] / (fat[r] * fat[n - r]);  // se n! não estourar
}

// combinação: versão iterativa
int nCr_iterative(int n, int r){
  int c = 1;
  r = min(r, n - r);
  for(int i = 0; i < r; ++i) c = c * (n - i) / (i + 1);
  return c;
}

// triângulo de pascal tem complexidade O(n²)
#define maxn 10010

vector<int> C[maxn];

// maxn = 33, se for int ou maxn = 66, se for long long (sem mod)
void pascal(){
  C[0].assign(1, 1);
  for(int i = 1; i < maxn; ++i){
    C[i].resize(i + 1);
    C[i][0] = C[i][i] = 1;
    for(int j = 1; j < i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  }
}
