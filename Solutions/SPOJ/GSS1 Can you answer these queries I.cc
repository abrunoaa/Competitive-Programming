/* You are given a sequence A[1], A[2], ..., A[N]. (|A[i]| ≤ 15007, 1 ≤ N ≤ 50000).
 * A query is defined as follows:
 * Query(x,y) = max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }
 */
#include <bits/stdc++.h>
using namespace std;

#define L (k << 1)
#define R (L + 1)
#define M ((l + r) >> 1)
#define maxn 50010
#define inf 0x3f3f3f3f

// ml/mr = max left/right; mt = max total; t = total
struct no{ int ml, mr, mt, t; } segt[4 * maxn];
int n, v[maxn];

no merge(const no &x, const no &y){
  return no{ max(x.ml, x.t + y.ml),
             max(y.mr, y.t + x.mr),
             max(x.mr + y.ml, max(x.mt, y.mt)),
             x.t + y.t };
}

no build(int k = 1, int l = 1, int r = n){
  if(l == r) return segt[k] = no{ v[l],v[l],v[l],v[l] };
  return segt[k] = merge(build(L, l, M), build(R, M+1, r));
}

no qry(int i, int j, int k = 1, int l = 1, int r = n){
  if(l > j or i > r) return no{ -inf,-inf,-inf,0 };
  if(l >= i and j >= r) return segt[k];
  return merge(qry(i, j, L, l, M), qry(i, j, R, M+1, r));
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> v[i];
  build();

  int m, x, y;
  cin >> m;
  while(m--){
    cin >> x >> y;
    cout << qry(x, y).mt << '\n';
  }

  return 0;
}
