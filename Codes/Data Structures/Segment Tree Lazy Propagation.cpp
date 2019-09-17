#define L (2 * t)
#define R (L + 1)
#define M ((l + r) / 2)

typedef int no;               // depende da aplicação

const int maxn = 100003;

int n, arr[maxn];
int lz[4 * maxn];   // lazy
no st[4 * maxn];    // segtree

// une dois nós da segtree (push up)
inline no merge(no x, no y) { return x + y; }

// constrói a árvore
no build(int t = 1, int l = 0, int r = n - 1) {
  if (l == r) return st[t] = arr[l];
  return st[t] = merge(build(L, l, M), build(R, M + 1, r));
}

// propaga a preguiça no nó t
void prop(int t, bool child) {
  int &l = lz[t];
  if (l) {          // se tem preguiça
    st[t] += l;     // atualiza
    if (child) {    // e joga para os filhos
      lz[L] += l;
      lz[R] += l;
    }
    l = 0;
  }
}

// atualiza o intervalo [i, j] em +x
no upd(int i, int j, int x, int t = 1, int l = 0, int r = n - 1) {
  if (i <= l && r <= j) {
    lz[t] += x;
    prop(t, r - l);
    return st[t];
  }
  prop(t, r - l);
  if (r < i || j < l) return st[t];
  return st[t] = merge(upd(i, j, x, L, l, M), upd(i, j, x, R, M + 1, r));
}

// consulta entre [i, j]
no qry(int i, int j, int t = 1, int l = 0, int r = n - 1) {
  if (r < i || j < l) return 0;
  prop(t, r - l);
  if (i <= l && r <= j) return st[t];
  return merge(qry(i, j, L, l, M), qry(i, j, R, M + 1, r));
}
