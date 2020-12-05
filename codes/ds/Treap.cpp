#include <bits/stdc++.h>
using namespace std;

/** begin *********************************************************************/
template <class T> struct Treap {
  struct Node {
    inline static Node* const nil = new Node(nullptr);
    Node *left, *right;
    int size, priority;
    T x;
    T sum, lazy;
    bool reverse;

    Node() {}
    Node(const T& _x) : left(nil), right(nil), size(1), priority(rand()), x(_x),
        sum(_x), lazy(0), reverse(0) {}

    void prop() {
      if (lazy) {
        x += lazy;
        sum += size * lazy;
        left->lazy += lazy; // may overflow on nil
        right->lazy += lazy;
        lazy = 0;
      }
      if (reverse) {
        swap(left, right);
        left->reverse ^= 1;
        right->reverse ^= 1;
        reverse = 0;
      }
    }

    void update() {
      size = 1 + left->size + right->size;
      sum = x + left->sum + right->sum;
    }

  private:
    Node(int*) : left(this), right(this), size(0), priority(-1), x(), sum(0) {}
  };

  inline static Node* const nil = Node::nil;
  Node* root;

  Treap() : root(nil) {}

  inline void clear() { root = nil; }
  [[nodiscard]] inline bool empty() { return size() == 0; }
  [[nodiscard]] inline int size() { return root->size; }
  void insert(int i, const T& x) { work(i, i - 1, [&](){ root = new Node(x); }); }
  void erase(int i, int j) { work(i, j, [&](){ clear(); }); }
  void update(int i, const T& x) { work(i, i, [&](){ root->x = root->sum = x; }); }
  void add(int i, int j, const T& x) { work(i, j, [&](){ root->lazy = x; }); }
  void reverse(int i, int j) { work(i, j, [&](){ root->reverse = 1; }); }
  [[nodiscard]] int sum(int i, int j) { int s; work(i, j, [&](){ s = root->sum; }); return s; }
  void rotate(int i, int newi, int j) {
    work(i, j, [&](){
      Node *a, *b;
      split(root, a, b, newi - i);
      merge(root, b, a);
    });
  }

private:

  // merge l and r (max(l) <= min(r)) saving into t (l and r becomes invalid)
  static void merge(Node* &t, Node* l, Node* r) {
    l->prop();
    r->prop();
    if (l == nil) t = r;
    else if (r == nil) t = l;
    else if (l->priority > r->priority) merge(l->right, l->right, r), t = l;
    else merge(r->left, l, r->left), t = r;
    t->update();
  }

  // splits t into the first n elements in l and others in r (t becomes invalid)
  static void split(Node* t, Node* &l, Node* &r, int n) {
    if (t == nil) { l = r = nil; return; }
    t->prop();
    int nl = t->left->size;
    if (nl < n) split(t->right, t->right, r, n - 1 - nl), l = t;
    else split(t->left, l, t->left, n), r = t;
    t->update();
  }

  // treap remains with elements from i to j (inclusive), then calls `operation`
  void work(int i, int j, const function<void()>& operation) {
    Node *l, *r;
    split(root, l, r, i); // before i goes to l
    split(r, root, r, j - i + 1); // after j goes to r
    operation();
    merge(root, l, root); // merge again
    merge(root, root, r);
  }
};
/** end ***********************************************************************/

int main() {
  Treap<int> t;
  t.insert(1, 2);
  return 0;
}
