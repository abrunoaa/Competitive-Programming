#include <bits/stdc++.h>
using namespace std;

#define pi acos(-1)
#define maxn (1 << 15)

typedef long double lf;
typedef long long ll;

struct cp{
  lf a, b;

  cp(lf a = 0.0, lf b = 0.0) : a(a), b(b) {}

  cp operator + (cp& x){ return {a + x.a, b + x.b}; }
  cp operator - (cp& x){ return {a - x.a, b - x.b}; }
  cp operator * (cp& x){ return {a * x.a - b * x.b, a * x.b + b * x.a}; }
  cp operator / (lf d){ return {a / d, b / d}; }
};

void fft(cp* a, int n, int s){
  for(int i = 0, j = 0; i < n; ++i){
    if(i > j) swap(a[i], a[j]);
    for(int k = n / 2; (j ^= k) < k; k >>= 1);
  }

  for(int i = 1; (1 << i) <= n; ++i){
    int p = 1 << i;
    int q = p >> 1;

    cp wn = cp(cos(2 * s * pi / p), sin(2 * s * pi / p));
    for(int j = 0; j < n; j += p){
      cp w = cp(1, 0);
      for(int k = j; k < q + j; ++k){
        cp t = w * a[k + q];
        a[k + q] = a[k] - t;
        a[k] = a[k] + t;
        w = wn * w;
      }
    }
  }
}

void multiply(cp* a, cp* b, int n){
  assert((n & (n - 1)) == 0);
  fft(a, n, 1);
  fft(b, n, 1);
  for(int i = 0; i < n; i++) a[i] = a[i] * b[i];
  fft(a, n, -1);
  for(int i = 0; i < n; i++) a[i] = a[i] / n;
}

cp x[maxn], y[maxn];

int main(){
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    for(int i = n, t; i >= 0; --i){
      cin >> t;
      x[i] = { (lf)t, 0 };
    }
    for(int i = n, t; i >= 0; --i){
      cin >> t;
      y[i] = { (lf)t, 0 };
    }

    int power = 2 * (n + 1);
    while(power & (power - 1)){
      power += power & -power;
    }

    for(int i = n + 1; i < power; ++i){
      x[i] = y[i] = {0,0};
    }

    multiply(x, y, power);

    for(int i = 2 * n; i >= 0; --i){
      cout << (ll)(x[i].a + .5);
      if(i){
        cout << ' ';
      }
    }
    cout << '\n';
  }

  return 0;
}
