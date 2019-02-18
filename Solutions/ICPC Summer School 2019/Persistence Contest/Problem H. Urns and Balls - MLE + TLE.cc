#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#ifdef BALLOONFIELD
__attribute__((destructor)) static void __destroy__(){ cerr << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void debug(){}
template<class t, class... u> void debug(const t& x, const u& ...y){ cerr << ' ' << x, debug(y...); }
#define debug(x...) cerr << "\x1b[91m[" #x "] =", debug(x), cerr << "\x1b[0m\n"
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define zero(x) (abs(x) < eps)
#define pi acos(-1.0l)
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define gcd __gcd
#define popcnt __builtin_popcountll
#define ctz __builtin_ctzll
#define clz __builtin_clzll
#define lg(x) (63 - clz(x))

#define y0 asdf1
#define y1 asdf2
#define yn asdf3
#define j1 asdf4
#define tm asdf5
#define lr asdf6
#define div asdf7

template<class t> using tset = tree<t,null_type,less<t>,rb_tree_tag,tree_order_statistics_node_update>;
template<class t,class u> using tmap = tree<t,u,less<t>,rb_tree_tag,tree_order_statistics_node_update>;
template<class t,class u = greater<t>> using pqueue = priority_queue<t,vector<t>,u>;

template<class t1, class t2> ostream& operator << (ostream& out, const pair<t1,t2>& x){ return out << '(' << x.st << ", " << x.nd << ')'; }

#define PRINT_DS bool flag = 0; out << '['; for(auto& x : ds){ if(flag) out << ", "; else flag = 1; out << x; } return out << ']'
template<class t> ostream& operator << (ostream& out, const vector<t>& ds){ PRINT_DS; }
template<class t> ostream& operator << (ostream& out, const set<t>& ds){ PRINT_DS; }
template<class t> ostream& operator << (ostream& out, const tset<t>& ds){ PRINT_DS; }
template<class t1, class t2> ostream& operator << (ostream& out, const map<t1,t2>& ds){ PRINT_DS; }
template<class t1, class t2> ostream& operator << (ostream& out, const tmap<t1,t2>& ds){ PRINT_DS; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double lf;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define eps 1e-9
#define mod 1000000007
#define maxm 50003

struct Node{
  shared_ptr<Node> left, right;
  int size;
  int x;

  Node(){}
  Node(int x, int n) : left(0), right(0), size(n), x(x) {}

  void update(){
    size = 1;
    if(left) size += left->size;
    if(right) size += right->size;
  }
};

typedef shared_ptr<Node> PNode;

struct Treap{
  PNode root;
  Treap(int n) : root(0){ create(root, n); }

  void create(PNode& r, int n, int s = 0){
    if(!n) return;
    int k = (n + 1) / 2;
    r = PNode(new Node(s + k, n));
    create(r->left, k - 1, s);
    create(r->right, n - k, s + k);
  }

  static PNode copy(PNode t){
    if(!t) return 0;
    PNode u(new Node());
    u->left = t->left;
    u->right = t->right;
    u->size = t->size;
    u->x = t->x;
    return u;
  }

  static void merge(PNode& t, PNode l, PNode r){
    if(!l) t = copy(r);
    else if(!r) t = copy(l);
    else if(l->size > r->size) t = copy(l), merge(t->right, t->right, r);
    else t = copy(r), merge(t->left, l, t->left);
    if(t) t->update();
  }

  static void split(PNode t, PNode& l, PNode& r, int n){
    if(!t){ l = r = 0; return; }
    int nl = t->left ? t->left->size : 0;
    // debug(t->x, n, nl);
    if(nl < n){
      l = copy(t);
      split(l->right, l->right, r, n - 1 - nl);
      l->update();
    }
    else{
      r = copy(t);
      split(r->left, l, r->left, n);
      r->update();
    }
  }

  void lift(int from, int to, int cnt){
    --from;
    --to;

    // bool flag;
    // debug(from, to, cnt);

    // encontra o intervalo da resposta
    PNode result, trash;
    split(root, trash, result, to);
    // flag = 0; cout << " -> "; print(result, flag); cout << '\n';
    split(result, result, trash, cnt);
    // flag = 0; cout << " -> "; print(result, flag); cout << '\n';

    // intervalo para inserir
    PNode a, b;
    split(root, a, b, from);
    // flag = 0; cout << " -> "; print(a, flag); cout << '\n';
    // flag = 0; cout << " -> "; print(b, flag); cout << '\n';
    split(b, trash, b, cnt);
    // flag = 0; cout << " -> "; print(b, flag); cout << '\n';

    // insere
    merge(root, a, result);
    merge(root, root, b);
  }

  void print(PNode r, bool& flag){
    if(r){
      print(r->left, flag);
      if(flag) cout << ' ';
      else flag = 1;
      cout << r->x;
      print(r->right, flag);
    }
  }

  void print(){
    bool flag = 0;
    print(root, flag);
    cout << '\n';
  }
};

int cnt[maxm], from[maxm], to[maxm];

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  // n = 1e5;
  // m = 5e4;
  Treap t(n);
  for(int i = 0; i < m; ++i){
    cin >> cnt[i] >> from[i] >> to[i];
    // cnt[i] = rand() % (n - 1) + 1;
    // from[i] = rand() % (n - cnt[i]) + 1;
    // to[i] = rand() % (n - cnt[i]) + 1;
  }
  for(int i = m - 1; i >= 0; --i){
    // t.print();
    t.lift(from[i], to[i], cnt[i]);
  }
  t.print();

  return 0;
}
