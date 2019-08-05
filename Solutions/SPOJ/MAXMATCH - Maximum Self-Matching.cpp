#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define maxfft (1 << (32 - __builtin_clz(6 * maxn)))
#define pi acos(-1)
#define ALFA 3

typedef double lf;

struct cpx {
  lf a, b;

  cpx(lf a = 0.0, lf b = 0.0) : a(a), b(b) {}

  cpx operator + (cpx &x) { return {a + x.a, b + x.b}; }
  cpx operator - (cpx &x) { return {a - x.a, b - x.b}; }
  cpx operator * (cpx &x) { return {a* x.a - b * x.b, a* x.b + b * x.a}; }
  cpx operator / (lf d) { return {a / d, b / d}; }
};

int match[maxn];
char s[2 * maxn], p[2 * maxn];
cpx x[ALFA + 2][maxfft], y[ALFA + 2][maxfft];

void fft(cpx* a, int n, int s) {
  for (int i = 0, j = 0; i < n; ++i) {
    if (i > j) { swap(a[i], a[j]); }
    for (int k = n / 2; (j ^= k) < k; k >>= 1);
  }

  for (int i = 1; (1 << i) <= n; ++i) {
    int p = 1 << i;
    int q = p >> 1;

    cpx wn = cpx(cos(2 * s * pi / p), sin(2 * s * pi / p));
    for (int j = 0; j < n; j += p) {
      cpx w = cpx(1, 0);
      for (int k = j; k < q + j; ++k) {
        cpx t = w * a[k + q];
        a[k + q] = a[k] - t;
        a[k] = a[k] + t;
        w = wn * w;
      }
    }
  }
}

void convolution(cpx* a, int n, cpx* b, int m) {
  int k = 1 << (32 - __builtin_clz(n + m - 1));
  for (int i = n; i < k; ++i) { a[i] = 0; }
  for (int i = m; i < k; ++i) { b[i] = 0; }
  fft(a, k, 1);
  fft(b, k, 1);
  for (int i = 0; i < k; ++i) { a[i] = a[i] * b[i]; }
  fft(a, k, -1);
  for (int i = 0; i < k; ++i) { a[i] = a[i] / k; }
}

void circularConvolution(cpx* a, int n, cpx* b, int m) {
  memcpy(b + m, b, m * sizeof(cpx));
  convolution(a, n, b, 2 * m);
  memmove(a, a + n, n * sizeof(cpx));
}

int reduce(char c) {
  if (c >= 'a' && c <= 'z') { return c - 'a'; }
  if (c >= 'A' && c <= 'Z') { return c - 'A' + 'z'; }
  return -1;      // retornar outros valores para outros caracteres (não esquecer de flags)
}

/*
 * retorna qtd de caracteres em comum entre s[k,k+m-1] e p[0,m-1]
 * >> deve limpar match, x e y
 * >> deve adicionar n caracteres (fora dos usados) em s e m caracteres em p
 * ex.: s = aba -> s = abaccc, p = ba -> p = badd
 */
void inaccurateMatching(const char* s, int n, const char* p, int m) {
  if (m > n) { return; }

  for (int i = 0; i < n; ++i) { x[reduce(s[i])][i] = 1; }
  for (int i = 0; i < m; ++i) { y[reduce(p[i])][m - i - 1] = 1; }
  for (int c = 0; c < ALFA; ++c) { circularConvolution(x[c], n, y[c], m); }

  // match[0] = int(x[c][n - 1].a + 0.5)
  for (int i = 0; i < n / 2 - 1; ++i)
    for (int c = 0; c < ALFA; ++c) {
      match[i + 1] += int(x[c][i].a + 0.5);
    }
}

/*
 * SPOJ: MAXMATCH - Maximum Self-Matching - https://www.spoj.com/problems/MAXMATCH/
 * >> Qual o max matching de s (incluindo todos os caracteres) com s shiftado k > 0 vezes?
 * Ex.: caccacaa    (string original)
 *         caccacaa (3 shifts)
 *         ^^^ ^
 */
int main() {
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> s;
  strcpy(p, s);
  int n = strlen(s);
  memset(s + n, 'd', n);  // copia flag n vezes para o final da string
  memset(p + n, 'e', n);
  s[2 * n] = p[2 * n] = 0;

  inaccurateMatching(p, 2 * n, s, 2 * n);

  int ans = 0;
  for (int i = 1; i < n; ++i) { ans = max(ans, match[i]); }

  cout << ans << '\n';
  for (int i = 1; i < n; ++i)
    if (ans == match[i]) {
      cout << i << ' ';
    }
  cout << '\n';
  return 0;
}
