#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define L (k << 1)
#define R (L + 1)
#define M ((l + r) >> 1)

typedef long long ll;

struct no{ ll h, n; } st[4 * maxn];

ll n, m, p, b;
int b_to[maxn];

no merge(const no& x, const no& y){
  return no{ (int)((x.h * b_to[y.n] + y.h) % p), x.n + y.n };
}

no build(int k = 1, int l = 1, int r = n){
  if(l == r) return st[k] = { 0,1 };
  return st[k] = { 0, build(L, l, M).n + build(R, M+1, r).n };
}

void construct(){
  b_to[0] = 1;
  for(int i = 1; i <= n; ++i) b_to[i] = b * b_to[i - 1] % p;
  build();
}

no upd(int i, int v, int k = 1, int l = 1, int r = n){
  if(l == r && l == i) return st[k] = no{ v,1 };
  if(i > M) return st[k] = merge(st[L], upd(i, v, R, M+1, r));
  return st[k] = merge(upd(i, v, L, l, M), st[R]);
}

no qry(int i, int j, int k = 1, int l = 1, int r = n){
  if(r < i || j < l) return no{ 0,0 };
  if(i <= l && r <= j) return st[k];
  return merge(qry(i, j, L, l, M), qry(i, j, R, M+1, r));
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  while(cin >> b >> p >> n >> m && (b || p || n || m)){
    construct();
    while(m--){
      char op;
      int i, j;
      cin >> op >> i >> j;
      if(op == 'E'){
        upd(i, j);
      }
      else{
        cout << qry(i, j).h << '\n';
      }
    }
    cout << "-\n";
  }

  return 0;
}
