/** retorna um fator não trivial (1 e n) de n, 0 se não existir **/
// o melhor depende de sorte ;)
ll floyd_pollard_rho(ll n){
  if(n <= 3 || millerRabin(n)) return 0;
  if(n % 2 == 0) return 2;
  ll rt = sqrt(n) + 1e-9;
  if(rt * rt == n) return rt;
  while(1){
    ll x = rand(), y = x, d = 1;
    while(d == 1){
      x = (mul(x, x, n) + 1) % n;
      y = (mul(y, y, n) + 1) % n;
      y = (mul(y, y, n) + 1) % n;
      d = gcd(n, abs(x - y));
    }
    if(d != n) return d;
  }
}

ll brent_pollard_rho1(ll n){
  if(n <= 3 || millerRabin(n)) return 0;
  if(n % 2 == 0) return 2;
  ll rt = sqrt(n) + 1e-9;
  if(rt * rt == n) return rt;
  while(1){
    ll x = rand(), y = x, d = 1;
    for(int i = 1; d == 1; ++i){
      x = (mul(x, x, n) + 1) % n;
      d = gcd(n, abs(x - y));
      if((i & (i - 1)) == 0) y = x;     // se i é uma potência de 2 (i = 2^k)
    }
    if(d != n && d != 1) return d;
  }
}

ll brent_pollard_rho2(ll n){
  if(n <= 3 || millerRabin(n)) return 0;
  if(n % 2 == 0) return 2;
  ll rt = sqrt(n) + 1e-9;
  if(rt * rt == n) return rt;
  int m;
  ll x, y, ys, q, g;
  do{
    m = rand() % 963 + 1;
    y = rand() % (n - 1) + 1;
    q = g = 1;
    for(int r = 1; g == 1; r *= 2){
      x = y;
      for(int i = 0; i < r; ++i) y = (mul(y, y, n) + 1) % n;
      for(int k = 0; k < r && g == 1; k += m){
        ys = y;
        for(int i = min(m, r - k); i; --i){
          y = (mul(y, y, n) + 1) % n;
          q = mul(q, abs(x - y), n);
        }
        g = gcd(q, n);
      }
    }
    if(g == n) do{
      ys = (mul(ys, ys, n) + 1) % n;
      g = gcd(n, abs(x - ys));
    } while(g == 1);
  } while(g == n);
  return g;
}
