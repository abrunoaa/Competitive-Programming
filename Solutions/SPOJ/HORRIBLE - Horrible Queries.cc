#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define L (k << 1)
#define R (L + 1)
#define M ((l + r) >> 1)

typedef long long ll;

int n, c;
ll st[4 * maxn], lazy[4 * maxn];

void prop(int k, int qtd){
  ll &l = lazy[k];
  if(l){
    st[k] += l * qtd;
    if(R < 4 * maxn){
      lazy[L] += l;
      lazy[R] += l;
    }
    l = 0;
  }
}

ll upd(int i, int j, int x, int k = 1, int l = 1, int r = n){
  prop(k, r - l + 1);
  if(r < i || j < l) return st[k];
  if(i <= l && r <= j) return st[k] + (r - l + 1) * (lazy[k] = x);
  return st[k] = upd(i, j, x, L, l, M) + upd(i, j, x, R, M+1, r);
}

ll qry(int i, int j, int k = 1, int l = 1, int r = n){
  if(r < i || j < l) return 0ll;
  prop(k, r - l + 1);
  if(i <= l && r <= j) return st[k];
  return qry(i, j, L, l, M) + qry(i, j, R, M+1, r);
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    memset(lazy, 0, sizeof lazy);
    memset(st, 0, sizeof st);

    cin >> n >> c;
    while(c--){
      int op, p, q, v;
      cin >> op >> p >> q;
      if(p > q) swap(p, q);
      if(op == 0){
        cin >> v;
        upd(p, q, v);
      }
      else
        cout << qry(p, q) << '\n';
    }
  }

  return 0;
}
