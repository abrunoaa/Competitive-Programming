#include <bits/stdc++.h>
using namespace std;

/************************ Key é sempre passado por cópia! ************************/
template<class Key> struct LeftistHeap {
  struct Node {
    Node *left, *right;
    Key k;
    int s;  // rank do nó
    Node() {}
    Node(Key k) : left(0), right(0), k(k), s(1) {}
  };

  static Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->k > b->k) swap(a, b);
    a->right = merge(a->right, b);
    if (!a->left) {
      a->left = a->right;
      a->right = 0;
      assert(a->s == 1);
    }
    else {
      if (a->left->s < a->right->s) swap(a->left, a->right);
      a->s = 1 + a->right->s;                               // a->right tem o menor rank
    }
    return a;
  }

  Node* root;

  LeftistHeap() : root(0) {}
  LeftistHeap(const Key* a, int n) : root(0) {  // O(n)
    queue<Node*> q;
    for (int i = 0; i < n; ++i) q.push(new Node(a[i]));
    while (q.size() > 1) {
      Node* a = q.front();
      q.pop();
      Node* b = q.front();
      q.pop();
      q.push(merge(a, b));
    }
    root = q.front();
  }
  ~LeftistHeap() { clear(); }

  inline void clear(){  // O(n)
    clear(root);
    root = 0;
  }
  static void clear(Node* r) {
    if (r) {
      clear(r->left);
      clear(r->right);
      delete r;
    }
  }

  inline bool empty() { return !root; }
  inline Key top() { return root->k; }

  // Todas operações em O(lg n)
  inline void push(Key k) { root = merge(root, new Node(k)); }
  inline void pop() {
    Node* t = root;
    root = merge(root->left, root->right);
    delete t;
  }
  inline void merge(LeftistHeap& h){
    root = merge(root, h.root);
    h.root = 0;
  }

  void print(Node* r){
    if(r){
      print(r->left);
      cerr << ' ' << r->k;
      print(r->right);
    }
  }
  void print(){ cerr << " > T ="; print(root); cerr << endl; }
};

/// TESTES
__attribute__((destructor))static void __destroy__(){ cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n"; }

template<class t> ostream& operator<<(ostream& out,const vector<t>& ds)
{ bool flag=0; out<<'['; for(auto& x : ds){ if(flag) out<<", "; else flag=1; out<<x; } return out<<']'; }

void debug(){}
template<class t,class... u> void debug(const t& x,const u& ...y){ cerr<<' '<<x,debug(y...); }
#define debug(x...) cerr<<"\x1b[91m[" #x "] =",debug(x),cerr<<"\x1b[0m\n"

void buildTest(){
  int n = rand() % 1000 + 1;
  vector<int> v(n, 0);
  for(int& x : v) x = rand();
  // debug(v);

  priority_queue<int,vector<int>,greater<int>> pq;
  for(int x : v) pq.push(x);

  LeftistHeap<int> heap(v.data(), v.size());

  while(!pq.empty()){
    // debug(heap.top(), pq.top());
    assert(pq.top() == heap.top());
    pq.pop();
    heap.pop();
  }
}

int main(){
  srand(time(0));

  int B = 1000;
  int O = 100000;

  for(int b = 1; b <= B; ++b){
    // debug(b);
    buildTest();
  }

  LeftistHeap<int> heap;
  priority_queue<int,vector<int>,greater<int>> pq;
  for(int o = 1; o <= O; ++o){
    // debug(o);
    int op = rand() % 7;
    // debug(op);
    if(op == 0){
      while(!pq.empty()) pq.pop();
      heap.clear();
    }
    else if(op <= 3 && !pq.empty()){
      pq.pop();
      heap.pop();
    }
    else{
      int x = rand();
      // debug(x);
      pq.push(x);
      heap.push(x);
    }
    if(!pq.empty()) assert(pq.top() == heap.top());
  }

  return 0;
}
