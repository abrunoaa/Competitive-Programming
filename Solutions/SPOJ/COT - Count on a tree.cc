#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__(){cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}

void debug(){}
template<class t,class... u> void debug(const t&x,const u&...y){cerr<<' '<<x,debug(y...);}
# define debug(x...) cerr<<"\x1b[91m"<<__LINE__<<" ["#x"] =",debug(x),cerr<<"\x1b[0m\n"
# define sleep(x) this_thread::sleep_for(chrono::milliseconds(x))
#else
# define assert(x) void(0)
# define debug(...) void(0)
# define freopen(...) void(0)
# define sleep(x) void(0)
#endif

template<class A,class B>ostream&operator<<(ostream&f,const pair<A,B>&x){return f<<'('<<x.first<<", "<<x.second<<')';}

#define DEF1(_class...) ostream&operator<<(ostream&f,const _class&x){int b=0;f<<'[';for(auto&y:x){if(b++)f<<", ";f<<y;}return f<<']';}
#define DEF2(get,pop,_class...) ostream&operator<<(ostream&f,_class x){int b=0;f<<'[';while(x.size()){if(b++)f<<", ";f<<x.get();x.pop();}return f<<']';}
template<class T> DEF1(vector<T>) template<class T,class C> DEF1(set<T,C>) template<class T,class C> DEF1(multiset<T,C>) template<class K,class T,class C> DEF1(map<K,T,C>) template<class K,class T,class C> DEF1(multimap<K,T,C>)
template<class T> DEF2(front,pop,queue<T>) template<class T> DEF2(top,pop,stack<T>) template<class T,class V,class C> DEF2(top,pop,priority_queue<T,V,C>)

#define null nullptr
#define st first
#define nd second
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 100003
#define maxl 17

#define rand() uid(rng)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); // ll = mt19937_64
uniform_int_distribution<int> uid(0, numeric_limits<int>::max());             // range for random

typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;

#define M ((l + r) / 2)

struct Node{
  Node *left, *right;
  int sum;
  Node() : left(0), right(0), sum(0) {}
  Node(Node *l, Node* r, int s) : left(l), right(r), sum(s) {}
};

int n, m, w[maxn], value[maxn], arseq[maxn];
int depth[maxn], p[maxl][maxn];
vector<int> g[maxn];
Node *root[maxn];

void buildSt(Node* &t = root[0], int l = 1, int r = n){
  t = new Node();
  if(l != r){
    buildSt(t->left, l, M);
    buildSt(t->right, M+1, r);
  }
}

inline Node* copy(Node* &t){
  return t = new Node(t->left, t->right, t->sum);
}

int upd(int i, Node* &t, int l = 1, int r = n){
  t = copy(t);
  if(l == r) return ++t->sum;
  if(i <= M) return t->sum = upd(i, t->left, l, M) + t->right->sum;
  return t->sum = t->left->sum + upd(i, t->right, M+1, r);
}

int qry(int i, Node* t, int l = 1, int r = n){
  if(i < l) return 0;
  if(r <= i) return t->sum;
  return qry(i, t->left, l, M) + qry(i, t->right, M+1, r);
}

int qry(int k, Node *u, Node *v, Node *w, Node *p, int l = 1, int r = n){
  if(l == r) return l;
  int x = u->left->sum + v->left->sum - w->left->sum - p->left->sum;
  if(k <= x) return qry(k, u->left, v->left, w->left, p->left, l, M);
  return qry(k - x, u->right, v->right, w->right, p->right, M+1, r);
}

void dfs(int u = 1, int par = 0){
  p[0][u] = par;
  root[u] = root[par];
  upd(w[u], root[u]);
  for(int v : g[u]) if(v != par){
    depth[v] = depth[u] + 1;
    dfs(v, u);
  }
}

void buildLca(){
  for(int i = 1; i < maxl; ++i){
    for(int u = 1; u <= n; ++u){
      int v = p[i - 1][u];
      p[i][u] = p[i - 1][v];
    }
  }
}

int lca(int u, int v){
  if(depth[u] < depth[v]) swap(u, v);
  int dif = depth[u] - depth[v];
  for(int i = maxl - 1; i >= 0; --i)
    if(1 & (dif >> i))
      u = p[i][u];
  if(u == v) return u;
  for(int i = maxl - 1; i >= 0; --i) if(p[i][u] != p[i][v]){
    u = p[i][u];
    v = p[i][v];
  }
  return p[0][u];
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;

  map<int,int> mp;
  for(int i = 1; i <= n; ++i){
    cin >> w[i];
    mp[w[i]];
  }
  int cnt = 0;
  for(auto &p : mp){
    p.nd = ++cnt;
    value[cnt] = p.st;
  }
  for(int i = 1; i <= n; ++i){
    w[i] = mp[w[i]];
  }

  for(int i = 1; i < n; ++i){
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  buildSt();
  dfs();
  buildLca();
  while(m--){
    int u, v, k;
    cin >> u >> v >> k;
    int w = lca(u, v);
    int pw = p[0][w];
    int x = qry(k, root[u], root[v], root[w], root[pw]);
    cout << value[x] << '\n';
  }

  return 0;
}
