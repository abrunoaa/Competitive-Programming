/// lis O(n lg n)
int n;              // n números
int a[maxn];        // vetor

int lis() {
  vector<int> ans = {a[0]};
  for (int i = 1; i < n; ++i)
    if (a[i] > ans.back()) {
      ans.push_back(a[i]);
    } else {
      *lower_bound(ans.begin(), ans.end(), a[i]) = a[i];
    }
  return (int)ans.size();
}

/// lis com reconstrução
int b[maxn];        // memória para reconstruir
ii ft[maxn];

void rec(int i) {
  if (i < 0) return;
  rec(b[i]);
  assert(b[i] == -1 || a[b[i]] < a[i]);
}

void upd(int i, ii x) { for (; i < maxn; i += i & -i) ft[i] = max(ft[i], x); }

ii qry(int i) {
  ii ans(0, -1);
  for (; i; i -= i & -i) ans = max(ans, ft[i]);
  return ans;
}

ii recLis() {
  memset(ft, -1, sizeof ft);
  ii ans(0, -1);
  for (int i = 0; i < n; ++i) {
    ii x = qry(a[i]);         // assume que a[i] > 0
    b[i] = x.nd;
    ++x.st;
    x.nd = i;
    ans = max(ans, x);
    upd(a[i] + 1, x);
  }
  return ans;
}
