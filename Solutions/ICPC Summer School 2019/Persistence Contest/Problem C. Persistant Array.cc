#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
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
#define maxn 100003

struct Node{
  int i, x;
  Node* left;
  Node* right;
  Node(){}
  Node(int i, int x, Node* l, Node* r) : i(i), x(x), left(l), right(r) {}
};

Node* copy(Node*& t){
  Node* u = new Node();
  memcpy(u, t, sizeof(Node));
  return t = u;
}

void insert(Node*& t, int i, int x){
  if(!t) t = new Node(i, x, 0, 0);
  else if(i < t->i) insert(t->left, i, x);
  else insert(t->right, i, x);
}

void upd(Node* t, int i, int x){
  while(i != t->i) t = i < t->i ? copy(t->left) : copy(t->right);
  t->x = x;
}

int get(Node* t, int i){
  while(i != t->i) t = i < t->i ? t->left : t->right;
  return t->x;
}

int n, v[maxn], r[maxn];
Node* root[maxn];

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> v[i];
    r[i] = i;
  }
  srand(time(0));
  random_shuffle(r, r + n);
  for(int i = 0; i < n; ++i){
    insert(root[1], r[i] + 1, v[r[i]]);
  }

  int m;
  cin >> m;
  for(int i = 0, k = 1; i < m; ++i){
    int a, b, c;
    string s;
    cin >> s >> a >> b;
    if(s[0] == 'c'){
      cin >> c;
      upd(copy(root[++k] = root[a]), b, c);
    }
    else{
      cout << get(root[a], b) << endl;
    }
  }

  return 0;
}
