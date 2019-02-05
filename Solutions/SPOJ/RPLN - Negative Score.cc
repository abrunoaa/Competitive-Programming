#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define L (k << 1)
#define R (L + 1)
#define M ((l + r) >> 1)

int n, q, v[maxn], st[4 * maxn];

int build(int k = 1, int l = 1, int r = n){
  if(l == r) return st[k] = v[l];
  return st[k] = min(build(L, l, M), build(R, M+1, r));
}

int qry(int i, int j, int k = 1, int l = 1, int r = n){
  if(r < i || j < l) return 1e9;
  if(i <= l && r <= j) return st[k];
  return min(qry(i, j, L, l, M), qry(i, j, R, M+1, r));
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  for(int sc = 1; sc <= t; ++sc){
    cout << "Scenario #" << sc << ":\n";
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> v[i];
    build();
    while(q--){
      int a, b;
      cin >> a >> b;
      cout << qry(a, b) << '\n';
    }
  }

  return 0;
}
