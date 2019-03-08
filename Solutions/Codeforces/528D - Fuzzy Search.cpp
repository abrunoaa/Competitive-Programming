#include <bits/stdc++.h>
using namespace std;

#define pi acos(-1)
#define maxn 200010
#define maxf (1 << (32 - __builtin_clz(4 * maxn)))  // clz(max(t.size(), p.size()))
#define ALFA 4

typedef double lf;

struct cpx {
  lf real, imag;
  cpx(lf a = 0, lf b = 0) : real(a), imag(b) {}
  cpx operator + (cpx a) const{ return cpx(real + a.real, imag + a.imag); }
  cpx operator - (cpx a) const{ return cpx(real - a.real, imag - a.imag); }
  cpx operator * (cpx a) const{ return cpx(real * a.real - imag * a.imag, real * a.imag + imag * a.real); }
  cpx operator / (lf k){ return cpx(real / k, imag / k); }
};

char t[maxn], p[maxn];
int match[maxn];
int sum[ALFA + 2][maxn];
cpx x[ALFA + 2][maxf], y[ALFA + 2][maxf];

void fft(cpx* a, int n, int s){
  for(int i = 0, j = 0; i < n; ++i){
    if(i > j) swap(a[i], a[j]);
    for(int k = n / 2; (j ^= k) < k; k >>= 1);
  }

  for(int i = 1; (1 << i) <= n; ++i){
    int p = 1 << i;
    int q = p >> 1;

    lf ang = 2 * s * pi / p;
    cpx wn = cpx(cos(ang), sin(ang));
    for(int j = 0; j < n; j += p){
      cpx w = 1;
      for(int k = j; k < q + j; ++k){
        cpx t = w * a[k + q];
        a[k + q] = a[k] - t;
        a[k] = a[k] + t;
        w = wn * w;
      }
    }
  }
}

void convolution(cpx* a, int n, cpx* b, int m, cpx* c){
  int k = 1 << (32 - __builtin_clz(max(n, m)));
  fft(a, k, 1);
  fft(b, k, 1);
  for(int i = 0; i < k; ++i) c[i] = a[i] * b[i];
  fft(c, k, -1);
  for(int i = 0; i < k; ++i) c[i] = c[i] / k;
}

void circularconvolution(cpx* a, int n, cpx* b, int m, cpx* c){
  memcpy(b + m, b, m * sizeof(cpx));
  convolution(a, n, b, 2 * m, c);
  memcpy(c, c + n, n * sizeof(cpx));
}

int reduce(char c){
  return c == 'A' ? 0 : c == 'C' ? 1 : c == 'G' ? 2 : 3;
}

void matchfft(const char *t, int n, const char *p, int m, int k){
  memset(match, 0, n * sizeof(int));
  if(m > n) return;

  for(int i = 0; i < n; ++i){
    sum[reduce(t[i])][max(0, i - k)] += 1;
    sum[reduce(t[i])][min(n, i + k + 1)] -= 1;
  }
  for(int c = 0; c < ALFA; ++c)
    for(int i = 0; i < n; ++i){
      sum[c][i] += !i ? 0 : sum[c][i - 1];
      x[c][i] = sum[c][i] < 1 ? 0 : 1;
    }
  for(int i = 0; i < m; ++i) y[reduce(p[i])][2 * n - i - 1] = 1;
  for(int c = 0; c < ALFA; ++c){
    circularconvolution(x[c], 2 * n, y[c], 2 * n, x[c]);
    match[0] += int(x[c][2 * n - 1].real + .5);
    for(int i = 0; i < n - 1; ++i)
      match[i + 1] += int(x[c][i].real + .5);
  }
}

int main(){
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  // cerr << maxf << endl;

  int n, m, k;
  cin >> n >> m >> k >> t >> p;

  matchfft(t, n, p, m, k);
  int ans = 0;
  for(int i = 0; i < n; ++i){
    if(match[i] == m){
      ++ans;
    }
    // cerr << match[i] << ' ';
  }
  // cerr << endl;
  cout << ans << '\n';

  return 0;
}
