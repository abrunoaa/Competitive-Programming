/// BIT 2D - Fenwick Tree 2D

#define maxn 10010

int ft[maxn][maxn];

// atualiza (i+, j0+) somando x; O(lg²n)
void upd(int i, int j0, int x){
  for(; i < maxn; i += i & -i)
    for(int j = j0; j < maxn; j += j & -j)
      ft[i][j] += x;
}

// retorna a soma de (i-, j0-); O(lg²n)
int qry(int i, int j0){
  int s = 0;
  for(; i; i -= i & -i)
    for(int j = j0; j; j -= j & -j)
      s += ft[i][j];
  return s;
}
