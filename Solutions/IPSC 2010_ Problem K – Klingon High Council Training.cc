#include <bits/stdc++.h>
using namespace std;

#define maxn 125

typedef long long ll;

ll pile[maxn];

ll nimValue(ll d){
  ll not3 = 0; // numbers which can't be sum of three squares <= d
  for(ll p = 1; p <= d; p *= 4){
    not3 += (d / p - 7) / 8 + (7 * p <= d);
  }
  return d - not3;
}

int main(){
  freopen("k2.in","r",stdin);
  freopen("out","w",stdout);
  ios::sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
      ll x, y, z;
      cin >> x >> y >> z;
      pile[i] = nimValue(x*x + y*y + z*z);
    }

    bool win = 0;
    for(int bit = 0; bit < 64; ++bit){
      int sum = 0;
      for(int i = 0; i < n; ++i){
        sum += ((1ll << bit) & pile[i]) != 0;
      }
      if(sum % (k + 1)){
        win = 1;
        break;
      }
    }

    cout << "Player " << 1 + !win << '\n';
  }

  return 0;
}
