#include <bits/stdc++.h>
using namespace std;

/** begin *********************************************************************/
#define st first
#define nd second

template<class T> struct MaxQueue {
  int n;
  deque<pair<T, int>> q;

  MaxQueue() : n(0), q() {}

  [[nodiscard]] inline bool empty() { return !n; }
  [[nodiscard]] inline int size() { return n; }
  [[nodiscard]] inline T& front() { return q.front().st; }
  void clear() { n = 0; q.clear(); }
  void pop() { --n; if (!--q.front().nd) q.pop_front(); }
  void push(T x) {
    int k = 0;          // <= for MinQueue
    for (; !q.empty() && x >= q.back().st; q.pop_back()) k += q.back().nd;
    q.push_back({x, k + 1});
    ++n;
  }
};
/** end ***********************************************************************/

#define cerr if (0) cerr

void test(int n, int seed) {
  cout << "Test with n = " << n << ", seed = " << seed << "\n";

  srand(seed);
  queue<int> q;
  multiset<int, greater<int>> s;
  MaxQueue<int> mq;
  for (int i = 0; i < n; ++i) {
    cerr << " > operation " << i << "\n";
    int r = rand() % 2;
    if (r < 1 && !q.empty()) {
      s.erase(s.find(q.front()));
      q.pop();

      cerr << " > pop\n";
      mq.pop();
    } else if (r < 2) {
      int x = rand() % 10001 - 5000;
      s.insert(x);
      q.push(x);

      cerr << " > push " << x << "\n";
      mq.push(x);
    }

    assert((int)q.size() == mq.size());
    assert(q.empty() == mq.empty());
    assert(mq.empty() || *s.begin() == mq.front());
  }

  mq.clear();
}

int main() {
  for (int s = 0; s < 1000; ++s)
    test(10, s);
  for (int n = 1; n <= 1000; ++n)
    test(n, 0);
  return 0;
}
