#define st first
#define nd second

template<class T> struct MaxQueue {
  int n;
  deque<pair<T, int>> q;

  MaxQueue() : n(0), q() {}

  bool empty() { return !n; }
  int size() { return n; }
  T front() { return q.front().st; }
  void clear() { n = 0; q.clear(); }
  void pop() { --n; if (!--q.front().nd) q.pop_front(); }
  void push(T x) {
    int k = 0;
    for (; !q.empty() && x >= q.back().st; q.pop_back()) { k += q.back().nd; }
    q.push_back({x, k + 1});
    ++n;
  }
};
