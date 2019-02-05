#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define L (k << 1)
#define R (L + 1)
#define M ((l + r) >> 1)

int n, m;
struct no{ int h, e, r, lazy; } st[4 * maxn];

no merge(const no& x, const no& y){ return no{ x.h + y.h, x.e + y.e, x.r + y.r, 0 }; }

no build(int k = 1, int l = 1, int r = n){
  if(l == r) return st[k] = { 1,0,0,0 };
  return st[k] = merge(build(L, l, M), build(R, M+1, r));
}

void change(no& x){
  swap(x.h, x.e);
  swap(x.h, x.r);
  ++x.lazy;
}

void prop(int k){
  int &l = st[k].lazy;
  if(l %= 3){
    if(R < 4 * maxn)
      for(int i = 0; i < l; ++i){
        change(st[L]);
        change(st[R]);
      }
    l = 0;
  }
}

no upd(int i, int j, int k = 1, int l = 1, int r = n){
  prop(k);
  if(r < i || j < l) return st[k];
  if(i <= l && r <= j){
    change(st[k]);
    return st[k];
  }
  return st[k] = merge(upd(i, j, L, l, M), upd(i, j, R, M+1, r));
}

no qry(int i, int j, int k = 1, int l = 1, int r = n){
  if(r < i || j < l) return no{ 0,0,0,0 };
  prop(k);
  if(i <= l && r <= j) return st[k];
  return merge(qry(i, j, L, l, M), qry(i, j, R, M+1, r));
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  while(cin >> n >> m){
    build();
    while(m--){
      char op;
      int a, b;
      cin >> op >> a >> b;
      if(op == 'M')
        upd(a, b);
      else{
        no t = qry(a, b);
        cout << t.h << ' ' << t.e << ' ' << t.r << '\n';
      }
    }
    cout << '\n';
  }
  return 0;
}
