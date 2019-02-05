#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define L (k << 1)
#define R (L + 1)
#define M ((l + r) >> 1)

struct no { int r0, r1, r2, lazy; } st[4 * maxn];
int n, q;

no merge(const no& x, const no& y){
  return no{ x.r0 + y.r0, x.r1 + y.r1, x.r2 + y.r2, 0 };
}

no build(int k = 1, int l = 0, int r = n - 1){
  if(l == r) return st[k] = no{ 1,0,0,0 };
  return st[k] = merge(build(L, l, M), build(R, M+1, r));
}

void change(no& x){
  swap(x.r0, x.r1);
  swap(x.r0, x.r2);
}

void prop(int k){
  int &l = st[k].lazy;
  if(l %= 3){
    if(R < 4 * maxn){
      st[L].lazy += l;
      st[R].lazy += l;
      for(int i = 0; i < l; ++i){
        change(st[L]);
        change(st[R]);
      }
    }
    l = 0;
  }
}

no upd(int i, int j, int k = 1, int l = 0, int r = n - 1){
  if(r < i || j < l) return st[k];
  prop(k);
  if(i <= l && r <= j){
    change(st[k]);
    st[k].lazy = 1;
    return st[k];
  }
  return st[k] = merge(upd(i, j, L, l, M), upd(i, j, R, M+1, r));
}

int qry(int i, int j, int k = 1, int l = 0, int r = n - 1){
  if(r < i || j < l) return 0;
  prop(k);
  if(i <= l && r <= j) return st[k].r0;
  return qry(i, j, L, l, M) + qry(i, j, R, M+1, r);
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  build();
  while(q--){
    int op, a, b;
    cin >> op >> a >> b;
    if(op == 0)
      upd(a, b);
    else
      cout << qry(a, b) << '\n';
  }
  return 0;
}
