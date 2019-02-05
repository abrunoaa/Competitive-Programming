#include <bits/stdc++.h>
using namespace std;

#define mod ((int)1e9 + 7)
#define gcd __gcd

typedef long long ll;

int mpow(int b, int e, int m){
  int x = 1;
  while(e){
    if(e % 2) x = (ll)x * b % m;
    e /= 2;
    b = (ll)b * b % m;
  }
  return x;
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);

  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t){
    int n, k;
    cin >> n >> k;

    int ans = 0;
    for(int i = 1; i <= n; ++i){
      ans = (ans + mpow(k, gcd(n, i), mod)) % mod;
    }
    cout << "Case " << t << ": " << (ll)ans * mpow(n, mod - 2, mod) % mod << '\n';
  }

  return 0;
}
