/// Split-Merge Segment Tree

#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define maxs (25 * maxn)
#define L lc[k]
#define R rc[k]
#define M ((l + r) / 2)

struct SegmentTree{ // multi-multiset
  int n, cnt, nroot, root[maxn];
  int sz[maxs], lc[maxs], rc[maxs];

  SegmentTree() {}
  SegmentTree(int n) : n(n), cnt(0), nroot(0) {}

  int mk(int n){  // "aloca" um novo nó com n elementos
    lc[cnt] = rc[cnt] = -1;
    sz[cnt] = n;
    return cnt++;
  }

  // cria um novo set com apenas o elemento i
  int build(int i, int l, int r){
    int t = mk(1);
    if(l == r) return t;
    if(i <= M) lc[t] = build(i, l, M);
    else rc[t] = build(i, M + 1, r);
    return t;
  }
  int newSet(int i){
    root[nroot] = build(i, 0, n - 1);
    return nroot++;
  }

  // splita r1, deixando com os k primeiros elementos retorna a nova raíz r2
  /// \warning retorna -1 se a raíz não foi criada!!!
  int split(int r1, int k){
    if(r1 == -1 || sz[r1] <= k) return -1;  // atingiu a meta
    int r2 = mk(sz[r1] - k);                // move o excedente para r2
    sz[r1] = k;                             // mantém k
    int sl = lc[r1] == -1 ? 0 : sz[lc[r1]];

    // move o excedente do filho direito
    if(sl < k) rc[r2] = split(rc[r1], k - sl);
    else swap(rc[r1], rc[r2]);

    // move o excedente do filho esquerdo
    if(sl > k) lc[r2] = split(lc[r1], k);

    return r2;
  }
  int splitSet(int r, int k){
    assert(k >= 0);
    assert(r != -1);
    if(k >= sz[root[r]]) return -1;   // todos continuam em r
    if(k == 0){                       // todos saem de r
      root[nroot] = root[r];
      root[r] = -1;
    }
    else{                             // splita
      root[nroot] = split(root[r], k);
    }
    return nroot++;
  }

  // move os elementos da raíz r2 para r1
  /// \warning r2 não pode mais ser usado!!!
  int move(int r1, int r2){
    if(r1 == -1) return r2;
    if(r2 == -1) return r1;
    lc[r1] = move(lc[r1], lc[r2]);
    rc[r1] = move(rc[r1], rc[r2]);
    sz[r1] += sz[r2];
    return r1;
  }
  void merge(int r1, int r2){
    assert(root[r1] != -1 && root[r2] != -1);
    root[r1] = move(root[r1], root[r2]);
    root[r2] = -1;
  }

  // retorna qtos elementos entre i e j estão na sub-árvore na raíz k
  int qry(int i, int j, int k, int l, int r){
    if(k == -1 || r < i || j < l) return 0;
    if(i <= l && r <= j) return sz[k];
    return qry(i, j, L, l, M) + qry(i, j, R, M + 1, r);
  }
  int qry(int i, int j, int r){ return qry(i, j, root[r], 0, n - 1); }

  // retorna o i-ésimo elemento de k (i = [0 .. sz(k)-1])
  int at(int i, int k, int l, int r){
    assert(i < sz[k]);
    if(l == r) return l;
    int sl = lc[k] == -1 ? 0 : sz[L];
    if(i < sl) return at(i, L, l, M);
    return at(i - sl, R, M + 1, r);
  }
  int at(int i, int r){ return at(i, root[r], 0, n - 1); }

  // imprime os elementos da raiz r em ordem
  void print(int k, int l, int r){
    if(k == -1) return;
    print(L, l, M);
    print(R, M + 1, r);
    if(l == r) cout << l << ' ';
  }
  void print(int r){
    print(root[r], 0, n - 1);
    cout << endl;
  }
};

const int n = 10;
int r[n * 10];
SegmentTree st(n);

int main(){
  for(int i = 0; i < n; ++i){
    r[i] = st.newSet(i);
  }

  st.merge(r[5], r[7]);
  st.merge(r[0], r[5]);
  st.print(r[0]);

  r[n] = st.splitSet(r[0], 3);

  st.print(r[0]);
  st.print(r[n]);

  return 0;
}
