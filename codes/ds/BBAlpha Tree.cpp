#include <bits/stdc++.h>
using namespace std;

/** begin *********************************************************************/
template<class Key, class Value, int beta = 10> struct BBAlpha {
  static_assert(beta > 2);

  struct Node {
    inline static Node* const nil = new Node(0);
    Node* left;
    Node* right;
    int size;
    Key key;
    Value value;

    Node() : left(nil), right(nil), size(1), key(), value() {}

    Node(const Key &_key, const Value &_value)
      : left(nil), right(nil), size(1), key(_key), value(_value) {}

  private:
    Node(int) : left(this), right(this), size(0), key(), value() {}
  };

  inline static Node* const nil = Node::nil;
  inline static std::vector<Node*> pointers;
  Node* root;

  BBAlpha() : root(nil) {}
  ~BBAlpha() { clear(); }

  inline void clear() {
    clear(root);
    root = nil;
  }

  inline void insert(const Key &key, const Value &value) { insert(root, key, value); }
  inline void erase(const Key &key) { erase(root, key); }
  [[nodiscard]] inline bool empty() const { return (size() == 0); }
  [[nodiscard]] inline int size() const { return root->size; }
  [[nodiscard]] inline bool has(const Key &key) const { return (find(root, key) != nil); }
  [[nodiscard]] inline int height() { return height(root); }

  inline Value &operator[](const Key &key) {
    Node* ptr = find(root, key);
    if (ptr == nil) {
      insert(key, Value());
      ptr = find(root, key);
    }
    return ptr->value;
  }

private:

  static void clear(Node* t) {
    if (t != nil) {
      clear(t->left);
      clear(t->right);
      delete t;
    }
  }

  [[nodiscard]] static Node* findMin(Node* t) {
    while (t->left != nil) t = t->left;
    return t;
  }

  [[nodiscard]] static Node* findMax(Node* t) {
    while (t->right != nil) t = t->right;
    return t;
  }

  static void savePointers(Node* t) { // in order
    if (t != nil) {
      savePointers(t->left);
      pointers.push_back(t);
      savePointers(t->right);
    }
  }

  static void build(Node* &t, int l, int r) {
    if (l > r) {
      t = nil;
      return;
    }
    int m = (l + r) / 2;
    t = pointers[m];
    build(t->left, l, m - 1);
    build(t->right, m + 1, r);
    t->size = 1 + t->left->size + t->right->size;
  }

  static void update(Node* &t) {
    if (t == nil) return;
    t->size = 1 + t->left->size + t->right->size;
    int n = t->size / beta;
    if (t->left->size < n || t->right->size < n) {  // balance tree
      pointers.clear();
      savePointers(t);
      build(t, 0, (int)pointers.size() - 1);
    }
  }

  [[nodiscard]] static Node* find(Node* t, const Key &key) {
    while (t != nil) {
      if (key < t->key) {
        t = t->left;
      } else if (t->key < key) {
        t = t->right;
      } else {
        return t;
      }
    }
    return nil;
  }

  static void insert(Node* &t, const Key &key, const Value &value) {
    if (t == nil) {
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

  static void erase(Node* &t, const Key &key) {
    if (t == nil) return;                         // not found
    if (key < t->key) {
      erase(t->left, key);
    } else if (t->key < key) {
      erase(t->right, key);
    } else if (t->left == nil) {
      Node* removed = t;
      t = t->right;
      delete removed;
    } else if (t->right == nil) {
      Node* removed = t;
      t = t->left;
      delete removed;
    } else {
      Node* s = findMin(t->right);
      std::swap(t->key, s->key);
      std::swap(t->value, s->value);
      erase(t->right, key);
    }
    update(t);
  }

  [[nodiscard]] static int height(Node* t) {
    return t == nil ? 0 : 1 + std::max(height(t->left), height(t->right));
  }
};
/** end ***********************************************************************/

#define cerr if (0) cerr

void test(int n, int s, bool compare = 1) {
  cout << "Running n = " << n << ", s = " << s << endl;

  srand(s);
  BBAlpha<int, int> bb;
  map<int, int> mp;

  for (int i = 0; i < n; ++i) {
    int r = rand() % 3;
    cerr << " >> operation " << i << ": " << r << '\n';
    if (r < 1 && mp.size() >= 2) {
      auto it = mp.begin();
      ++it;
      int v = it->first;
      mp.erase(v);

      cerr << " >> erase " << v << '\n';
      bb.erase(v);
    } else if (r < 3) {
      int k = rand() % 1001 - 500;
      int v = rand() % 1001 - 500;
      mp[k] = v;

      cerr << " >> insert " << k << ' ' << v << '\n';
      bb[k] = v;
    }

    cerr << " >> check\n";
    assert(bb.empty() == mp.empty());
    assert(bb.size() == (int)mp.size());
    assert(!compare || all_of(mp.begin(), mp.end(), [&](auto k) {
      return bb.has(k.first) && bb[k.first] == k.second;
    }));
  }
}

int main() {
  for (int s = 0; s < 500; ++s)
    test(10, s);
  for (int n = 1; n <= 500; ++n)
    test(n, 0);
  for (int s = 0; s < 10; ++s)
    test(100000, s, 0);
  return 0;
}
