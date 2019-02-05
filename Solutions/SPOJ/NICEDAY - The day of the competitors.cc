#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define st first
#define nd second
#define inf 0x3f3f3f3f

typedef pair<int,int> ii;
typedef pair<ii,int> tri;

int n, bit[maxn];
tri v[maxn];

void upd(int i, int x){
  for(; i <= n; i += i & -i) bit[i] = min(bit[i], x);
}

int qry(int i){
  int x = inf;
  for(; i; i -= i & -i) x = min(x, bit[i]);
  return x;
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    memset(bit, inf, sizeof bit);

    cin >> n;
    for(int i = 0, a, b, c; i < n; ++i){
      cin >> a >> b >> c;
      v[i] = tri(ii(a, b), c);
    }

    sort(v, v + n, [](const tri& x, const tri& y){ return x.st.st < y.st.st; });

    int ans = 0;
    for(int i = 0; i < n; ++i){
      if(v[i].nd < qry(v[i].st.nd)) ++ans;
      upd(v[i].st.nd, v[i].nd);
    }

    cout << ans << '\n';
  }

  return 0;
}
