#include <bits/stdc++.h>
using namespace std;

#define lg(x) (63 - __builtin_clzll(x))
#define maxn 100003
#define maxr maxn // nº de revisões

template<class T> struct Stack{
  struct Node{
    T x;
    Node* next;
    Node(){}
    Node(const T& x, Node* next) : x(x), next(next) {}
  };

  int nv;
  Node* root[maxr];

  Stack() : nv(0) { root[0] = 0; }

  void push(int v, const T& x){ root[++nv] = new Node(x, root[v]); }
  void pop(int v){ root[++nv] = root[v]->next; }
  const T& top(int v) const { return root[v]->x; }
};

template<class T> struct Queue{
  struct Node{
    T x;
    int n;
    Node* p[lg(maxn)];
    Node(){}
    Node(const T& x, Node* p0) : x(x){
      p[0] = p0;
      for(int i = 1; i < lg(maxn); ++i) p[i] = !p[i - 1] ? 0 : p[i - 1]->p[i - 1];
    }
  };

  int nv;
  Node* back[maxr];

  void push(int v, const T& x){ back[++nv] = new Node(x, back[v]); }
  void pop(int v){
    memcpy(back[++nv], back[v], sizeof(Node));
    --back[nv]->n;
  }
  const T& front(int v){
    Node* r = back[v];
    for(int i = lg(maxn) - 1, up = r->n - 1; i >= 0; --i)
      if(up >= (1 << i)){
        up -= (1 << i);
        r = r->p[i];
      }
    return r->x;
  }
};

template<class T> struct Array{
  struct Node{
    T x;
    int idx;
    Node* left;
    Node* right;
    Node(){}
    Node(const T& x, int i, Node* l, Node* r) : x(x), idx(i), left(l), right(r) {}
  };

  int nv;
  Node* root[maxr];

  Array(const T* a, int n) : nv(0){
    vector<int> v(n, 0);
    iota(v.begin(), v.end(), 0);
    random_shuffle(v.begin(), v.end());
    for(int i : v) insert(root[0], i, a[i]);
  }

  void insert(Node*& t, int i, const T& x){
    if(!t) t = new Node(i, x, 0, 0);
    else if(i < t->i) insert(t->left, i, x);
    else insert(t->right, i, x);
  }

  Node* copy(Node*& t){
    Node* u = new Node();
    memcpy(u, t, sizeof(Node));
    return t = u;
  }

  void upd(int v, int i, const T& x){
    Node*& t = root[++nv] = root[v];
    copy(t);
    while(i != t->i) t = i < t->i ? copy(t->left) : copy(t->right);
    t->x = x;
  }

  const T& get(Node* t, int i){
    while(i != t->i) t = i < t->i ? t->left : t->right;
    return t->x;
  }
};

int main(){
  return 0;
}
