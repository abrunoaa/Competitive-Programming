#include <bits/stdc++.h>
using namespace std;

template <class T> struct Buffer {
  vector<T*> buf;

  ~Buffer() { for (auto ptr : buf) delete ptr; }

  template <class... Args>
  [[nodiscard]] T* get(Args... args) {
    if (buf.empty()) return new T(args...);
    T* p = buf.back();
    buf.pop_back();
    *p = T(args...);
    return p;
  }

  void free(T* ptr) { buf.push_back(ptr); }
};

/** begin *********************************************************************/
template<class Key> struct LeftistHeap {
  struct Node {
    Node* left;
    Node* right;
    Key key;
    int s;  // rank
    Node() {}
    Node(Key k) : left(0), right(0), key(k), s(1) {}
  };

  inline static Buffer<Node> buf;
  Node* root;

  LeftistHeap() : root(0) {}  // it's not worth building in O(n)
  ~LeftistHeap() { clear(); } // slow!

  inline void clear() { clear(root); root = 0; }
  [[nodiscard]] inline bool empty() { return !root; }
  [[nodiscard]] inline const Key& top() { return root->key; }
  inline void push(const Key& key) { root = merge(root, buf.get(key)); }
  inline void pop() { buf.free(root); root = merge(root->left, root->right); }
  inline void merge(LeftistHeap &h) { root = merge(root, h.root); h.root = 0; }

private:

  static void clear(Node* t) {
    if (t) {
      clear(t->left);
      buf.free(t);
      clear(t->right);
    }
  }

  [[nodiscard]] static Node* merge(Node* a, Node* b) {  // O(lg n)
    if (!a) return b;
    if (!b) return a;
    if (a->key > b->key) swap(a, b);
    a->right = merge(a->right, b);
    if (!a->left) {
      assert(a->s == 1);
      a->left = a->right;
      a->right = 0;
    } else {
      if (a->left->s < a->right->s) swap(a->left, a->right);
      a->s = 1 + a->right->s;           // a->right has the lowest rank
    }
    return a;
  }
};
/** end ***********************************************************************/

#define cerr if (0) cerr

typedef LeftistHeap<int>::Node Node;

void validateTree(Node* t) {
  if (!t) return;
  validateTree(t->left);
  validateTree(t->right);
  assert(!t->left || t->key <= t->left->key);
  assert(!t->right || t->key <= t->right->key);
  if (t->left && t->right) {
    assert(t->left->s >= t->right->s);
  }
}

void test(int n, int s, bool validate = 1) {
  cout << "Test n = " << n << ", s = " << s << '\n';
  srand(s);

  LeftistHeap<int> h;
  priority_queue<int,vector<int>,greater<int>> pq;

  for (int i = 0; i < n; ++i) {
    cerr << " > operation " << i << '\n';

    int r = rand() % 2;
    if (r < 1 && !pq.empty()) {
      pq.pop();
      cerr << " > pop\n";
      h.pop();
    } else if (r < 2) {
      int x = rand() % 100 + 1;
      pq.push(x);
      cerr << " > push " << x << '\n';
      h.push(x);
    }

    cerr << " > validate\n";
    assert(h.empty() == pq.empty());
    assert(h.empty() || h.top() == pq.top());
    if (validate) validateTree(h.root);
  }
}

int main() {
  for (int s = 0; s < 1000; ++s)
    test(10, s);
  for (int n = 1; n <= 1000; ++n)
    test(n, 0);
  for (int s = 0; s < 5; ++s)
    test(100000, s, 0);
  return 0;
}
