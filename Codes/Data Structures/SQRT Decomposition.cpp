const int maxn = 100003;

int v[maxn];

int brute(int l, int r) {
  // calcula resposta com força bruta entre l e r
}

int get(int bl, int br) {
  // calcula apenas a resposta dos blocos de bl até br
}

int main() {
  int n, q;
  cin >> n >> q;
  const int bs = sqrt(n);
  for (int i = 0; i * bs < n; ++i) {
    int m = min(n, (i + 1) * bs);
    for (int j = i * bs; j < m; ++j) cin >> v[j];
    // calcula resposta do bloco i
  }
  while (q--) {
    int l, r;
    cin >> l >> r, --l, --r;

    int bl = l / bs, br = r / bs;       // bloco de l e de r
    int ans = 0;
    if (bl == br) {
      ans = brute(l, r);
    } else {
      ans = get(bl + 1, br - 1);
      ans += brute(l, (bl + 1) * bs - 1);
      ans += brute((br - 1) * bs, r);
    }
  }
  return 0;
}
