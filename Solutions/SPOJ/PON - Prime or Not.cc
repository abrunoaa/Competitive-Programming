#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mul(ll a, ll b, ll m){ return __int128(a) * b % m; }

ll mpow(ll b, ll e, ll m){
  b %= m;
  ll x = 1;
  while(e){
    if(e % 2) x = mul(x, b, m);
    b = mul(b, b, m);
    e /= 2;
  }
  return x;
}

bool millerRabin(ll n, int k){
  for(int p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}){
    if(p * p > n)  return 1;
    if(n % p == 0) return n == p;
  }

  ll m = n - 1;
  while(m % 2 == 0) m /= 2;

  for(int i = 0; i < k; ++i){
    ll x = mpow(2 + rand() % (n - 4), m, n);
    if(x == 1 || x == n - 1)
      continue;
    for(ll d = m; d != n - 1 && x != 1 && x != n - 1; d *= 2)
      x = mul(x, x, n);
    if(x == 1 || x != n - 1)
      return 0;
  }
  return 1;
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    ll n;
    cin >> n;
    cout << (millerRabin(n, 10) ? "YES" : "NO") << '\n';
  }

  return 0;
}
