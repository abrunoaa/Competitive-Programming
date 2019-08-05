#define eps 1e-9
#define maxn 100010

int n, arr[maxn];
int st[maxn][(int)log2(maxn) + 1];  // sparse table

// constrói a tabela em O(n lg n)
void build() {
  for (int i = 0; i < n; ++i) {
    st[i][0] = arr[i];
  }
  for (int j = 1; (1 << j) <= n; ++j)
    for (int i = 0; i + (1 << j) <= n; ++i) {
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
} // ==> pode armazenar a posição ao invés do valor

// consulta O(1)
int qry(int i, int j) {
  int k = log2(j - i + 1) + eps;
  return min(st[i][k], st[j - (1 << k) + 1][k]);
}
