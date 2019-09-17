#define clz __builtin_clzll
#define lg(x) (63 - clz(x))

const int maxn = 100003;

int n, arr[maxn];
int st[maxn][lg(maxn) + 1];  // sparse table

// constrói a tabela em O(n lg n)
void build() {
  for (int i = 0; i < n; ++i)
    st[i][0] = arr[i];
  for (int j = 1; (1 << j) <= n; ++j)
    for (int i = 0; i + (1 << j) <= n; ++i)
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
} // ==> pode armazenar a posição ao invés do valor

// consulta O(1)
int qry(int i, int j) {
  int k = lg(j - i + 1);
  return min(st[i][k], st[j - (1 << k) + 1][k]);
}
