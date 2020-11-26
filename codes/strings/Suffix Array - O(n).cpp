#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

// find the suffix array p of s[0..n-1] with alphabet {1..k}
// require s[n-1]=0 (the sentinel!), n>=2
// use a working space (excluding s and p) of at most 2.25n+O(1) for a constant alphabet
void build(int* p, const int* s, int n, int k) {
  assert(n > 1 && s[n - 1] == 0);
  vi bkt(k + 1);
  vector<bool> t(n);
  auto isLMS = [&](int i) { return i > 0 && t[i] && !t[i - 1]; };
  auto getBuckets = [&](bool end) {
    bkt.assign(k + 1, 0);
    for (int i = 0; i < n; ++i) ++bkt[s[i]];
    if (end) for (int i = 1; i <= k; ++i) bkt[i] += bkt[i - 1];
    else for (int i = 0, sum = 0; i <= k; ++i) sum += bkt[i], bkt[i] = sum - bkt[i];
  };
  auto induce = [&]() {
    getBuckets(false);
    for (int i = 0, j; i < n; ++i) if (j = p[i] - 1, j >= 0 && !t[j]) p[bkt[s[j]]++] = j;
    getBuckets(true);
    for (int i = n - 1, j; i >= 0; --i) if (j = p[i] - 1, j >= 0 && t[j]) p[--bkt[s[j]]] = j;
  };
  t[n - 2] = 0;
  t[n - 1] = 1;
  for (int i = n - 3; i >= 0; --i) t[i] = s[i] != s[i + 1] ? s[i] < s[i + 1] : t[i + 1];
  getBuckets(true);
  for (int i = 0; i < n; ++i) p[i] = -1;
  for (int i = 1; i < n; ++i) if (isLMS(i)) p[--bkt[s[i]]] = i;
  induce();
  int m = 0, diff = 0;
  for (int i = 0; i < n; ++i) if (isLMS(p[i])) p[m++] = p[i];
  for (int i = m; i < n; ++i) p[i] = -1;
  for (int i = 0, prev = -1; i < m; ++i) {
    int pos = p[i];
    for (int j = 0; j < n; j++) {
      if (prev == -1 || s[pos+j] != s[prev+j] || t[pos+j] != t[prev+j]) {
        ++diff;
        prev = pos;
        break;
      }
      if (j > 0 && (isLMS(pos+j) || isLMS(prev+j))) break;
    }
    pos /= 2;
    p[m + pos] = diff - 1;
  }
  for (int i = n - 1, j = n - 1; i >= m; --i) if (p[i] >= 0) p[j--] = p[i];
  int *s1 = p + (n - m);
  if (diff == m) for (int i = 0; i < m; ++i) p[s1[i]] = i;
  else build(p, s1, m, diff - 1);
  getBuckets(true);
  for (int i = 1, j = 0; i < n; ++i) if (isLMS(i)) s1[j++] = i;
  for (int i = 0; i < m; ++i) p[i] = s1[p[i]];
  for (int i = m; i < n; ++i) p[i] = -1;
  for (int i = m - 1; i >= 0; --i) {
    int j = p[i];
    p[i] = -1;
    p[--bkt[s[j]]] = j;
  }
  induce();
}

vi build(const string& str) {
  const int alpha = 128;
  int value[alpha] = {-1};
  for (char c : str) value[(int)c] = 1;
  for (int i = 1; i < alpha; ++i) value[i] += value[i - 1];
  vi sm;
  sm.reserve(str.size());
  for (char c : str) sm.push_back(value[(int)c]);
  vi p(sm.size());
  build((int*)p.data(), (int*)sm.data(), (int)sm.size(), value[alpha - 1]);
  return p;
}

int main() {
  for (int t = 0; t < 1000; ++t) {
    string s(1000, 'a');
    for (char &c : s) c = (char)(rand() % 26 + 'a');
    s += s;
    s.push_back('$');
    // cerr << " ## " << s << endl;
    vi p = build(s);
    for (int i = 1; i < (int)s.size(); ++i) {
      assert(s.substr(p[i - 1]) < s.substr(p[i]));
    }
  }
  return 0;
}
