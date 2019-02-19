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

#define maxn 300003 // wrong max value

struct PersistentTreap{
  struct Node{
    Node *left, *right;
    int key, qtd, unique;
    int size, priority, version;

    Node(){}
    Node(int k, int v)
    : left(0), right(0), key(k), qtd(1), unique(1), size(1), priority(rand()), version(v) {}

    void update(){
      size = 1;
      unique = qtd == 1;
      if(left) size += left->size, unique += left->unique;
      if(right) size += right->size, unique += right->unique;
    }
  };

  int nv;
  Node* root[maxn];

  PersistentTreap() : nv(0){
    srand(time(0));
    root[0] = 0;
  }

  Node* copy(Node* t, int v){
    if(!t || t->version == v) return t;
    Node* u = new Node();
    memcpy(u, t, sizeof(Node));
    u->version = v;
    return u;
  }

  void merge(Node*& t, Node* l, Node* r, int v){
    if(!l) t = r;
    else if(!r) t = l;
    else if(l->priority > r->priority) t = copy(l, v), merge(t->right, t->right, r, v);
    else t = copy(r, v), merge(t->left, l, t->left, v);
    if(t) t->update();
  }

  void split(Node* t, Node*& l, Node*& r, int k, int v){
    if(!t){
      l = r = 0;
      return;
    }
    if(t->key <= k){
      l = copy(t, v);
      split(l->right, l->right, r, k, v);
      l->update();
    }
    else{
      r = copy(t, v);
      split(r->left, l, r->left, k, v);
      r->update();
    }
  }

  void insert(int k){
    ++nv;
    Node *l, *r, *&t = root[nv];
    t = root[nv - 1];
    split(t, l, r, k - 1, nv);
    split(r, t, r, k, nv);
    if(!t) t = new Node(k, nv);
    else{
      ++t->qtd;
      t->update();
    }
    merge(t, l, t, nv);
    merge(t, t, r, nv);
  }

  void remove(int k){
    ++nv;
    Node *l, *r, *&t = root[nv];
    t = root[nv - 1];
    split(t, l, r, k - 1, nv);
    split(r, t, r, k, nv);
    if(t && t->qtd > 0){
      if(!--t->qtd){
        t = 0;
      }
      else{
        t->update();
      }
    }
    merge(t, l, t, nv);
    merge(t, t, r, nv);
  }

  int count(int k, int v){
    ++nv;
    root[nv] = root[nv - 1];
    Node* r = root[v];
    while(r && r->key != k) r = (k < r->key ? r->left : r->right);
    return (!r ? 0 : r->qtd);
  }

  int diff(int v){
    ++nv;
    root[nv] = root[nv - 1];
    return (!root[v] ? 0 : root[v]->size);
  }

  int unique(int v){
    ++nv;
    root[nv] = root[nv - 1];
    return (!root[v] ? 0 : root[v]->unique);
  }
};

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, m;
  long long s = 0;
  char op[20];
  PersistentTreap t;
  cin >> n >> m;
  for(int i = 1; i <= n; ++i){
    int y;
    cin >> op >> y;
    char c = op[0];
    int ans = 0;
    if(c == 'c'){
      int v;
      cin >> v;
      ans = t.count(y, (v + s) % i);
      cout << ans << '\n';
    }
    else if(c == 'd'){
      ans = t.diff((y + s) % i);
      cout << ans << '\n';
    }
    else if(c == 'u'){
      ans = t.unique((y + s) % i);
      cout << ans << '\n';
    }
    else if(c == 'a'){
      t.insert(y);
    }
    else{
      t.remove(y);
    }
    s += ans;
  }

  return 0;
}
