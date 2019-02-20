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

#define maxn 100003
#define maxa 4000000
#define M ((l + r) / 2)

struct Node{
  Node *left, *right;
  int val;
  Node(){}
  Node(int x) : left(0), right(0), val(x) {}

  static Node *pnew, buf[];
  static void* operator new(size_t){ return pnew++; }
  static void operator delete(void*){}
  static void init(){ pnew = buf; }
} *Node::pnew, Node::buf[maxa];

Node* copy(Node* t){
  Node* u = new Node();
  memcpy(u, t, sizeof(Node));
  return u;
}

int n, m, p[maxn];
Node* root[maxn];

void build(Node*& t, int l = 1, int r = n){
  t = new Node(0);
  if(l < r){
    build(t->left, l, M);
    build(t->right, M+1, r);
  }
}

int upd(int i, int x, Node*& t, int l = 1, int r = n){
  if(r < i || i < l) return t->val;
  t = copy(t);
  if(l == r) return t->val += x;
  if(i <= M) return t->val = upd(i, x, t->left, l, M) + t->right->val;
  return t->val = t->left->val + upd(i, x, t->right, M+1, r);
}

int qry(int i, int j, Node* t, int l = 1, int r = n){
  if(r < i || j < l) return 0;
  if(i <= l && r <= j) return t->val;
  return qry(i, j, t->left, l, M) + qry(i, j, t->right, M+1, r);
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  Node::init();

  cin >> n >> m;
  build(root[0]);
  for(int i = 1; i <= n; ++i){
    int a;
    cin >> a;
    root[i] = root[i - 1];
    if(p[a]) upd(p[a], -1, root[i]);
    p[a] = i;
    upd(i, +1, root[i]);
  }
  upd(n + 1, n + m, root[n + 1] = root[n]);

  int p = 0, q;
  cin >> q;
  while(q--){
    int l, k;
    cin >> l >> k;
    l = (l + p) % n + 1;
    k = (k + p) % m + 1;
    int i = l, j = n + 1;
    while(i < j){
      int m = (i + j) / 2;
      if(qry(l, m, root[m]) >= k){
        j = m;
      }
      else{
        i = m + 1;
      }
    }
    // debug(l, k, i);
    p = (i <= n ? i : 0);
    cout << p << '\n';
  }

  return 0;
}
