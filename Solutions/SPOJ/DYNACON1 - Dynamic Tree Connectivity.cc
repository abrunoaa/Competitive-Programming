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
    bool flip;  // por algum motivo fica mais rápido
    Node() : left(0), right(0), parent(0), pathParent(0), size(0), label(-1), flip(0) {}

    void update(){
      size = 1;
      if(left) size += left->size;
      if(right) size += right->size;
    }

    void prop(){
      if(flip){
        flip = 0;
        swap(left, right);
        if(left) left->flip ^= 1;
        if(right) right->flip ^= 1;
      }
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
  y->update();                                                                             \
  x->update();

  void rotl(Node* x){ rot(left, right); }
  void rotr(Node* x){ rot(right, left); }

#undef rot

  void splay(Node* x){
    x->prop();
    while(x->parent){
      Node* y = x->parent;
      Node* z = y->parent;
      if(z) z->prop();
      y->prop();
      x->prop();
      if(!z) x == y->left ? rotr(x) : rotl(x);
      else if(y == z->left) x == y->left ? (rotr(y), rotr(x)) : (rotl(x), rotr(x));
      else                 x == y->right ? (rotl(y), rotl(x)) : (rotr(x), rotl(x));
    }
  }

  Node* access(Node* x){
    splay(x);
    if(x->right){
      x->right->pathParent = x;
      x->right->parent = null;
      x->right = null;
      x->update();
    }
    Node* y = x;
    while(x->pathParent){
      y = x->pathParent;
      splay(y);
      if(y->right){
        y->right->pathParent = y;
        y->right->parent = null;
      }
      y->right = x;
      x->parent = y;
      x->pathParent = null;
      y->update();
      rotl(x);
    }
    return y;
  }

  void makeRoot(Node* x){
    access(x);
    splay(x);
    if(x->left){
      x->left->flip ^= 1;
      x->left->parent = null;
      x->left->pathParent = x;
      x->left = null;
      x->size = 1;
    }
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

  inline void link(int u, int v){
    Node* x = root + u; // root + u == &root[u]
    Node* y = root + v;
    makeRoot(y);
    y->pathParent = x;
  }

  inline void cut(int u){
    Node* x = root + u;
    access(x);
    x->left->parent = null;
    x->left = null;
    x->size = 1;
  }

  inline void cut(int u, int v){
    Node* x = root + u;
    Node* y = root + v;
    makeRoot(x);
    splay(y);
    if(y->pathParent){
      y->pathParent = null;
    }
    else{
      y->left->parent = null;
      y->left = null;
      y->update();
    }
  }

  inline int findRoot(int u){
    Node* x = root + u;
    access(x);
    while(x->left) x = x->left;
    splay(x);
    return x->label;
  }

  inline int lca(int u, int v){
    Node* x = root + u;
    Node* y = root + v;
    access(x);
    return access(y)->label;
  }

  inline int depth(int u){
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
    cin >> op >> a >> b, --a, --b;
    if(op[0] == 'a'){
      lct.link(a, b);
    }
    else if(op[0] == 'r'){
      lct.cut(a, b);
    }
    else{
      cout << (lct.findRoot(a) == lct.findRoot(b) ? "YES" : "NO") << '\n';
    }
  }

  return 0;
}
