int n, m;                     // itens, tamanho da mochila
int v[maxn], w[maxn];         // valor, peso
int dp[maxm];

void knapsack() {
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < n; ++i) {
    int v = ::v[i], w = ::w[i];
    for (int j = m; j >= w; --j) {
      dp[j] = max(dp[j], dp[j - w] + v);
    }
  }
}

/// knapsack 0-1 apenas w com remoção (probabilístico)
#define mod int(1e9 + 7) // menos chance de dar errado: usar vários primos

void weigthOnly_and_remove() {
  memset(dp, 0, sizeof dp);
  dp[0] = 1;                              // dp[j] != 0 -> o peso é possível
  for (int i = 0; i < n; ++i) {
    int w = ::w[i];
    for (int j = m; j >= w; --j) {
      dp[j] = (dp[j] + dp[j - w]) % mod;  // n° de maneiras de conseguir peso j
    }
  }
}

void remove(int i) { // assume que i está na mochila
  // remove todas as combinações que o item i adiciona
  int w = ::w[i];
  for (int j = w; j <= m; ++j) {
    dp[j] = (dp[j] - dp[j - w] + mod) % mod;
  }
}
