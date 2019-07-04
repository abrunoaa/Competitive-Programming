#define maxa 10000010         // máximo de nós alocados entre init's

struct node{
  node* left;
  node* right;
  int size;
  int priority;
  int x;
  int sum;
  int lazy;
  bool reverse;

  // assume que os valores são iniciados após o new (ou construtor)
  static node *pnew, mem[];
  inline static void* operator new(size_t){ return pnew++; }
  inline static void operator delete(void*){}
  inline static void init(){ pnew = mem; }

  node(){}
  node(int x)
  : left(0),
    right(0),
    size(1),
    priority(rand()),
    x(x),
    sum(x),
    lazy(0),
    reverse(0)
  {}

  void prop(){
    if(lazy){
      x += lazy;
      sum += size * lazy;
      if(left) left->lazy += lazy;
      if(right) right->lazy += lazy;
      lazy = 0;
    }
    if(reverse){
      swap(left, right);
      if(left) left->reverse ^= 1;
      if(right) right->reverse ^= 1;
      reverse = 0;
    }
  }

  void update(){
    size = 1;
    sum = x;
    if(left) size += left->size, sum += left->sum;
    if(right) size += right->size, sum += right->sum;
  }
} *node::pnew, node::mem[maxa];

struct Treap{
  node* root;
  Treap() : root(0) { node::init(); }// várias treaps: por init no main

  inline void clear(){ root = 0; }
  inline int size(){ return (root ? root->size : 0); }

  // une l e r (l < r) armazenando em t
  static void merge(node*& t, node* l, node* r){
    if(l) l->prop();
    if(r) r->prop();
    if(!l) t = r;
    else if(!r) t = l;
    else if(l->priority > r->priority) merge(l->right, l->right, r), t = l;
    else merge(r->left, l, r->left), t = r;
    if(t) t->update();
  }

  // splita t com os n primeiros em l e o resto em r
  static void split(node* t, node*& l, node*& r, int n){
    if(!t){ l = r = 0; return; }
    t->prop();
    int nl = t->left ? t->left->size : 0;
    if(nl < n) split(t->right, t->right, r, n - 1 - nl), l = t;
    else split(t->left, l, t->left, n), r = t;
    t->update();
  }

// treap fica com os elementos de i a j e faz a operação
#define do(operation)\
  node *l, *r;\
  split(root, l, r, i); split(r, root, r, j - i + 1);\
  operation;\
  merge(root, l, root); merge(root, root, r);

  void push_back(int x){ merge(root, root, new node(x)); }
  void push_front(int x){ merge(root, new node(x), root); }
  void insert(int i, int x){ int j = i - 1; do(root = new node(x)); }
  void erase(int i, int j){ do(clear()); }
  void update(int i, int x){ int j = i; do(root->x = root->sum = x); }
  void add(int i, int j, int x){ do(root->lazy = x); }
  void reverse(int i, int j){ do(root->reverse = 1); }
  int sum(int i, int j){ do(int ans = root->sum); return ans; }

  void rotate(int i, int newi, int j){
    node *a, *b;
    do((split(root, a, b, newi - i),
        merge(root, b, a)));
  }

#undef do
};
