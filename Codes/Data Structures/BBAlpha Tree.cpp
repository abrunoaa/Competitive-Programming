#include <algorithm>
#include <vector>

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

    Node(const Key &key, const Value &value) :
      left(nullptr),
      right(nullptr),
      size(1),
      key(key),
      value(value)
    {}
  };

  static inline int size(Node* t) {
    return (t == nullptr ? 0 : t->size);
  }

  Node* root;
  std::vector<Node*> pointers;

  BBAlpha() :
    root(nullptr)
  {}

  ~BBAlpha() {
    clear();
  }

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

  inline bool empty() const {
    return (root == nullptr);
  }

  inline int size() const {
    return (root == nullptr ? 0 : root->size);
  }

  static Node* findMin(Node* t) {
    while (t->left != nullptr) {
      t = t->left;
    }
    return t;
  }

  static Node* findMax(Node* t) {
    while (t->right != nullptr) {
      t = t->right;
    }
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
      ;
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

  inline void insert(const Key &key, const Value &value) {
    insert(root, key, value);
  }

  void erase(Node* &t, const Key &key) {
    if (t == nullptr) {
      throw "Value not found!";
    }
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
    if (t != nullptr) {
      update(t);
    }
  }

  inline void erase(const Key &key) {
    erase(root, key);
  }

  inline bool has(const Key &key) const {
    return (find(root, key) != nullptr);
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
    if (!t) { return 0; }
    return 1 + std::max(height(t->left), height(t->right));
  }

  int height() {
    return height(root);
  }

};  /// \class BBAlpha

#include <iostream>
#include <random>
#include <map>
using namespace std;

int main() {
  srand(2019);
  BBAlpha<int, int, 10> bb;
  map<int, int> mp;
  for (int i = 0; i < 1000000; ++i) {
    if (i % 100000 == 0) { cerr << " >> at operation " << i << endl; }
    int op = rand() % 13;
    int key = rand() % 100007;
    int value = rand() % 1000;
    //cerr << " >>>> operation " << i << ": "  << op << ' ' << key << ' ' << value << endl;
    if (op < 7) {
      bb[key] = value;
      mp[key] = value;
    } else if (op < 12) {
      if (!mp.count(key)) {
        assert(!bb.has(key));
      } else {
        mp.erase(key);
        bb.erase(key);
      }
    } else {
      assert(bb[key] == mp[key]);
    }
    assert(bb.size() == (int)mp.size());
  }
  cerr << "ended with " << bb.size() << " keys and height " << bb.height() << endl;
  cerr << "everything looks good!\n";
  return 0;
}