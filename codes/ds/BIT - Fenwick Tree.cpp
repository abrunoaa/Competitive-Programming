const int maxn = (int)1e5 + 3;
int ft[maxn];

void upd(int i, int x) { for (; i < maxn; i += i & -i) ft[i] += x; }

int qry(int i) {
  int s = 0;
  for (; i; i -= i & -i) s += ft[i];
  return s;
}
