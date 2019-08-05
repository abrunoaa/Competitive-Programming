#define maxn 100010
#define L (2 * t)
#define R (L + 1)
#define M ((l + r) / 2)
#define ub(v, x) (int)(upper_bound(v.begin(), v.end(), x) - v.begin())
#define lb(v, x) (int)(lower_bound(v.begin(), v.end(), x) - v.begin())

typedef vector<int> vi;

int n, v[maxn];
vi st[4 * maxn];

// intercala x e y e salva em dest
void merge(vi &dest, const vi &x, const vi &y) {
  dest.resize(x.size() + y.size());
  merge(x.begin(), x.end(), y.begin(), y.end(), dest.begin());
}

// constrói a árvore
vi &build(int t = 1, int l = 0, int r = n - 1) {
  if (l == r) { st[t].assign(1, v[l]); }
  else { merge(st[t], build(L, l, M), build(R, M + 1, r)); }
  return st[t];
}

// retorna qtd de nº entre i e j menores que x
int qry(int i, int j, int x, int t = 1, int l = 0, int r = n - 1) {
  if (r < i || j < l) { return 0; }
  if (i <= l && r <= j) { return lb(st[t], x); }
  return qry(i, j, x, L, l, M) + qry(i, j, x, R, M + 1, r);
}

int numLess(int i, int j, int x, int t = 1, int l = 0, int r = n - 1) {
  if (r < i || j < l) { return 0; }
  if (i <= l && r <= j) { return ub(st[t], x); }
  return numLess(i, j, x, L, l, M) + numLess(i, j, x, R, M + 1, r);
}

// >> k-ésimo de uma sequência:
//   > cria o par ii(valor, posição), ordena por valor e cria a posição
int qry(int i, int j, int k, int t = 1, int l = 0, int r = n - 1) {
  if (l == r) { return st[t][0]; }
  int nl = ub(st[R], i) - lb(st[L], i);
  if (k <= nl) { return qry(i, j, k, L, l, M); }
  return qry(i, j, k - nl, R, M + 1, r);
}
