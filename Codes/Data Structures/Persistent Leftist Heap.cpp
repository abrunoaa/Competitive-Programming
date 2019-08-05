/************************ Key é sempre passado por cópia! ************************/
template<class Key> struct PersistentLeftistHeap {
  struct Node {
    Node* left, *right;
    Key k;
    int s;  // rank do nó
    Node() {}
    Node(Key k) : left(0), right(0), k(k), s(1) {}
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

  void print(Node* r) {
    if (r) {
      print(r->left);
      cerr << ' ' << r->k;
      print(r->right);
    }
  }
  void print(int v) { cerr << " > T ="; print(root[v]); cerr << endl; }
};
