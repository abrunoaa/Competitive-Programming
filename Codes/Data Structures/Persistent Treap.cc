/// ****************************** SEM TESTE!!! ****************************************

#include <bits/stdc++.h>
using namespace std;

#define maxn 100003
#define maxa maxn // máximo de nós alocados entre init's

struct Node{
  Node* left;
  Node* right;
  int size;
  int priority;
  int key;

  Node(){}
  Node(int k) :
    left(0),
    right(0),
    size(1),
    priority(rand()),
    key(k)
  {}

  void update(){
    size = 1;
    if(left) size += left->size;
    if(right) size += right->size;
  }

  // assume que os valores são iniciados após o new (ou construtor)
  static Node *pnew, mem[];
  inline static void* operator new(size_t){ return pnew++; }
  inline static void operator delete(void*){}
  inline static void init(){ pnew = mem; }
} *Node::pnew, Node::mem[maxa];

struct Treap{
  int nv;           // nº de versões
  Node* root[maxn]; // raízes

  Treap(){
    root[0] = 0;    // versão 0 é a inicial
    Node::init();   // várias treaps: por init no main
  }

  inline int size(int v){ return (root[v] ? root[v]->size : 0); }

  static Node* copy(Node* t){
    if(!t) return 0;
    Node* u = new Node();
    memcpy(u, t, sizeof(Node));
    return u;
  }

  static void merge(Node*& t, Node* l, Node* r){
    if(!l) t = copy(r);
    else if(!r) t = copy(l);
    else if(l->priority > r->priority) t = copy(l), merge(t->right, t->right, r);
    else t = copy(r), merge(r->left, l, r->left);
    if(t) t->update();
  }

  static void split(Node* t, Node*& l, Node*& r, int n){
    if(!t){ l = r = 0; return; }
    int nl = t->left ? t->left->size : 0;
    if(nl < n) l = copy(t), split(l->right, l->right, r, n - 1 - nl);
    else r = copy(t), split(r->left, l, r->left, n);
    t->update();
  }

  // fazer as operações como uma treap normal, sem esquecer de incrementar nv
};

int main(){
  return 0;
}
