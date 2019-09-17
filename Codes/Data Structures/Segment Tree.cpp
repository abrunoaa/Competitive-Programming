#define L (2 * t)
#define R (L + 1)
#define M ((l + r) / 2)

typedef int no;               // depende da aplicação

const int maxn = 100003;

int n, arr[maxn];
no st[4 * maxn];    // segtree

// une dois nós da segtree (push up)
inline no merge(no x, no y) { return x + y; }

// constrói a árvore
no build(int t = 1, int l = 0, int r = n - 1) {
  if (l == r) return st[t] = arr[l];
  return st[t] = merge(build(L, l, M), build(R, M + 1, r));
}

// atualiza a posição i por x
no upd(int i, int x, int t = 1, int l = 0, int r = n - 1) {
  if (r < i || i < l) return st[t];
  if (l == r) return st[t] = x;
  return st[t] = merge(upd(i, x, L, l, M), upd(i, x, R, M + 1, r));
}

// consulta entre [i, j]
no qry(int i, int j, int t = 1, int l = 0, int r = n - 1) {
  if (r < i || j < l) return 0;
  if (i <= l && r <= j) return st[t];
  return merge(qry(i, j, L, l, M), qry(i, j, R, M + 1, r));
}
