#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 100010
#define maxalloc (2 * maxn) // nº máximo de nós alocados durante toda execução

struct no{
  int pri;  // prioridade
  int size; // qtde de elementos na sub-árvore
  int val;  // valor do nó
  int minVal;  // soma do intervalo
  int lz; // lazy
  bool reverse; // flag para inverter o intervalo (reverse)
  no *l, *r;

  no() {}
  no(int x) : pri(rand()), size(1), val(x), minVal(x), lz(0), reverse(0), l(0), r(0) {}

  static no* pnew;
  static void* operator new(size_t){ return pnew++; }
};

no alloc[maxalloc];
no* no::pnew = alloc;

struct treap{ // indexado em 0
  no* root;

  treap() : root(0) {}
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
    t->minVal = t->val;
    if(t->l) t->minVal = min(t->minVal, t->l->minVal);
    if(t->r) t->minVal = min(t->minVal, t->r->minVal);
  }

  void prop(no* t){
    if(!t) return;
    if(t->lz){  // propaga lazy
      int &lz = t->lz;
      t->val += lz;
      t->minVal += lz;
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

  void reverse(int i, int j){
    no *l, *tmp, *r;
    split(root, l, tmp, i - 1);
    split(tmp, root, r, j - i);
    root->reverse ^= 1;
    merge(tmp, l, root);
    merge(root, tmp, r);
  }

  void add(int i, int j, int x){  // add +x from i to j
    no *l, *tmp, *r;
    split(root, l, tmp, i - 1);
    split(tmp, root, r, j - i);
    root->lz += x;
    merge(tmp, l, root);
    merge(root, tmp, r);
  }

  int qry(int i, int j){  // minVal from i to j
    no *l, *tmp, *r;
    split(root, l, tmp, i - 1);
    split(tmp, root, r, j - i);
    int minVal = root->minVal;
    merge(tmp, l, root);
    merge(root, tmp, r);
    return minVal;
  }

  void revolve(int i, int j, int k){
    k %= j - i + 1;
    no *l, *tmp, *r;
    split(root, l, tmp, i - 1);
    split(tmp, root, r, j - i);
    no *a, *b;
    split(root, a, b, j - i - k);
    merge(root, b, a);
    merge(tmp, l, root);
    merge(root, tmp, r);
  }
};

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  srand(0);

  int n;
  cin >> n;

  treap t;
  for(int i = 0; i < n; ++i){
    int x;
    cin >> x;
    t.insert(i, x);
  }

  int m;
  cin >> m;
  while(m--){
    char s[30];
    int x, y, z;
    cin >> s >> x;
    if(!strcmp(s, "DELETE")) t.erase(x - 1);
    else{
      cin >> y;
      if(!strcmp(s, "REVERSE")) t.reverse(x - 1, y - 1);
      else if(!strcmp(s, "INSERT")) t.insert(x, y);
      else if(!strcmp(s, "MIN")) cout << t.qry(x - 1, y - 1) << '\n';
      else{
        cin >> z;
        if(!strcmp(s, "ADD")) t.add(x - 1, y - 1, z);
        else if(!strcmp(s, "REVOLVE")){
          t.revolve(x - 1, y - 1, z);
        }
        else return 1;
      }
    }
  }

  cout << flush;
  return 0;
}
