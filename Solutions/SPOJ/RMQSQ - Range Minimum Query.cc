#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define maxalloc (100 * maxn) // nº máximo de nós alocados durante toda execução

struct no{
  int pri;  // prioridade
  int size; // qtde de elementos na sub-árvore
  int val;  // valor do nó
  int sum;  // soma do intervalo
  int lz; // lazy
  bool reverse; // flag para inverter o intervalo (reverse)
  no *l, *r;

  no() {}
  no(int x) : pri(rand()), size(1), val(x), sum(x), lz(0), reverse(0), l(0), r(0) {}

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
    if(t->l) t->sum = min(t->sum, t->l->sum);
    if(t->r) t->sum = min(t->sum, t->r->sum);
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
    if(t->reverse){ // propaga inversão
      swap(t->l, t->r);
      if(t->l) t->l->reverse ^= 1;
      if(t->r) t->r->reverse ^= 1;
      t->reverse = 0;
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

  void erase(int i){  // remove da posição i (move os outros para trás)
    no *l, *r, *tmp, *del;
    split(root, l, tmp, i - 1);
    split(tmp, del, r, 0);
    merge(root, l, r);
    // delete del;
  }

  void replace(int i, int x){ // replace value at i by x
    no *l, *tmp, *r;
    split(root, l, tmp, i - 1);
    split(tmp, root, r, 0);
    *root = no(x);
    merge(tmp, l, root);
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

  void print(){ cout<<" --- ROOT = "<<root->val<<endl; print(root); cout<<" +++"<<endl; }
  void print(no* r){
    if(r){
      print(r->l);
      cout << r->val << ' ' << r->sum << ' ' << r->size;
      if(r->l) cout << "; L = " << r->l->val;
      if(r->r) cout << "; R = " << r->r->val;
      cout << endl;
      print(r->r);
    }
  }
};

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;

  treap t;
  for(int i = 0; i < n; ++i){
    int x;
    cin >> x;
    t.insert(i, x);
  }

  int q;
  cin >> q;
  while(q--){
    int i, j;
    cin >> i >> j;
    cout << t.qry(i, j) << '\n';
  }

  return 0;
}
