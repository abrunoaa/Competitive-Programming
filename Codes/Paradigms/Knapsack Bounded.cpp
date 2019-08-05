template<class T> struct MaxQueue {
  int n;
  T lazy;
  deque<pair<T, int>> q;
  MaxQueue() : n(0), lazy(0), q() {}

  int size() { return n; }
  void clear() { n = 0; lazy = 0; q.clear(); }
  void push(T x) {
    ++n;
    x -= lazy;
    int k = 1;
    for (; !q.empty() && q.back().st <= x; q.pop_back()) { k += q.back().nd; }
    q.push_back({x, k});
  }
  void pop() { --n; if (!--q.front().nd) q.pop_front(); }
  void add(T x) { lazy += x; }
  T front() { return q.front().st + lazy; }
};

int n, m;// itens, tamanho da mochila
int v[maxn], w[maxn], b[maxn];// valor, peso, nº de repetições
int dp[maxm];
MaxQueue<int> q[maxm];

// knapsack com b[i] repetições do item i
void boundedKnapsack() {
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < n; ++i) {
    int v = ::v[i], w = ::w[i], b = ::b[i];
    for (int j = 0; j < w; ++j) { q[j].clear(), q[j].push(dp[j]); }
    for (int j = w; j <= m; ++j) {
      auto &p = q[j % w];
      if (p.size() > b) { p.pop(); }
      p.add(v);
      p.push(dp[j]);
      dp[j] = p.front();
    }
  }
}

/// checa se um peso pode ser atingido na mochila
void boundedKnapsack_weigthOnly() {
  memset(dp, 0, sizeof dp);
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    int w = ::w[i], b = ::b[i];// se w repetir, soma os b's
    for (int j = m - w; j >= 0; --j)
      if (dp[j])
        for (int k = 1; k <= b && j + k * w <= m && !dp[j + k * w]; ++k) {
          dp[j + k * w] = 1;
        }
  }
}
