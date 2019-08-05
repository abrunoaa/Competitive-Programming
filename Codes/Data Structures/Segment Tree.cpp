#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)
#define maxn 100010

typedef int no;               // depende da aplicação

int n, arr[maxn];
no st[4 * maxn];    // segtree

// une dois nós da segtree (push up)
inline no merge(no x, no y) { return x + y; }

// constrói a árvore
no build(int k = 1, int l = 0, int r = n - 1) {
  if (l == r) { return st[k] = arr[l]; }
  return st[k] = merge(build(L, l, M), build(R, M + 1, r));
}

// atualiza a posição i por x
no upd(int i, int x, int k = 1, int l = 0, int r = n - 1) {
  if (r < i || i < l) { return st[k]; }
  if (l == r) { return st[k] = x; }
  return st[k] = merge(upd(i, x, L, l, M), upd(i, x, R, M + 1, r));
}

// consulta entre [i, j]
no qry(int i, int j, int k = 1, int l = 0, int r = n - 1) {
  if (r < i || j < l) { return 0; }
  if (i <= l && r <= j) { return st[k]; }
  return merge(qry(i, j, L, l, M), qry(i, j, R, M + 1, r));
}
