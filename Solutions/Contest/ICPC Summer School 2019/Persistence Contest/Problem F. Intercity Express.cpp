// JUDGE PROBLEM

#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor)) static void __destroy__() { cerr << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void debug() {}
template<class t, class... u> void debug(const t &x, const u &...y) { cerr << ' ' << x, debug(y...); }
#define debug(x...) cerr << "\x1b[91m[" #x "] =", debug(x), cerr << "\x1b[0m\n"
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

#define st first
#define nd second
#define maxm 100003
#define maxa 2500000
#define M ((l + r) / 2)

struct Ticket {
  int a, b, c;
  bool operator < (const Ticket &t) const {
    return a < t.a;
  }
};

struct Node {
  Node* left, *right;
  int x;

  static Node* pnew, buf[];
  static void* operator new (size_t) { return pnew++; }
  static void init() { pnew = buf; }
}* Node::pnew, Node::buf[maxa];

int n, s, m;
Node* root[maxm];
Ticket t[maxm];

void build(Node* &t, int l = 0, int r = s) {
  t = new Node();
  if (l < r) {
    build(t->left, l, M);
    build(t->right, M + 1, r);
  }
}

Node* copy(Node* t) {
  assert(t);
  Node* u = new Node();
  memcpy(u, t, sizeof(Node));
  return u;
}

int upd(int i, int x, Node* &t, int l = 0, int r = s) {
  t = copy(t);
  if (l == r) { return t->x = x; }
  if (i <= M) { return t->x = min(upd(i, x, t->left, l, M), t->right->x); }
  return t->x = min(t->left->x, upd(i, x, t->right, M + 1, r));
}

int qry(int a, Node* t, int l = 0, int r = s) {
  if (l == r) { return l; }
  if (t->left->x <= a) { return qry(a, t->left, l, M); }
  return qry(a, t->right, M + 1, r);
}

Node* updRoot(int i) {
  if (root[i]) { return root[i]; }
  return root[i] = updRoot(i - 1);
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  Node::init();

  cin >> n >> s >> m;

  map<int, int> mp;
  mp[1];
  mp[n];
  for (int i = 0; i < m; ++i) {
    auto &x = t[i];
    cin >> x.c >> x.a >> x.b;
    mp[x.a];
    mp[x.b];
  }

  int cnt = 0;
  for (auto &x : mp) {
    x.nd = cnt++;
  }
  for (auto &x : t) {
    x.a = mp[x.a];
    x.b = mp[x.b];
  }

  sort(t, t + m);

  build(root[0]);
  for (int i = 0; i < m; ++i) {
    auto &x = t[i];
    // debug(x.a, x.b, x.c);
    updRoot(x.a + 1);
    upd(x.c - 1, x.b, root[x.a + 1]);
  }
  updRoot(cnt);

  int p = 0, q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    auto it = mp.upper_bound(a + p);
    a = (--it)->nd;
    b = mp.lower_bound(b + p)->nd;
    // debug(a, b, p);
    p = qry(a, root[b]);
    // debug(p);
    p = (p == s ? 0 : p + 1);
    cout << p << '\n';
  }

  return 0;
}
