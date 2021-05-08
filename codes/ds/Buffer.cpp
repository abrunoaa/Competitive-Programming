#include <bits/stdc++.h>
using namespace std;

/** begin *********************************************************************/
template <class T> struct Buffer {
  vector<T*> buf;

  ~Buffer() { for (auto ptr : buf) delete ptr; }  // slow!

  template <class... Args>
  [[nodiscard]] T* get(const Args&... args) {
    if (buf.empty()) return new T(args...);
    T* p = buf.back();
    buf.pop_back();
    *p = T(args...);
    return p;
  }

  void free(T* ptr) { buf.push_back(ptr); }
};
/** end ***********************************************************************/

struct Node {
  int v1, v2;

  Node() {
    v1 = v2 = -1;
  }

  Node(int a, int b) {
    v1 = a;
    v2 = b;
  }
};

Buffer<Node> buf;

int main() {
  Node* ptr;

  ptr = buf.get(11, 7);
  assert(ptr->v1 == 11 && ptr->v2 == 7);
  buf.free(ptr);

  ptr = buf.get(1, 2);
  assert(ptr->v1 == 1 && ptr->v2 == 2);
  buf.free(ptr);

  ptr = buf.get();
  assert(ptr->v1 == -1 && ptr->v2 == -1);
  buf.free(ptr);

  cout << "done.\n";
  return 0;
}
