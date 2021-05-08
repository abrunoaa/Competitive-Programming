#include <bits/stdc++.h>
using namespace std;

/** begin *********************************************************************/
template<class Key> struct PersistentLeftistHeap {
  struct Node {
    Node *left, *right;
    Key k;
    int s;  // node's rank
    Node() {}
    Node(Key key) : left(0), right(0), k(key), s(1) {}
  };

  static Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->k > b->k) swap(a, b);
    a = new Node(*a);
    a->right = merge(a->right, b);
    if (!a->left) {
      a->left = a->right;
      a->right = 0;
      assert(a->s == 1);
    } else {
      if (a->left->s < a->right->s) swap(a->left, a->right);
      a->s = 1 + a->right->s;
    }
    return a;
  }

  vector<Node*> root;

  PersistentLeftistHeap() : root(1, 0) {} // version 0 is empty
  inline bool empty(int v) { return !root[v]; }
  inline Key top(int v) { return root[v]->k; }
  inline void push(const Key& k, int v) { root.push_back(merge(root[v], new Node(k))); }
  inline void pop(int v) { root.push_back(!root[v] ? 0 : merge(root[v]->left, root[v]->right)); }
  inline void merge(int u, int v) { root.push_back(merge(root[u], root[v])); }
};
/** end ***********************************************************************/

typedef PersistentLeftistHeap<int> PHeap;

void print(const PHeap::Node* r) {
  if (r) {
    print(r->left);
    cerr << ' ' << r->k;
    print(r->right);
  }
}
void print(const PHeap& h, int v) { cerr << " > T ="; print(h.root[v]); cerr << endl; }

int main() {
  return 0;
}
