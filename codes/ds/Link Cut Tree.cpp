struct LinkCutTree {
  struct Node {
    Node* left, *right, *parent, *pathParent;
    int size, label;
    bool flip;        // por algum motivo fica mais rápido
    Node() : left(0), right(0), parent(0), pathParent(0), size(0), label(-1), flip(0) {}

    void update() {
      size = 1;
      if (left) size += left->size;
      if (right) size += right->size;
    }

    void prop() {
      if (flip) {
        flip = 0;
        swap(left, right);
        if (left) left->flip ^= 1;
        if (right) right->flip ^= 1;
      }
    }
  };

#define rot(L, R)                                                                   \
  Node* y = x->parent;                                                              \
  Node* z = y->parent;                                                              \
  if(x->L) x->L->parent = y;                                                        \
  y->R = x->L;                                                                      \
  x->L = y;                                                                         \
  y->parent = x;                                                                    \
  x->parent = z;                                                                    \
  if(z) y == z->left ? z->left = x : z->right = x;                                  \
  x->pathParent = y->pathParent;                                                    \
  y->pathParent = nullptr;                                                          \
  y->update();                                                                      \
  x->update();

  void rotl(Node* x) { rot(left, right); }
  void rotr(Node* x) { rot(right, left); }

#undef rot

  void splay(Node* x) {
    x->prop();
    while (x->parent) {
      Node* y = x->parent;
      Node* z = y->parent;
      if (z) z->prop();
      y->prop();
      x->prop();
      if (!z)                 x == y->left ? rotr(x)            : rotl(x);
      else if (y == z->left)  x == y->left ? (rotr(y), rotr(x)) : (rotl(x), rotr(x));
      else                   x == y->right ? (rotl(y), rotl(x)) : (rotr(x), rotl(x));
    }
  }

  Node* access(Node* x) {
    splay(x);
    if (x->right) {
      x->right->pathParent = x;
      x->right->parent = nullptr;
      x->right = nullptr;
      x->update();
    }
    Node* y = x;
    while (x->pathParent) {
      y = x->pathParent;
      splay(y);
      if (y->right) {
        y->right->pathParent = y;
        y->right->parent = nullptr;
      }
      y->right = x;
      x->parent = y;
      x->pathParent = nullptr;
      y->update();
      rotl(x);
    }
    return y;
  }

  void makeRoot(Node* x) {
    access(x);
    splay(x);
    if (x->left) {
      x->left->flip ^= 1;
      x->left->parent = nullptr;
      x->left->pathParent = x;
      x->left = nullptr;
      x->size = 1;
    }
  }

  Node* root;
  LinkCutTree(int n) {
    root = new Node[n];
    for (int i = 0; i < n; ++i) {
      root[i].label = i;
      root[i].size = 1;
    }
  }
  ~LinkCutTree() { delete[] root; }

  inline void link(int u, int v) {
    Node* x = root + u;                 // root + u == &root[u]
    Node* y = root + v;
    makeRoot(y);
    y->pathParent = x;
  }

  inline void cut(int u) {
    Node* x = root + u;
    access(x);
    x->left->parent = nullptr;
    x->left = nullptr;
    x->size = 1;
  }

  inline void cut(int u, int v) {
    Node* x = root + u;
    Node* y = root + v;
    makeRoot(x);
    splay(y);
    if (y->pathParent) {
      y->pathParent = nullptr;
    } else {
      y->left->parent = nullptr;
      y->left = nullptr;
      y->update();
    }
  }

  inline int findRoot(int u) {
    Node* x = root + u;
    access(x);
    while (x->left) x = x->left;
    splay(x);
    return x->label;
  }

  inline int lca(int u, int v) {
    Node* x = root + u;
    Node* y = root + v;
    access(x);
    return access(y)->label;
  }

  inline int depth(int u) {
    Node* x = root + u;
    access(x);
    return x->size - 1;
  }
};
