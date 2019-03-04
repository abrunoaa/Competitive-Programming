#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__(){ cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n"; }

void debug(){}
template<class t,class... u> void debug(const t& x,const u& ...y){ cerr<<' '<<x,debug(y...); }
#define debug(x...) cerr<<"\x1b[91m[" #x "] =",debug(x),cerr<<"\x1b[0m\n"
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

#define null nullptr

struct LinkCutTree{
  struct Node{
    Node *left, *right, *parent, *pathParent;
    int size, label;
    Node() : left(0), right(0), parent(0), pathParent(0) {}
    void update(){
      size = 1;
      if(left) size += left->size;
      if(right) size += right->size;
    }
  };

#define rot(L, R)                                                                          \
  Node* y = x->parent;                                                                     \
  Node* z = y->parent;                                                                     \
  if(x->L) x->L->parent = y;                                                               \
  y->R = x->L;                                                                             \
  x->L = y;                                                                                \
  y->parent = x;                                                                           \
  x->parent = z;                                                                           \
  if(z) y == z->left ? z->left = x : z->right = x;                                         \
  x->pathParent = y->pathParent;                                                           \
  y->pathParent = null;                                                                    \
  y->update();

  void rotl(Node* x){ rot(left, right); }
  void rotr(Node* x){ rot(right, left); }

#undef rot

  void splay(Node* x){
    while(x->parent){
      Node* y = x->parent;
      Node* z = y->parent;
      if(!z) x == y->left ? rotr(x) : rotl(x);
      else if(y == z->left) x == y->left ? (rotr(y), rotr(x)) : (rotl(x), rotr(x));
      else                 x == y->right ? (rotl(y), rotl(x)) : (rotr(x), rotl(x));
    }
  }

  Node* access(Node* v){
    splay(v);
    if(v->right){
      v->right->pathParent = v;
      v->right->parent = null;
      v->right = null;
      v->update();
    }
    Node* w = v;
    while(v->pathParent){
      w = v->pathParent;
      splay(w);
      if(w->right){
        w->right->pathParent = w;
        w->right->parent = null;
      }
      w->right = v;
      v->parent = w;
      v->pathParent = null;
      w->update();
      splay(v); // rotl
    }
    return w;
  }

  Node* root;
  LinkCutTree(int n){
    root = new Node[n];
    for(int i = 0; i < n; ++i){
      root[i].label = i;
      root[i].size = 1;
    }
  }
  ~LinkCutTree(){ delete[] root; }

  void link(int u, int v){    // transforma v em filho de u
    Node* x = root + u;
    Node* y = root + v;
    access(x);
    access(y);
    x->right = y;
    y->parent = x;
    x->update();
  }

  void cut(int u){            // remove a aresta entre u e u->parent
    Node* x = root + u;
    access(x);
    x->left->parent = null;
    x->left = null;
  }

  int top(int u){             // ?
    Node* x = root + u;
    access(x);
    while(x->left) x = x->left;
    splay(x);
    return x->label;
  }

  int lca(int u, int v){      // retorna o lca entre u e v
    Node* x = root + u;
    Node* y = root + v;
    access(x);
    return access(y)->label;
  }

  int depth(int u){           // retorna a profundidade de u (na sua árvore)
    Node* x = root + u;
    access(x);
    return x->size - 1;
  }
};

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  LinkCutTree lct(n);
  char op[10];
  while(m--){
    int a, b;
    cin >> op >> a, --a;
    if(op[0] == 'c'){
      lct.cut(a);
    }
    else{
      cin >> b, --b;
      if(op[1] == 'i'){
        lct.link(b, a);
      }
      else{
        cout << lct.lca(a, b) + 1 << '\n';
      }
    }
  }

  return 0;
}
