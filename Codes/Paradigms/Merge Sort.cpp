int v[maxn], tmp[maxn];

void merge(int l, int m, int r) {
  int k = 0;
  for (int i = l; i <= m; ++k, ++i) tmp[k] = v[i];
  for (int i = r; i >  m; ++k, --i) tmp[k] = v[i];
  for (int i = 0, j = k - 1; l <= r; ++l)
    v[l] = tmp[i] < tmp[j] ? tmp[i++] : tmp[j--];
}

void mergeSort(int l, int r) {
  if (l >= r) return;
  int m = (l + r) / 2;
  mergeSort(l, m);
  mergeSort(m + 1, r);
  merge(l, m, r);
}
