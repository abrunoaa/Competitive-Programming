#include <bits/stdc++.h>
using namespace std;

/** begin *********************************************************************/
#define hsz (int)heap.size()

template <class T> struct IndexedHeap {
  vector<T> val; // any value is never removed
  vector<int> idx; // idx[i] = index of val[i] in heap; any value is never removed
  vector<int> heap; // val[heap[i]] has priority i (0 is the highest)

  IndexedHeap(int n = 16) {
    val.reserve(n);
    heap.reserve(n);
    idx.reserve(n);
  }

  inline bool empty() const { return hsz == 0; }
  inline int size() const { return hsz; }
  inline const T& top() const { return get(0); }
  inline const T& find(int id) const { return get(idx[id]); }

  void push(const T& p) {
    val.push_back(p);
    heap.push_back((int)val.size() - 1);
    idx.push_back(hsz - 1);
    siftUp(hsz - 1);
  }

  inline void pop() { popHeap(0, heap[0]); }
  inline void pop(int id) { popHeap(idx[id], id); }

  void update(int id, const T& newVal) {
    val[id] = newVal;
    int h = idx[id];
    h != 0 && higher(h, parent(h)) ? siftUp(h) : siftDown(h);
  }

// private:

  void popHeap(int h, int id) {
    exchange(h, hsz - 1);
    idx[id] = -1;
    heap.pop_back();
    h != 0 && h < hsz && higher(h, parent(h)) ? siftUp(h) : siftDown(h);
  }

  inline int parent(int h) const { return (h - 1) >> 1; }
  inline int child(int h) const { return (h << 1) + 1; }
  inline const T& get(int h) const { return val[heap[h]]; }

  // h has more priority than k?
  inline bool higher(int h, int k) const { return get(h) < get(k); }

  void siftUp(int h) { for (int p; p = parent(h), h != 0 && higher(h, p); h = p) exchange(h, p); }
  void siftDown(int h) {
    for (int c; c = child(h), c += (c + 1 < hsz) && higher(c + 1, c), c < hsz && higher(c, h); h = c) exchange(h, c);
  }

  void exchange(int h, int k) {
    swap(idx[heap[h]], idx[heap[k]]);
    swap(heap[h], heap[k]);
  }
};

#undef hsz
/** end ***********************************************************************/

#define cerr if (0) cerr

template <class T>
void validate(const IndexedHeap<T>& h) {
  cerr << "> val:";
  if (h.empty()) cerr << " (empty)";
  for (int x : h.val) cerr << ' ' << x;
  cerr << '\n';
  cerr << "> heap:";
  if (h.empty()) cerr << " (empty)";
  for (int x : h.heap) cerr << ' ' << x;
  cerr << '\n';
  cerr << "> heap*:";
  if (h.empty()) cerr << " (empty)";
  for (int x : h.heap) cerr << ' ' << h.val[x];
  cerr << '\n';
  cerr << "> idx:";
  if (h.empty()) cerr << " (empty)";
  for (int x : h.idx) cerr << ' ' << x;
  cerr << '\n';

  cerr << "Validating... ";
  assert(h.val.size() == h.idx.size());

  int deleted = 0;
  for (int id : h.idx) deleted += id == -1;
  assert(h.heap.size() + deleted == h.val.size());

  for (int i = 0; i < (int)h.heap.size(); ++i) assert(h.idx[h.heap[i]] == i);

  for (int i = 1; i < (int)h.heap.size(); ++i) cerr << h.parent(i) << ' ' << i << endl, assert(!h.higher(i, h.parent(i)));
  cerr << "done.\n";
}

void test(int n, int up, int seed, bool callValidate = 1) {
  srand(seed);

  vector<int> val(n);
  vector<bool> deleted(n, 0);
  for (int i = 0; i < n; ++i) val[i] = rand() % up + 1;

  cerr << "\n---\n\n";
  cout << "Testing n = " << n << ", seed = " << seed << '\n';
  cerr << "Items:";
  for (int x : val) cerr << ' ' << x;
  cerr << '\n';

  int headDel = 0;

  IndexedHeap<int> h(n);
  for (int i = 0; i < n; ++i) {
    int op = rand() % 10;
    if (op < 1 && !h.empty()) {
      cerr << "Pop head... ";
      assert(!deleted[h.heap[0]]);
      deleted[h.heap[0]] = 1;
      h.pop();
      cerr << "done.\n";
      if (callValidate) validate(h);
    } else if (op < 3 && !h.empty()) {
      while (deleted[headDel]) ++headDel;
      int k = headDel + (h.heap.size() > 1);
      while (deleted[k]) ++k;

      cerr << "Pop index " << k << "... ";
      assert(!deleted[k]);
      deleted[k] = 1;
      h.pop(k);
      cerr << "done.\n";
      if (callValidate) validate(h);
    } else if (op < 6 && !h.empty()) {
      while (deleted[headDel]) ++headDel;
      int k = headDel + (h.heap.size() > 1);
      while (deleted[k]) ++k;

      cerr << "Update index " << k << "... ";
      assert(!deleted[k]);
      val[k] = rand() % up + 1;
      h.update(k, val[k]);
      cerr << "done.\n";
    }

    cerr << "Push value " << val[i] << "... ";
    h.push(val[i]);
    cerr << "done.\n";
    if (callValidate) validate(h);
  }

  assert(h.val == val);

  for (int x : h.heap) assert(!deleted[x]);
}

int main() {
  cout << "Template test.\n";
  IndexedHeap<string> h;
  h.push("test");
  assert(h.top() == "test");
  h.push("all");
  assert(h.top() == "all");
  h.push("zebra");
  assert(h.top() == "all");
  h.pop();
  assert(h.top() == "test");
  h.pop();
  assert(h.top() == "zebra");
  h.pop();
  assert(h.empty());

  cout << "Small tests.\n";
  for (int n = 2; n <= 10; ++n)
    for (int s = 0; s < 10000; ++s)
      test(n, 5, s);

  cout << "Huge tests.\n";
  for (int n : {100, 1000})
    for (int s = 0; s < 10; ++s)
      test(n, 100, s);

  cout << "Stress tests.\n";
  for (int n : {10000, 50000})
    for (int s = 0; s < 5; ++s)
      test(n, 1000, s, false);
  return 0;
}
