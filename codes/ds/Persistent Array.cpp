#include <bits/stdc++.h>
using namespace std;

/** begin *********************************************************************/
const int maxn = 100003;
const int maxr = maxn;        // number of versions

#define T string
// template<class T>
struct PersistentArray { // perfectly balanced tree with updates only
  struct Node {
    T x;
    int i;
    Node *left, *right;
    Node(const T& val, int idx, Node* l, Node* r) : x(val), i(idx), left(l), right(r) {}
  };

  int nv;           // latest version
  Node* root[maxr]; // root of each version

  PersistentArray(const T* a, int n) : nv(0) { root[0] = build(a, 0, n - 1); }
  static Node* build(const T* a, int l, int r) {
    if (l > r) return 0;
    int m = (l + r) / 2;
    return new Node(a[l + m], l + m, build(a, l, m - 1), build(a, m + 1, r));
  }

  void upd(int v, int i, const T& x) {  // a[i] = x in version v, creating a new version
    Node* t = root[++nv] = new Node(*root[v]);
    while (i != t->i) t = copy(i < t->i ? t->left : t->right);
    t->x = x;
  }
  static inline Node* copy(Node*& t) { return t = new Node(*t); }

  const T& get(int v, int i) {
    Node* t = root[v];
    while (i != t->i) t = i < t->i ? t->left : t->right;
    return t->x;
  }
};
/** end ***********************************************************************/

int main() {
  return 0;
}
