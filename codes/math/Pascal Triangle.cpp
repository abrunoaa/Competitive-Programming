vector<int> C[maxn];

void pascal() {   // maxn = 33, se for int ou maxn = 66, se for long long (sem mod)
  C[0].assign(1, 1);
  for (int i = 1; i < maxn; ++i) {
    C[i].resize(i + 1);
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  }
}
