#define maxn 100003
#define maxr maxn   // nº de revisões

template<class T> struct Array { // vetor em uma treap, modifica apenas o valor
  struct Node {
    T x;
    int idx;
    Node* left, *right;
    Node() {}
    Node(const T &x, int i, Node* l, Node* r) : x(x), idx(i), left(l), right(r) {}
  };

  int nv;           // nº de versões
  Node* root[maxr]; // raíz de cada versão

  Array(const T* a, int n) : nv(0) {
    vector<int> v(n, 0);
    iota(v.begin(), v.end(), 0);
    random_shuffle(v.begin(), v.end());
    for (int i : v) { insert(root[0], i, a[i]); }
  }

  void insert(Node* &t, int i, const T &x) { // usa apenas na hora de criar
    if (!t) { t = new Node(i, x, 0, 0); }
    else if (i < t->i) { insert(t->left, i, x); }
    else { insert(t->right, i, x); }
  }

  Node* copy(Node* &t) {
    Node* u = new Node();
    memcpy(u, t, sizeof(Node));
    return t = u;
  }

  void upd(int v, int i, const T &x) {
    Node* &t = root[++nv] = root[v];
    copy(t);
    while (i != t->i) { t = i < t->i ? copy(t->left) : copy(t->right); }
    t->x = x;
  }

  const T &get(Node* t, int i) {
    while (i != t->i) { t = i < t->i ? t->left : t->right; }
    return t->x;
  }
};
