#include <bits/stdc++.h>
using namespace std;

#define maxn 100003
#define maxt (int)(maxn * log2(maxn) * 2)
#define M ((l + r) >> 1)

typedef long long ll;

struct Trie {
  int prev;
  map<char, Trie*> next;
};

int n;
int newSt, root[maxn], lc[maxt], rc[maxt];
ll st[maxt];
Trie* trie, *ntrie, alloc[maxt];

Trie* newTrie() {
  Trie* t = ntrie++;
  t->prev = 0;
  t->next.clear();
  return t;
}

void build(int t, int l = 1, int r = n) {
  st[t] = 0;
  if (l < r) {
    lc[t] = newSt++;
    rc[t] = newSt++;
    build(lc[t], l, M);
    build(rc[t], M + 1, r);
  }
}

int copy(int &u) {
  int v = newSt++;
  st[v] = st[u];
  lc[v] = lc[u];
  rc[v] = rc[u];
  return u = v;
}

ll upd(int i, int x, int t, int l = 1, int r = n) {
  if (r < i || i < l) { return st[t]; }
  if (l == r) { return st[t] += x; }
  if (i <= M) { return st[t] = upd(i, x, copy(lc[t]), l, M) + st[rc[t]]; }
  return st[t] = st[lc[t]] + upd(i, x, copy(rc[t]), M + 1, r);
}

ll qry(int i, int j, int t, int l = 1, int r = n) {
  if (r < i || j < l) { return 0; }
  if (i <= l && r <= j) { return st[t]; }
  return qry(i, j, lc[t], l, M) + qry(i, j, rc[t], M + 1, r);
}

void insert(int idx, const string &s) {
  Trie* r = trie;
  copy(root[idx] = root[idx - 1]);
  for (char c : s) {
    if (!r->next[c]) { r->next[c] = newTrie(); }
    r = r->next[c];
    int &p = r->prev;
    if (p) { upd(p, -1, root[idx]); }
    p = idx;
    upd(p, +1, root[idx]);
  }
}

void clear() {
  newSt = 0;
  root[0] = newSt++;
  build(root[0]);
  ntrie = alloc;
  trie = newTrie();
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  while (cin >> n) {
    clear();
    for (int i = 1; i <= n; ++i) {
      string s;
      cin >> s;
      insert(i, s);
    }
    int q;
    cin >> q;
    int z = 0;
    while (q--) {
      int l, r;
      cin >> l >> r;
      l = (l + z) % n + 1;
      r = (r + z) % n + 1;
      if (l > r) { swap(l, r); }
      z = qry(l, r, root[r]);
      cout << z << '\n';
    }
  }
  return 0;
}
