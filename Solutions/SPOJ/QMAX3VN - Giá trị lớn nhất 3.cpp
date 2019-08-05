#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define maxalloc maxn // nº máximo de nós alocados durante toda execução

struct no {
  int pri;  // prioridade
  int size; // qtde de elementos na sub-árvore
  int val;  // valor do nó
  int ans;  // soma do intervalo
  no* l, *r;

  no() {}
  no(int x) : pri(rand()), size(1), val(x), ans(x), l(0), r(0) {}

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
    t->size = 1 + size(t->l) + size(t->r);
    t->ans = t->val;
    if (t->l) { t->ans = max(t->ans, t->l->ans); }
    if (t->r) { t->ans = max(t->ans, t->r->ans); }
  }

  void split(no* t, no* &l, no* &r, int pos) { // divide t em l = [0 .. pos] e r = [pos+1 .. n-1]
    if (!t) { l = r = 0; }
    else if (size(t->l) <= pos) { split(t->r, t->r, r, pos - 1 - size(t->l)), l = t; }
    else { split(t->l, l, t->l, pos), r = t; }
    upd(t);
  }

  void merge(no* &t, no* l, no* r) { // junta l e r, armazenando em t (l < r)
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

  int qry(int i, int j) { // ans from i to j
    no* l, *tmp, *r;
    split(root, l, tmp, i - 1);
    split(tmp, root, r, j - i);
    int ans = root->ans;
    merge(tmp, l, root);
    merge(root, tmp, r);
    return ans;
  }
};

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;

  treap t;
  while (n--) {
    char op;
    int x, y;
    cin >> op >> x >> y;
    if (op == 'A') {
      t.insert(y - 1, x);
    } else {
      cout << t.qry(x - 1, y - 1) << '\n';
    }
  }

  return 0;
}
