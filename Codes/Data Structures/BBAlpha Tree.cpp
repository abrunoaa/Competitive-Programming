template<class Key, class Value, int inverseAlpha> struct BBAlpha {
  static_assert(inverseAlpha > 2, "Alpha must be < 1/2");

  struct Node {
    Node* left;
    Node* right;
    int size;
    Key key;
    Value value;

    Node() :
      left(nullptr),
      right(nullptr),
      size(1),
      key(),
      value()
    {}

    Node(const Key &_key, const Value &_value) :
      left(nullptr),
      right(nullptr),
      size(1),
      key(_key),
      value(_value)
    {}
  };

  static inline int size(Node* t) { return (t == nullptr ? 0 : t->size); }

  Node* root;
  std::vector<Node*> pointers;

  BBAlpha() : root(nullptr) {}
  ~BBAlpha() { clear(); }

  static void clear(Node* t) {
    if (t != nullptr) {
      clear(t->left);
      clear(t->right);
      delete t;
    }
  }

  inline void clear() {
    clear(root);
    root = nullptr;
  }

  inline bool empty() const { return (root == nullptr); }
  inline int size() const { return (root == nullptr ? 0 : root->size); }

  static Node* findMin(Node* t) {
    while (t->left != nullptr) t = t->left;
    return t;
  }

  static Node* findMax(Node* t) {
    while (t->right != nullptr) t = t->right;
    return t;
  }

  void inOrder(Node* t) {
    if (t) {
      inOrder(t->left);
      pointers.push_back(t);
      inOrder(t->right);
    }
  }

  void build(Node* &t, int l, int r) {
    if (l > r) {
      t = nullptr;
      return;
    }
    int m = (l + r) / 2;
    t = pointers[m];
    build(t->left, l, m - 1);
    build(t->right, m + 1, r);
    t->size = 1 + size(t->left) + size(t->right);
  }

  void update(Node* &t) {
    t->size = 1 + size(t->left) + size(t->right);
    int n = t->size / inverseAlpha;
    if (size(t->left) < n || size(t->right) < n) {
      pointers.clear();
      inOrder(t);
      build(t, 0, (int)pointers.size() - 1);
    }
  }

  static Node* find(Node* t, const Key &key) {
    while (t) {
      if (key < t->key) {
        t = t->left;
      } else if (t->key < key) {
        t = t->right;
      } else {
        return t;
      }
    }
    return nullptr;
  }

  void insert(Node* &t, const Key &key, const Value &value) {
    if (t == nullptr) {
      t = new Node(key, value);
      return;
    }
    if (key < t->key) {
      insert(t->left, key, value);
    } else if (t->key < key) {
      insert(t->right, key, value);
    } else {
      t->value = value;
    }
    update(t);
  }

  void erase(Node* &t, const Key &key) {
    if (t == nullptr) throw "Value not found!";
    if (key < t->key) {
      erase(t->left, key);
    } else if (t->key < key) {
      erase(t->right, key);
    } else if (t->left == nullptr) {
      Node* removed = t;
      t = t->right;
      delete removed;
    } else if (t->right == nullptr) {
      Node* removed = t;
      t = t->left;
      delete removed;
    } else {
      Node* s = findMin(t->right);
      std::swap(t->key, s->key);
      std::swap(t->value, s->value);
      erase(t->right, key);
    }
    if (t != nullptr) update(t);
  }

  inline Value &operator[](const Key &key) {
    Node* ptr = find(root, key);
    if (ptr == nullptr) {
      insert(key, Value());
      ptr = find(root, key);
    }
    return ptr->value;
  }

  int height(Node* t) {
    return !t ? 0 : 1 + std::max(height(t->left), height(t->right));
  }

  void insert(const Key &key, const Value &value) { insert(root, key, value); }
  void erase(const Key &key) { erase(root, key); }
  bool has(const Key &key) const { return (find(root, key) != nullptr); }
  int height() { return height(root); }
};  /// \class BBAlpha
