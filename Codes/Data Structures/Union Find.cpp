#define maxn 100010

int n;        // nº de elementos
int p[maxn];  // vetor de pais
int s[maxn];  // tamanho do conjunto (apenas os pais / mais representativos)

// inicializa o union find
void build() {
  for (int i = 0; i < n; ++i) {
    p[i] = i;
    s[i] = 1;
  }
}

// retorna o pai de u (mais representativo)
int find(int u) {
  return (u == p[u] ? u : p[u] = find(p[u]));
}

// une os conjuntos que contem u e v
void unite(int u, int v) {
  u = find(u);
  v = find(v);
  if (u != v) {
    p[u] = v;
    s[v] += s[u];
  }
}
