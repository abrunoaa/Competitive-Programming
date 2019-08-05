#define clz __builtin_clz

typedef double lf;

struct cpx {
  lf real, imag;
  cpx(lf a = 0, lf b = 0) : real(a), imag(b) {}
  cpx operator + (cpx a) const { return cpx(real + a.real, imag + a.imag); }
  cpx operator - (cpx a) const { return cpx(real - a.real, imag - a.imag); }
  cpx operator * (cpx a) const {
    return cpx(real * a.real - imag * a.imag,
               real * a.imag + imag * a.real);
  }
  cpx operator / (lf k) { return cpx(real / k, imag / k); }
};

void fft(cpx* a, int n, int s) {
  for (int i = 0, j = 0; i < n; ++i) {
    if (i > j) { swap(a[i], a[j]); }
    for (int k = n / 2; (j ^= k) < k; k >>= 1);
  }
  for (int i = 1; (1 << i) <= n; ++i) {
    int p = 1 << i;
    int q = p >> 1;
    lf ang = s * 2 * acos(-1) / p;
    cpx wn(cos(ang), sin(ang));
    for (int j = 0; j < n; j += p) {
      cpx w = 1;
      for (int k = j; k < q + j; ++k) {
        cpx t = w * a[k + q];
        a[k + q] = a[k] - t;
        a[k] = a[k] + t;
        w = wn * w;
      }
    }
  }
}

void conv(cpx* a, int n, cpx* b, int m, cpx* c) {
  int k = 2 << (32 - clz(max(n, m) - 1));
  fft(a, k, 1);
  fft(b, k, 1);
  for (int i = 0; i < k; ++i) { c[i] = a[i] * b[i]; }
  fft(c, k, -1);
  for (int i = 0; i < k; ++i) { c[i] = c[i] / k; }
}

void circularConv(cpx* a, int n, cpx* b, int m, cpx* c) {
  memcpy(b + m, b, m * sizeof(cpx));
  conv(a, n, b, 2 * m, c);
  memcpy(c, c + n, n * sizeof(cpx));
}
