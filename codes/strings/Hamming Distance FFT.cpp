const int maxf = 2 << (32 - clz(4*maxn - 1)); // clz(max(2 * t.size(), 4 * p.size()))
const int ALFA = 26;                          // tamanho do alfabeto

char t[maxn], p[maxn];
int match[maxn];
cpx x[ALFA][maxf], y[ALFA][maxf];

int reduce(char c) { return c - 'a'; }  // letra -> inteiro

void matchfft(int* match, const char* t, int n, const char* p, int m) {
  assert(n >= m);
  memset(match, 0, n * sizeof(int));
  memset(x, 0, sizeof x);
  memset(y, 0, sizeof y);
  for (int i = 0; i < n; ++i) x[reduce(t[i])][i] = 1;
  for (int i = 0; i < m; ++i) y[reduce(p[i])][2 * n - i - 1] = 1;
  for (int c = 0; c < ALFA; ++c) {
    circularconv(x[c], 2 * n, y[c], 2 * n, x[c]);
    match[0] += int(x[c][2 * n - 1].real + .5);
    for (int i = 0; i < n - 1; ++i)
      match[i + 1] += int(x[c][i].real + .5);
  }
}
