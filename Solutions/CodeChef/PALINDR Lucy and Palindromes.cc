#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define maxalloc (maxn) // máximo de nós alocados durante toda execução
#define mod 1000000007

typedef long long ll;

int fact[maxn], invf[maxn];

int mpow(int b, int e, int m){
  int x = 1;
  while(e){
    if(e % 2) x = (ll)x * b % m;
    e /= 2;
    b = (ll)b * b % m;
  }
  return x;
}

void build(){
  fact[0] = invf[0] = 1;
  for(int i = 1; i < maxn; ++i){
    fact[i] = (ll)i * fact[i - 1] % mod;
    invf[i] = mpow(fact[i], mod - 2, mod);
  }
}

struct no{
  no *l, *r;
  int pri;  // prioridade
  int size; // qtde de elementos na sub-árvore
  int val;
  int freq[10];
  int ans;
  bool reverse; // flag para inverter o intervalo (reverse)

  no() {}
  no(int x) : l(0), r(0), pri(rand()), size(1), val(x), freq{}, ans(1), reverse(0){ freq[val] = 1; }

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
    no::pnew = alloc; /********** ESSA LINHA "ESTRAGA" TODAS AS TREAPS!!! **********/
  }

  inline int size(no* t){ return (t ? t->size : 0); }

  inline void upd(no* t){ // atualiza o intervalo do nó t
    if(!t) return;
    t->size = 1 + size(t->l) + size(t->r);
    t->ans = fact[t->size / 2];
    int odd = 0;
    for(int i = 0; i < 10; ++i){
      t->freq[i] = (t->val == i) + (t->l ? t->l->freq[i] : 0) + (t->r ? t->r->freq[i] : 0);
      t->ans = (ll)t->ans * invf[t->freq[i] / 2] % mod;
      odd += t->freq[i] % 2;
    }
    if(odd > 1 || (odd == 1 && t->size % 2 == 0)){
      t->ans = 0;
    }
  }

  void prop(no* t){
    if(!t) return;
    if(t->reverse){ // propaga inversão
      swap(t->l, t->r);
      if(t->l) t->l->reverse ^= 1;
      if(t->r) t->r->reverse ^= 1;
      t->reverse = 0;
    }
  }

  void split(no* t, no*& l, no*& r, int pos){ // t -> l = [0 .. pos] e r = [pos+1 .. n-1]
    prop(t);
    if(!t) l = r = 0;
    else if(size(t->l) <= pos) split(t->r, t->r, r, pos - 1 - size(t->l)), l = t;
    else split(t->l, l, t->l, pos), r = t;
    upd(t);
  }

  void merge(no*& t, no* l, no* r){ // junta l e r, armazenando em t
    prop(l); prop(r);
    if(!l) t = r;
    else if(!r) t = l;
    else if(l->pri > r->pri) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    upd(t);
  }

  void insert(int i, int x){  // insere x entre i-1 e i
    no *l, *r;
    split(root, l, r, i - 1);
    merge(root, l, new no(x));
    merge(root, root, r);
  }

  void reverse(int i, int j){ // inverte o intervalo [i, j]
    no *l, *r;
    split(root, l, root, i - 1);
    split(root, root, r, j - i);
    root->reverse ^= 1;
    merge(root, l, root);
    merge(root, root, r);
  }

  int qry(int i, int j){  // query entre [i, j]
    no *l, *r;
    split(root, l, root, i - 1);
    split(root, root, r, j - i);
    int ans = root->ans;
    merge(root, l, root);
    merge(root, root, r);
    return ans;
  }
};

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  build();

  int n, m;
  cin >> n >> m;

  treap t;
  for(int i = 0; i < n; ++i){
    char c;
    cin >> c, c -= 'a';
    t.insert(i, c);
  }

  while(m--){
    int op, l, r;
    cin >> op >> l >> r, --l, --r;
    if(op == 1){
      t.reverse(l, r);
    }
    else{
      cout << t.qry(l, r) << '\n';
    }
  }

  return 0;
}
