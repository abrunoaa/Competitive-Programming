#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define maxalloc (2 * maxn)

struct no {
  int pri;  // priority
  int size; // size of tree
  int val;  // value of node
  int sum, tot, maxLR, maxRL, maxV;
  no* l, *r;  // childs

  no() {}
  no(int x) : pri(rand()), size(1), val(x), sum(x), tot(x), maxLR(max(x, 0)), maxRL(max(x, 0)), l(0), r(0) {}

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
    no::pnew = alloc; /// ********** BEWARE!!! THIS LINE DESTROY ALL TREES!!! **********
  }

  inline int size(no* t) { return (t ? t->size : 0); }
  inline int sum(no* t) { return (t ? t->sum : 0); }
  inline int tot(no* t) { return (t ? t->tot : 0); }
  inline int maxLR(no* t) { return (t ? t->maxLR : 0); }
  inline int maxRL(no* t) { return (t ? t->maxRL : 0); }

  inline void upd(no* t) { // update value of range
    if (!t) { return; }
    t->size = 1 + size(t->l) + size(t->r);
    t->sum = max(maxRL(t->l) + t->val + maxLR(t->r), max(sum(t->l), sum(t->r)));
    t->maxLR = max(maxLR(t->l), tot(t->l) + t->val + maxLR(t->r));
    t->maxRL = max(maxRL(t->r), tot(t->r) + t->val + maxRL(t->l));
    t->tot = t->val + tot(t->l) + tot(t->r);
    t->maxV = t->val;
    if (t->l) { t->maxV = max(t->maxV, t->l->maxV); }
    if (t->r) { t->maxV = max(t->maxV, t->r->maxV); }
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

  void erase(int i) { // remove da posição i (move os outros para trás)
    no* l, *r, *tmp, *del;
    split(root, l, tmp, i - 1);
    split(tmp, del, r, 0);
    merge(root, l, r);
    // delete del;
  }

  void replace(int i, int x) { // replace value at i by x
    no* l, *tmp, *r;
    split(root, l, tmp, i - 1);
    split(tmp, root, r, 0);
    *root = no(x);
    merge(tmp, l, root);
    merge(root, tmp, r);
  }

  int qry(int i, int j) { // sum from i to j
    no* l, *tmp, *r;
    split(root, l, tmp, i - 1);
    split(tmp, root, r, j - i);
    int ans = root->maxV < 0 ? root->maxV : root->sum;
    merge(tmp, l, root);
    merge(root, tmp, r);
    return ans;
  }
};

int main() {
  // freopen("in","r",stdin);
  // freopen("out","w",stdout);
  srand(0);
  cin.sync_with_stdio(0), cin.tie(0);

  treap t;

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    t.insert(i, a);
  }

  int q;
  cin >> q;
  while (q--) {
    char op;
    int x, y;
    cin >> op >> x, --x;

    if (op == 'D') { t.erase(x); }
    else {
      cin >> y;
      if (op == 'I') { t.insert(x, y); }
      else if (op == 'R') { t.replace(x, y); }
      else { cout << t.qry(x, y - 1) << '\n'; }
    }
  }

  return 0;
}
