int ft[maxn], fat[maxn];

ll permutationIndex_2(int* p, int n) { // O(n^2)
  ll idx = 0;
  for (int i = n - 1; i >= 0; --i) {
    int k = 0;
    for (int j = i + 1; j < n; ++j)
      if (p[i] > p[j])
        ++k;
    idx = (idx + (ll)k * fat[n - i - 1]) % mod;
  }
  return idx;
}

int qry(int i) {
  int s = 0;
  for (; i; i -= i & -i) s += ft[i];
  return s;
}

void upd(int i) { for (; i < maxn; i += i & -i) ++ft[i]; }

ll permutationIndex(int* p, int n) { // O(n)
  memset(ft, 0, sizeof ft);
  ll idx = 0;
  for (int i = n - 1; i >= 0; --i) {
    idx = (idx + (ll)qry(p[i]) * fat[n - i - 1]) % mod;
    upd(p[i] + 1);
  }
  return idx;
}
