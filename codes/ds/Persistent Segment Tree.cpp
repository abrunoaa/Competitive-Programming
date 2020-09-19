const int maxn = 100003;
const int maxq = 100003;
const int maxs = 2 * maxn + maxq * ((int)log2(maxn) + 1);   // 2n + q*lg n

#define M ((l + r) / 2)

int n, arr[maxn];
int root[maxq];             // raízes das versões
int nno;                    // nº de nós "alocados"
int st[maxs];               // segtree
int lc[maxs], rc[maxs];     // filhos da esquerda(lc) e direita(rc)

// cria uma cópia do nó v em uma nova posição, salvando em u
int copy(int &u) {
  lc[nno] = lc[u];
  rc[nno] = rc[u];
  st[nno] = st[u];
  return u = nno++;
}

int build(int t = root[0], int l = 1, int r = n) {
  if (l == r) return st[t] = arr[l];
  lc[t] = nno++;
  rc[t] = nno++;
  return st[t] = build(lc[t], l, M) + build(rc[t], M + 1, r);
}

int upd(int i, int x, int &t, int l = 1, int r = n) {
  copy(t);
  if (l == r) return st[t] += x;
  if (i <= M) return st[t] = upd(i, x, lc[t], l, M) + st[rc[t]];
  return st[t] = st[lc[t]] + upd(i, x, rc[t], M + 1, r);
}

int qry(int i, int j, int t, int l = 1, int r = n) {
  if (r < i || j < l) return 0;
  if (i <= l && r <= j) return st[t];
  return qry(i, j, lc[t], l, M) + qry(i, j, rc[t], M + 1, r);
}
