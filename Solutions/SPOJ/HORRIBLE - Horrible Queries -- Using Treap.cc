#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define maxalloc maxn // nº máximo de nós alocados durante toda execução

typedef int Int;
#define int long long

struct no{
  int pri;  // prioridade
  int size; // qtde de elementos na sub-árvore
  int val;  // valor do nó
  int sum;  // soma do intervalo
  int lz; // lazy
  no *l, *r;

  no() {}
  no(int x) : pri(rand()), size(1), val(x), sum(x), lz(0), l(0), r(0) {}

  static no* pnew;
  static void* operator new(size_t){ return pnew++; }
};

no alloc[maxalloc];
no* no::pnew = alloc;

struct treap{ // indexado em 0
  no* root = 0;

  ~treap(){ clear(); }
  void clear(){
    root = 0;
    no::pnew = alloc; /// ********** ESSA LINHA "ESTRAGA" TODAS AS TREAPS!!! **********
  }

  inline int size(no* t){ return (t ? t->size : 0); }

  inline void upd(no* t){ // atualiza o intervalo
    if(!t) return;
    prop(t->l), prop(t->r);
    t->size = 1 + size(t->l) + size(t->r);
    t->sum = t->val;
    t->sum += (t->l ? t->l->sum : 0);
    t->sum += (t->r ? t->r->sum : 0);
  }

  void prop(no* t){
    if(!t) return;
    if(t->lz){  // propaga lazy
      int &lz = t->lz;
      t->val += lz;
      t->sum += lz * t->size;
      if(t->l) t->l->lz += lz;
      if(t->r) t->r->lz += lz;
      lz = 0;
    }
  }

  void split(no* t, no*& l, no*& r, int pos){ // divide t em l = [0 .. pos] e r = [pos+1 .. n-1]
    prop(t);
    if(!t) l = r = 0;
    else if(size(t->l) <= pos) split(t->r, t->r, r, pos - 1 - size(t->l)), l = t;
    else split(t->l, l, t->l, pos), r = t;
    upd(t);
  }

  void merge(no*& t, no* l, no* r){ // junta l e r, armazenando em t (l < r)
    prop(l), prop(r);
    if(!l) t = r;
    else if(!r) t = l;
    else if(l->pri > r->pri) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    upd(t);
  }

  void insert(int i, int x){  // insere x entre i-1 e i
    no *l, *r, *tmp;
    split(root, l, r, i - 1);
    merge(tmp, l, new no(x));
    merge(root, tmp, r);
  }

  void upd(int i, int j, int x){  // add +x from i to j
    no *l, *tmp, *r;
    split(root, l, tmp, i - 1);
    split(tmp, root, r, j - i);
    root->lz += x;
    merge(tmp, l, root);
    merge(root, tmp, r);
  }

  int qry(int i, int j){  // sum from i to j
    no *l, *tmp, *r;
    split(root, l, tmp, i - 1);
    split(tmp, root, r, j - i);
    int ans = root->sum;
    merge(tmp, l, root);
    merge(root, tmp, r);
    return ans;
  }
};

Int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n, c;
    cin >> n >> c;

    treap t;
    for(int i = 0; i < n; ++i){
      t.insert(0, 0);
    }

    while(c--){
      int op, p, q, v;
      cin >> op >> p >> q, --p, --q;
      if(p > q) swap(p, q);
      if(op == 0){
        cin >> v;
        t.upd(p, q, v);
      }
      else{
        cout << t.qry(p, q) << '\n';
      }
    }
  }

  return 0;
}
