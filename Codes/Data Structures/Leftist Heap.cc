#define maxa 10000003  // máximo de nós alocados antes de um init

/************************ Key é sempre passado por cópia! ************************/
template<class Key> struct Node {
  Node *left, *right;
  Key key;
  int s;  // rank do nó
  Node() {}
  Node(Key k) : left(0), right(0), key(k), s(1) {}

  static Node *pnew, buf[];
  inline static void* operator new(size_t){ return pnew++; }
  inline static void operator delete(void*){}
  inline static void init(){ pnew = buf; }
};

template<class Key> Node<Key> *Node<Key>::pnew;
template<class Key> Node<Key> Node<Key>::buf[maxa];

template<class Key> struct LeftistHeap {
  typedef ::Node<Key> Node;

  static Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->key > b->key) swap(a, b);
    a->right = merge(a->right, b);
    if (!a->left) {                     // o rank 's' de a com certeza é 1
      a->left = a->right;
      a->right = 0;
    }
    else {
      if (a->left->s < a->right->s) swap(a->left, a->right);
      a->s = 1 + a->right->s;           // a->right tem o menor rank
    }
    return a;
  }

  Node* root;
  LeftistHeap() : root(0) { Node::init(); } // não vale apena construir em O(n)

  inline void clear(){ root = 0; }
  inline bool empty() { return !root; }
  inline Key top() { return root->key; }

  // Todas operações em O(lg n)
  inline void push(Key key) { root = merge(root, new Node(key)); }
  inline void pop() { root = merge(root->left, root->right); }
  inline void merge(LeftistHeap& h) {
    root = merge(root, h.root);
    h.root = 0;
  }

  static void print(Node* r) {
    if(!r) return;
    print(r->left);
    cerr << ' ' << r->key;
    print(r->right);
  }
  void print() { cerr << " > T ="; print(root); cerr << endl; }
};
