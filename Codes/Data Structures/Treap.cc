#include <bits/stdc++.h>
using namespace std;

#define maxa 10000000 // máximo de nós alocados entre init's

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





/// testes
void test(int N){
  Treap t;
  vector<int> v;

  for(int i = 0; i < 100; ++i){
    int x = (rand() % 100 + 1) * (rand() % 2 ? 1 : -1);
    if(rand() % 2){
      v.push_back(x);
      t.push_back(x);
    }
    else{
      v.insert(v.begin(), x);
      t.push_front(x);
    }
  }

  for(int n = 0; n < N; ++n){
    int op = v.empty() ? 1 : rand() % 8;
    // cout << "op = " << op << endl;
    if(op == 1){
      int i = rand() % (v.size() + 1);
      int x = (rand() % 100 + 1) * (rand() % 2 ? 1 : -1);
      v.insert(v.begin() + i, x);
      t.insert(i, x);
    }
    else if(op == 2){
      int i = rand() % v.size();
      int j = rand() % v.size();
      if(i > j) swap(i, j);
      v.erase(v.begin() + i, v.begin() + j + 1);
      t.erase(i, j);
    }
    else if(op == 0 || op == 3 || op == 4){
      int i = rand() % v.size();
      int j = rand() % v.size();
      if(i > j) swap(i, j);
      int x = (rand() % 100 + 1) * (rand() % 2 ? 1 : -1);
      for(int k = i; k <= j; ++k) v[k] += x;
      t.add(i, j, x);
    }
    else if(op == 5){
      int i = rand() % v.size();
      int j = rand() % v.size();
      if(i > j) swap(i, j);
      reverse(v.begin() + i, v.begin() + j + 1);
      t.reverse(i, j);
    }
    else if(op == 6){
      int i = rand() % v.size();
      int j = rand() % v.size();
      if(i > j) swap(i, j);
      int k = i + rand() % (j - i + 1);
      rotate(v.begin() + i, v.begin() + k, v.begin() + j + 1);
      t.rotate(i, k, j);
    }
    else if(op == 7){
      int i = rand() % v.size();
      int x = (rand() % 100 + 1) * (rand() % 2 ? 1 : -1);
      v[i] = x;
      t.update(i, x);
    }
    else assert(0);

    // cout << " >> v = "; for(int x : v) cout << x << ' '; cout << '\n';
    // cout << " >> t = "; for(int i = 0; i < t.size(); ++i) cout << t.sum(i,i) << ' '; cout << '\n';
    assert(v.size() == t.size());
    for(int i = 0; i < v.size(); ++i)
      for(int j = i, sum = 0; j < v.size(); ++j){
        sum += v[j];
        assert(sum == t.sum(i, j));
      }
  }
}

int main(){
  srand(0);
  int T = 100;
  for(int t = 1; t <= T; ++t){
    cout << "teste " << t << '\n';
    test(1000);
  }
  cout << "ok!\n";
  return 0;
}
