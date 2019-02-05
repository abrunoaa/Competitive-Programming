#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll nbits(ll n, int i){
  if(i == 0) return (n + 1) / 2;
  ll x = ((n >> i) << i) & ~(1ll << i);
  return x / 2 + max(0ll, n - x + 1 - (1ll << i));
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  ll a, b;
  while(cin >> a >> b){
    ll ans = 0;
    for(int i = 0; i < 63; ++i){
      ans += nbits(b, i) - nbits(a - 1, i);
    }
    cout << ans << '\n';
  }

  return 0;
}

