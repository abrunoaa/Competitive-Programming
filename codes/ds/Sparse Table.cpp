#define lg(x) (63 - __builtin_clzll(x))

const int maxn = 100003;

int n, a[maxn];
int st[lg(maxn) + 1][maxn];  // sparse table

// constrói a tabela em O(n lg n)
void build() {
  for (int i = 0; i < n; ++i)
    st[0][i] = a[i];
  for (int j = 1; (1 << j) <= n; ++j)
    for (int i = 0; i + (1 << j) <= n; ++i)
      st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
} // ==> pode armazenar a posição ao invés do valor

// consulta O(1)
int qry(int i, int j) {
  int k = lg(j - i + 1);
  return min(st[k][i], st[k][j - (1 << k) + 1]);
}
