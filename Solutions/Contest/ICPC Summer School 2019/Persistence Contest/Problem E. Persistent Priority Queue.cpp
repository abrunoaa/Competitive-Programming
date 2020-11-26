#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__() { cerr << "\nElapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void debug() {}
template<class t, class... u> void debug(const t &x, const u &...y) { cerr << ' ' << x, debug(y...); }
#define debug(x...) cerr<<"\x1b[91m[" #x "] =",debug(x),cerr<<"\x1b[0m\n"
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

/************************ Key é sempre passado por cópia! ************************/
template<class Key> struct PersistentLeftistHeap {
  struct Node {
    Node* left, *right;
    Key k;
    int s;  // rank do nó

    Node() {}
    Node(Key k)
      : left(0),
        right(0),
        k(k),
        s(1)
    {}
  };

  static Node* copy(Node* a) {
    if (!a) { return 0; }
    Node* b = new Node();
    memcpy(b, a, sizeof(Node));
    return b;
  }

  static Node* merge(Node* a, Node* b) {
    if (!a) { return b; }
    if (!b) { return a; }
    if (a->k > b->k) { swap(a, b); }
    a = copy(a);
    a->right = merge(a->right, b);
    if (!a->left) {
      a->left = a->right;
      a->right = 0;
      assert(a->s == 1);
    } else {
      if (a->left->s < a->right->s) { swap(a->left, a->right); }
      a->s = 1 + a->right->s;                               // a->right tem o menor rank
    }
    return a;
  }

  vector<Node*> root;

  PersistentLeftistHeap() : root(1, 0) {}
  inline bool empty(int v) { return !root[v]; }
  inline Key top(int v) { return root[v]->k; }
  inline void push(Key k, int v) { root.push_back(merge(root[v], new Node(k))); }
  inline void pop(int v) { root.push_back(!root[v] ? 0 : merge(root[v]->left, root[v]->right)); }
  inline void unite(int u, int v) { root.push_back(merge(root[u], root[v])); }
};

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, s = 0;
  PersistentLeftistHeap<int> h;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int t, a, b;
    cin >> t >> a;
    int v = (a + s) % i;
    int ans;
    if (t == 3) {
      ans = (h.empty(v) ? -1 : h.top(v));
      h.pop(v);
    } else {
      cin >> b;
      if (t == 1) {
        int x = (b + 17ll * s) % ((int)1e9 + 1);
        h.push(x, v);
        ans = h.empty(i) ? -1 : h.top(i);
      } else {
        int u = (b + 13 * s) % i;
        h.unite(u, v);
        ans = h.empty(i) ? -1 : h.top(i);
      }
    }

    if (ans == -1) {
      cout << "empty\n";
    } else {
      cout << ans << '\n';
      s = (s + ans) % 239017;
    }
  }

  return 0;
}
