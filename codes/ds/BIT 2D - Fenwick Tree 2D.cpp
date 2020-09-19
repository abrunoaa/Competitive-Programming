const int maxn = 10003;
int ft[maxn][maxn];

void upd(int i, int j0, int x) {        // atualiza (i+, j0+) somando x
  for (; i < maxn; i += i & -i)
    for (int j = j0; j < maxn; j += j & -j)
      ft[i][j] += x;
}

int qry(int i, int j0) {                // retorna a soma de (i-, j0-)
  int s = 0;
  for (; i; i -= i & -i)
    for (int j = j0; j; j -= j & -j)
      s += ft[i][j];
  return s;
}
