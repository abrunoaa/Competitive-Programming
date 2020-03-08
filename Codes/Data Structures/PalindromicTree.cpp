#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e5 + 3;

struct PalindromicTree {  // ERRTREE
  int root, empty, maxSuf, d;
  string str;
  int length[maxn + 2];
  int link[maxn + 2];
  int occ[maxn + 2];          // frequency of each palindrome
  map<char, int> child[maxn + 2];

  PalindromicTree()
      : root(maxn - 1), empty(0), maxSuf(root), d(0), str("$") {
    length[0] = 0;
    length[root] = -1;
    link[0] = link[root] = root;
    occ[0] = occ[root] = 0;
  }

  bool add(char c) {
    int n = (int)str.size() - 1;
    auto up = [n, c, this](int p) {
      for (; p != root && c != str[n - length[p]]; p = link[p]);
      return p;
    };

    str.push_back(c);
    maxSuf = up(maxSuf);
    if (child[maxSuf].count(c)) {
      maxSuf = child[maxSuf][c];
      ++occ[maxSuf];
      return false;
    }

    ++d;
    length[d] = length[maxSuf] + 2;
    link[d] = maxSuf == root ? empty : child[up(link[maxSuf])][c];
    occ[d] = 1;
    maxSuf = child[maxSuf][c] = d;
    return true;
  }

  void updateAllOccurences() {
    for (int v = d; v > 0; --v) occ[link[v]] += occ[v];
  }
} p;

int main() {
  string s = "aabcaa";
  for (char c : s) {
    cerr << " >> " << c << ' ' << p.add(c) << endl;
  }
  cout << p.d << '\n';
  return 0;
}
