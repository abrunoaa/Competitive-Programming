/// Merge Sort Tree

#define maxn 100010
#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)

typedef vector<int> vi;

int n, v[maxn];
vi st[4 * maxn];

// intercala x e y e salva em dest
void merge(vi& dest, const vi& x, const vi& y){
  merge(x.begin(), x.end(), y.begin(), y.end(), back_inserter(dest));
  // resize em dest se possível para otimizar
}

// constrói a árvore
vi& build(int k = 1, int l = 0, int r = n - 1){
  if(l == r)
    st[k].assign(1, v[l]);
  else
    merge(st[k], build(L, l, M), build(R, M+1, r));
  return st[k];
}

// retorna qtd de nº entre i e j menores que x
int qry(int i, int j, int x, int k = 1, int l = 0, int r = n - 1){
  if(r < i || j < l) return 0;
  if(i <= l && r <= j) return lower_bound(st[k].begin(), st[k].end(), x) - st[k].begin();
  return qry(i, j, x, L, l, M) + qry(i, j, x, R, M+1, r);
}

/// k-ésimo ==> cria o par ii(valor, posição), ordena e cria a árvore usando a posição
int qry(int i, int j, int kth, int k = 1, int l = 0, int r = n - 1){
  if(l == r) return st[k][0];

  int nl = upper_bound(st[R].begin(), st[R].end(), i) - lower_bound(st[L].begin(), st[L].end(), i);
  if(kth <= nl) return qry(i, j, kth, L, l, M);
  return qry(i, j, kth - nl, R, M + 1, r);
}
