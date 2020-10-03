char s[maxn], p[maxn];
int n, m, b[maxn];

void kmp() {        // pré processa o padrão
  b[0] = -1;
  for (int i = 0, j = -1; i < m; b[++i] = ++j)
    while (j >= 0 && p[i] != p[j])
      j = b[j];
}

void match() {
  int i = 0, j = 0;
  while (i < n) {
    while (j >= 0 && s[i] != p[j])
      j = b[j];
    ++i;
    ++j;
    if (j == m) {
      cout << i - j << '\n';
      j = b[j];
    }
  }
}
