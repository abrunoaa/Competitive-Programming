#include <bits/stdc++.h>
using namespace std;

// x^k = x^(k mod (m - 1)) (mod m)

#define maxn 100010
#define mod 95542721
#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)

typedef long long ll;

struct no{
  int lazy, p[48];
};

int n, v[maxn];
no st[4 * maxn];

void merge(no& dest, const no& x, const no& y){
  dest.lazy = 0;
  // int lzx = x.lazy;
  // int lzy = y.lazy;
  for(int i = 0; i < 48; ++i){
    // dest.p[i] = (x.p[(i + lzx) % 48] + y.p[(i + lzy) % 48]) % mod;
    dest.p[i] = (x.p[i] + y.p[i]) % mod;
  }
}

no& build(int k = 1, int l = 1, int r = n){
  if(l == r){
    st[k].lazy = 0;
    int x = v[l];
    for(int i = 0; i < 48; ++i){
      st[k].p[i] = x;
      x = (ll)x * x % mod * x % mod;
    }
  }
  else{
    merge(st[k], build(L, l, M), build(R, M+1, r));
  }
  return st[k];
}

void prop(int k, bool child){
  int &l = st[k].lazy;
  if(l){
    if(child){
      st[L].lazy = (st[L].lazy + l) % 48;
      st[R].lazy = (st[R].lazy + l) % 48;
    }
    rotate(st[k].p, st[k].p + l, st[k].p + 48);
    l = 0;
  }
}

no& upd(int i, int j, int k = 1, int l = 1, int r = n){
  if(i <= l && r <= j){
    st[k].lazy = (st[k].lazy + 1) % 48;
    prop(k, l < r);
    return st[k];
  }
  prop(k, l < r);
  if(r < i || j < l) return st[k];
  merge(st[k], upd(i, j, L, l, M), upd(i, j, R, M+1, r));
  return st[k];
}

int qry(int i, int j, int k = 1, int l = 1, int r = n){
  if(r < i || j < l) return 0;
  prop(k, l < r);
  if(i <= l && r <= j) return st[k].p[0];
  return (qry(i, j, L, l, M) + qry(i, j, R, M+1, r)) % mod;
}

int main(){
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> v[i];
  }
  build();

  int q;
  cin >> q;
  while(q--){
    int t, l, r;
    cin >> t >> l >> r;
    if(t == 1){
      cout << qry(l, r) << '\n';
    }
    else{
      upd(l, r);
    }
  }

  return 0;
}