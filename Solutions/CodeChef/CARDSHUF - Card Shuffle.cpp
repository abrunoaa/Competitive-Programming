#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define maxalloc (maxn) // nº máximo de nós alocados durante toda execução

struct no {
  int pri;  // prioridade
  int size; // qtde de elementos na sub-árvore
  int val;  // valor do nó
  bool reverse; // flag para inverter o intervalo (reverse)
  no* l, *r;

  no() {}
  no(int x) : pri(rand()), size(1), val(x), reverse(0), l(0), r(0) {}

  static no* pnew;
  static void* operator new (size_t) { return pnew++; }
};

no alloc[maxalloc];
no* no::pnew = alloc;

struct treap { // indexado em 0
  no* root = 0;

  ~treap() { clear(); }
  void clear() {
    root = 0;
    no::pnew = alloc; /// ********** ESSA LINHA "ESTRAGA" TODAS AS TREAPS!!! **********
  }

  inline int size(no* t) { return (t ? t->size : 0); }

  inline void upd(no* t) { // atualiza o intervalo
    if (!t) { return; }
    prop(t->l), prop(t->r);
    t->size = 1 + size(t->l) + size(t->r);
  }

  void prop(no* t) {
    if (!t) { return; }
    if (t->reverse) { // propaga inversão
      swap(t->l, t->r);
      if (t->l) { t->l->reverse ^= 1; }
      if (t->r) { t->r->reverse ^= 1; }
      t->reverse = 0;
    }
  }

  void split(no* t, no* &l, no* &r, int pos) { // divide t em l = [0 .. pos] e r = [pos+1 .. n-1]
    prop(t);
    if (!t) { l = r = 0; }
    else if (size(t->l) <= pos) { split(t->r, t->r, r, pos - 1 - size(t->l)), l = t; }
    else { split(t->l, l, t->l, pos), r = t; }
    upd(t);
  }

  void merge(no* &t, no* l, no* r) { // junta l e r, armazenando em t (l < r)
    prop(l), prop(r);
    if (!l) { t = r; }
    else if (!r) { t = l; }
    else if (l->pri > r->pri) { merge(l->r, l->r, r), t = l; }
    else { merge(r->l, l, r->l), t = r; }
    upd(t);
  }

  void insert(int i, int x) { // insere x entre i-1 e i
    no* l, *r, *tmp;
    split(root, l, r, i - 1);
    merge(tmp, l, new no(x));
    merge(root, tmp, r);
  }

  void print() { print(root); cout << '\n'; }
  void print(no* r) {
    if (r) {
      prop(r);
      print(r->l);
      cout << r->val << ' ';
      print(r->r);
    }
  }

  void operation(int a, int b, int c) {
    no* A, *B, *C, *tmp;
    split(root, A, tmp, a - 1);
    split(tmp, B, tmp, b - 1);
    merge(root, A, tmp);
    split(root, C, tmp, c - 1);
    B->reverse ^= 1;
    merge(root, B, tmp);
    merge(root, C, root);
  }
};

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  treap t;
  for (int i = 0; i < n; ++i) {
    t.insert(i, i + 1);
  }
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    t.operation(a, b, c);
  }
  t.print();

  return 0;
}
