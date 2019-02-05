#include <bits/stdc++.h>
using namespace std;

#define clz __builtin_clzll
#define lg(x) (63 - clz(x))
#define maxn (2 << lg(1000000))

typedef long long ll;

int t, n, p, q, a[maxn], b[(int)2e7 / 64 + 10];
int st[lg(maxn)][maxn];

void build(){
  for(int i = 0; (1 << i) <= n; ++i){
    int *v = st[i];
    for(int s = 1; (s << i) <= n; s += 2){
      int k = s << i;
      v[k] = a[k] % p;
      v[k - 1] = a[k - 1] % p;
      for(int j = 1; j < (1 << i); ++j){
        v[k + j] = (ll)a[k + j] * v[k + j - 1] % p;
        v[k - j - 1] = (ll)a[k - j - 1] * v[k - j] % p;
      }
    }
  }
}

int qry(int i, int j){
  if(i == j) return a[i] % p;
  int k = 63 - clz(i ^ j);
  return (ll)st[k][i] * st[k][j] % p;
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n >> p >> q;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < q / 64 + 2; ++i) cin >> b[i];
    build();
    int x = 0;
    for(int i = 0, l, r; i < q; ++i){
      if(i % 64 == 0){
        l = (b[i / 64] + x) % n;
        r = (b[i / 64 + 1] + x) % n;
      }
      else{
        l = (l + x) % n;
        r = (r + x) % n;
      }
      if(l > r) swap(l, r);
      x = (qry(l, r) + 1) % p;
    }
    cout << x << '\n';
  }
  return 0;
}
