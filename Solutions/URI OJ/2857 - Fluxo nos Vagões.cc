#include <bits/stdc++.h>
using namespace std;

#define maxn 100010

typedef long long ll;

ll ft[maxn];

void upd(int i, int x){
  for(; i < maxn; i += i & -i){
    ft[i] += x;
  }
}

ll qry(int i){
  ll s = 0;
  for(; i; i -= i & -i){
    s += ft[i];
  }
  return s;
}

int main(){
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  while(m--){
    int t;
    cin >> t;
    if(t == 1){
      int x, y;
      cin >> x >> y;
      upd(x, y);
    }
    else{
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      if(c < a){
        swap(a, c);
        swap(b, d);
      }
      if(d <= b){
        cout << qry(b) - qry(a - 1) << '\n';
      }
      else if(c <= b){
        cout << qry(d) - qry(a - 1) << '\n';
      }
      else{
        cout << qry(b) - qry(a - 1) + qry(d) - qry(c - 1) << '\n';
      }
    }
  }

  return 0;
}
