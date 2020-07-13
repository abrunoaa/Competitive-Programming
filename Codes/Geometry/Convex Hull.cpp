#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct pt { // using integers
  int x, y;
  bool operator==(const pt& p) const { return x == p.x && y == p.y; }
  bool operator<(const pt& p) const { return x != p.x ? x < p.x : y < p.y; }
};

// area2 > 0 => cb is ccw wrt ca; = 0 => collinear; < 0 => cw
// 2 * triangle area = (a-c)x(b-c) = axb + bxc + cxa
ll area2(pt &c, pt &a, pt &b) {
  return (ll)(a.x - c.x) * (b.y - c.y) - (ll)(a.y - c.y) * (b.x - c.x);
}

void monotoneChain(vector<pt> &p) {     // returns p[0] != p[n]
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  if (p.size() <= 2) return;
  vector<pt> up, dn;
  for (int i = 0; i < (int)p.size(); ++i) {
    while (up.size() > 1 && area2(p[i], up[up.size() - 2], up.back()) >= 0) up.pop_back();
    while (dn.size() > 1 && area2(p[i], dn[dn.size() - 2], dn.back()) <= 0) dn.pop_back();
    up.push_back(p[i]);
    dn.push_back(p[i]);
  }
  p = dn;
  p.insert(p.end(), up.rbegin() + 1, up.rend() - 1);
}

// ---------------------- TESTS ----------------------
vector<pt> algorithmist(vector<pt> P) {
  // Sort points lexicographically
  sort(P.begin(), P.end());
  P.erase(unique(P.begin(), P.end()), P.end());
  if (P.size() <= 1) return P;

  int n = (int)P.size(), k = 0;
  vector<pt> H(2*n);

  // Build lower hull
  for (int i = 0; i < n; i++) {
    while (k >= 2 && area2(H[k-2], H[k-1], P[i]) <= 0) k--;
    H[k++] = P[i];
  }

  // Build upper hull
  for (int i = n-2, t = k+1; i >= 0; i--) {
    while (k >= t && area2(H[k-2], H[k-1], P[i]) <= 0) k--;
    H[k++] = P[i];
  }

  H.resize(k);
  if (H[0] == H.back()) H.pop_back();
  return H;
}

void test() {
  srand(0);
  int T = 10000000;
  for (int t = 0; t < T; ++t) {
    int n = rand() % 10 + 1;
    // cerr << " -------------- " << t << " -------------- " << endl;
    vector<pt> p(n);
    int r = 11;
    for (auto &a : p) {
      a.x = rand() % r - r / 2;
      a.y = rand() % r - r / 2;
    }
    // for (auto a : p) cerr << " !! " << a.x << ' ' << a.y << '\n';
    auto expected = algorithmist(p);
    monotoneChain(p);
    // for (auto a : expected) cerr << " ## " << a.x << ' ' << a.y << '\n';
    // for (auto a : p) cerr << " >> " << a.x << ' ' << a.y << '\n';
    assert(expected.size() == p.size());
    assert(set(expected.begin(), expected.end()) == set(p.begin(), p.end()));
    for (int i = 2; i < (int)p.size(); ++i) {
      assert(area2(p[i - 2], p[i - 1], p[i]) > 0);
    }
  }
}

int main() {
  test();
  return 0;
}
