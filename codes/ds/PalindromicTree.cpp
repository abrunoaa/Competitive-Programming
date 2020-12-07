#include <bits/stdc++.h>
using namespace std;

/** begin *********************************************************************/
struct PalindromicTree {  // also known as ERRTREE
  int root, empty, maxSuf, d; // d is the number of palindromes
  string str;
  vector<int> length, link, occ; // occ is the frequency of each palindrome
  vector<map<char, int>> child;

  PalindromicTree(int n) : root(n), empty(0), maxSuf(root), d(0), str("$"),
      length(n + 1), link(n + 1), occ(n + 1), child(n + 1) {
    length[root] = -1;
    link[0] = link[root] = root;
  }

  bool add(char c) {  // returns true if c adds a new palindrome substring
    assert(str.size() < link.size());
    str.push_back(c);
    maxSuf = up(maxSuf, c);
    if (child[maxSuf].count(c)) {
      maxSuf = child[maxSuf][c];
      ++occ[maxSuf];
      return false;
    }

    ++d;
    length[d] = length[maxSuf] + 2;
    link[d] = maxSuf == root ? empty : child[up(link[maxSuf], c)][c];
    occ[d] = 1;
    maxSuf = child[maxSuf][c] = d;
    return true;
  }

  void updateAllOccurences() { for (int v = d; v > 0; --v) occ[link[v]] += occ[v]; }

private:

  int up(int p, char c) {
    int k = (int)str.size() - 2;
    for (; p != root && c != str[k - length[p]]; p = link[p]);
    return p;
  }
};
/** end ***********************************************************************/

int main() {
  string s = "aabbaa";
  PalindromicTree p((int)s.size());
  for (char c : s) {
    bool a = p.add(c);
    cerr << " >> " << c << ' ' << a << endl;
    assert(a);
  }
  cout << p.d << '\n';
  return 0;
}
