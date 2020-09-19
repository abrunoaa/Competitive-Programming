#include <bits/stdc++.h>
using namespace std;

#define rand() uid(rng)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); // ll = mt19937_64
uniform_int_distribution<int> uid(0, numeric_limits<int>::max());             // range for random

namespace BBAlpha {
  #include "../Data Structures/BBAlpha Tree.cpp"

  int main() {
    srand(2019);
    BBAlpha<int, int, 10> bb;
    map<int, int> mp;
    for (int i = 0; i < 1000000; ++i) {
      // if (i % 100000 == 0) { cerr << " >> at operation " << i << endl; }
      int op = rand() % 13;
      int key = rand() % 100007;
      int value = rand();
      // cerr << " >>>> operation " << i << ": "  << op << ' ' << key << ' ' << value << endl;
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
    cerr << "BB ended with " << bb.size() << " keys and height " << bb.height() << endl;
    // cerr << "everything looks good!\n";
    return 0;
  }
}

namespace BIT {
  #include "../Data Structures/BIT - Fenwick Tree.cpp"
}

namespace PersistentQueue {
  #include "../Data Structures/Persistent Queue.cpp"

  Queue<int> q;
  queue<int> r[maxr];

  void main() {
    for (int i = 1; i < maxr; ++i) {
      int op = rand() % 7;
      int v = rand() % i;
      if (op <= 4 || r[v].empty()) {
        int x = rand() % 10 + 1;
        // cerr << " -- " << i << " add " << x << " to " << v << endl;
        q.push(v, x);
        r[i] = r[v];
        r[i].push(x);
      } else {
        // cerr << " -- " << i << " pop " << r[v].front() << " from " << v << endl;
        q.pop(v);
        r[i] = r[v];
        r[i].pop();
      }
      if (!r[v].empty() && r[v].front() != q.front(v)) {
        cerr << " ## " << r[v].front() << ' ' << q.front(v) << endl;
        assert(0);
      }
      if (!r[i].empty() && r[i].front() != q.front(i)) {
        cerr << " >> " << r[i].front() << ' ' << q.front(i) << endl;
        assert(0);
      }
    }
  }
}

int main() {
  // PersistentQueue::main();
  BBAlpha::main();
  return 0;
}
