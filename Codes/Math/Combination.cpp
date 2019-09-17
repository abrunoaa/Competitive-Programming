int fat[maxn], finv[maxn];

int nCr(int n, int r) {       // combinação
  return (ll)fat[n] * finv[r] % mod * finv[n - r] % mod;
  return fat[n] / (fat[r] * fat[n - r]);  // se n! não estourar
}

int nCr_iterative(int n, int r) {       // combinação: versão iterativa
  int c = 1;
  r = min(r, n - r);
  for (int i = 0; i < r; ++i) c = c * (n - i) / (i + 1);
  return c;
}
