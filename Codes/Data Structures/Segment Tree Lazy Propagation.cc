#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)
#define maxn 100010

typedef int no;               // depende da aplicação

int n, arr[maxn];
int lz[4 * maxn];   // lazy
no st[4 * maxn];    // segtree

// une dois nós da segtree (push up)
inline no merge(no x, no y){ return x + y; }

// constrói a árvore
no build(int k = 1, int l = 0, int r = n - 1){
  if(l == r) return st[k] = arr[l];
  return st[k] = merge(build(L, l, M), build(R, M+1, r));
}

// propaga a preguiça no nó k
void prop(int k, bool child){
  int &l = lz[k];
  if(l){            // se tem preguiça
    st[k] += l;     // atualiza
    if(child){      // e joga para os filhos
      lz[L] += l;
      lz[R] += l;
    }
    l = 0;
  }
}

// atualiza o intervalo [i, j] em +x
no upd(int i, int j, int x, int k = 1, int l = 0, int r = n - 1){
  if(i <= l && r <= j){
    lz[k] += x;
    prop(k, r - l);
    return st[k];
  }
  prop(k, r - l);
  if(r < i || j < l) return st[k];
  return st[k] = merge(upd(i, j, x, L, l, M), upd(i, j, x, R, M+1, r));
}

// consulta entre [i, j]
no qry(int i, int j, int k = 1, int l = 0, int r = n - 1){
  if(r < i || j < l) return 0;
  prop(k, r - l);
  if(i <= l && r <= j) return st[k];
  return merge(qry(i, j, L, l, M), qry(i, j, R, M+1, r));
}
