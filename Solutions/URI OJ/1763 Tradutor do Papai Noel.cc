#include <bits/stdc++.h>
using namespace std;

template<class key_t, class value_t>
struct SplayTree{
  struct no{
    no *p, *l, *r;
    key_t k;
    value_t v;
  };

  no* root = 0;

  void clear(no* r){  // avoid sanitizer memory leaks
    if(r){
      clear(r->l);
      clear(r->r);
      delete r;
    }
  }
  ~SplayTree(){ clear(root); }

  void rotr(no *x){
    no* y = x->p;
    no* z = y->p;
    if((y->l = x->r)) y->l->p = y;
    x->r = y;
    y->p = x;
    if((x->p = z)) y == z->l ? z->l = x : z->r = x;
  }

  void rotl(no *x){ // ctrl+c - ctrl+v :: rotr
    no* y = x->p;
    no* z = y->p;
    if((y->r = x->l)) y->r->p = y;  // diff rotr ==> change l <=> r
    x->l = y;                       // diff rotr
    y->p = x;
    if((x->p = z)) y == z->l ? z->l = x : z->r = x;
  }

  void splay(no *x){
    while(x->p){
      no* y = x->p;
      no* z = y->p;
      if(!z) x == y->l ? rotr(x) : rotl(x);
      else if(y == z->l) x == y->l ? (rotr(y), rotr(x)) : (rotl(x), rotr(x));
      else x == y->r ? (rotl(y), rotl(x)) : (rotr(x), rotl(x));
    }
    root = x;
  }

  no* find(key_t k){
    no* r = root;
    while(r && k != r->k) r = k < r->k ? r->l : r->r;
    if(r) splay(r);
    return r;
  }

  void insert(key_t k, value_t v){
    no *p = 0, **r = &root;
    while(*r){
      p = *r;
      assert(k != p->k);  // not multiset!
      r = k < p->k ? &p->l : &p->r;
    }
    *r = new no{p,0,0,k,v};
    splay(*r);
  }

  void erase(key_t k){
    no* r = find(k);  // move a chave para a raíz
    assert(r == root && r->k == k);  // must find it!
    if(!root->l) root = root->r;
    else{
      no* k = root->l;
      while(k->r) k = k->r;
      if((k->r = root->r)) k->r->p = k;
      root = root->l;
    }
    if(root) root->p = 0;
    delete r;
  }

  void print(no* r){
    if(r){
      print(r->l);
      cerr << r->k << ' ' << r->v << ", p = " << (!r->p ? r->k : r->p->k);
      if(r->l) cerr << ", l = " << r->l->k;
      if(r->r) cerr << ", r = " << r->r->k;
      cerr << '\n';
      print(r->r);
    }
  }
};

void build(){
  freopen("in","r",stdin);

  char s[100], t[100];
  while(scanf(" %s %[^\n]", s, t) == 2){
    cout << "t.insert(\"" << s << "\", \"" << t << "\");\n";
  }
}

int main(){
  // build();
  SplayTree<string,string> t;
  t.insert("brasil", "Feliz Natal!");
  t.insert("alemanha", "Frohliche Weihnachten!");
  t.insert("austria", "Frohe Weihnacht!");
  t.insert("coreia", "Chuk Sung Tan!");
  t.insert("espanha", "Feliz Navidad!");
  t.insert("grecia", "Kala Christougena!");
  t.insert("estados-unidos", "Merry Christmas!");
  t.insert("inglaterra", "Merry Christmas!");
  t.insert("australia", "Merry Christmas!");
  t.insert("portugal", "Feliz Natal!");
  t.insert("suecia", "God Jul!");
  t.insert("turquia", "Mutlu Noeller");
  t.insert("argentina", "Feliz Navidad!");
  t.insert("chile", "Feliz Navidad!");
  t.insert("mexico", "Feliz Navidad!");
  t.insert("antardida", "Merry Christmas!");
  t.insert("canada", "Merry Christmas!");
  t.insert("irlanda", "Nollaig Shona Dhuit!");
  t.insert("belgica", "Zalig Kerstfeest!");
  t.insert("italia", "Buon Natale!");
  t.insert("libia", "Buon Natale!");
  t.insert("siria", "Milad Mubarak!");
  t.insert("marrocos", "Milad Mubarak!");
  t.insert("japao", "Merii Kurisumasu!");

  char s[10000];
  while(scanf(" %[^\n]", s) == 1){
    printf("%s\n", (!t.find(s) ? "--- NOT FOUND ---" : t.root->v).data());
  }

  return 0;
}
