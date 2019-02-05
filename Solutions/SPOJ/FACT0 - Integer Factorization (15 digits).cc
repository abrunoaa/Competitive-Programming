#include <bits/stdc++.h>
using namespace std;

#define gcd __gcd

typedef long long ll;
typedef map<ll,int> mii;

ll mul(ll a, ll b, ll m){
  ll x = 0, y = a % m;
  while(b){
    if(b % 2) x = (x + y) % m;
    y = 2 * y % m;
    b /= 2;
  }
  return x;
}

ll pow(ll b, ll e, ll m){
  b %= m;
  ll x = 1;
  while(e){
    if(e % 2) x = mul(x, b, m);
    b = mul(b, b, m);
    e /= 2;
  }
  return x;
}

ll rho(ll n){
  int c = 1;
again:
  ll x = 2, y = 2, i = 0, k = 2;
  while(1){
    x = (mul(x, x, n) + c) % n;
    ll g = gcd(n, llabs(x - y));
    if(g == n){
      ++c;
      goto again;
    }
    if(g > 1) return g;
    if(++i == k) y = x, k *= 2;
  }
}

bool miller(ll n, int k){
  if(n % 2 == 0){
    return n == 2;
  }
  for(int p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}){
    if(p * p > n){
      return 1;
    }
    if(n % p == 0){
      return n == p;
    }
  }

  ll s = n - 1;
  while(s % 2 == 0){
    s /= 2;
  }

  for(int i = 0; i < k; ++i){
    ll x = pow(2 + rand() % (n - 4), s, n);
    if(x == 1 || x == n - 1){
      continue;
    }

    for(ll d = s; d != n - 1 && x != 1 && x != n - 1; d *= 2){
      x = mul(x, x, n);
    }
    if(x == 1 || x != n - 1){
      return 0;
    }
  }

  return 1;
}

mii merge(mii a, const mii& b){
  for(auto x : b){
    a[x.first] += x.second;
  }
  return a;
}

mii fatora(ll n){
  if(miller(n, 10)){
    mii t;
    t[n] = 1;
    return t;
  }
  ll x = rho(n);
  return merge(fatora(x), fatora(n / x));
}

int main(){
  srand(1998);

  ll n;
  while(cin >> n && n){
    mii ans = fatora(n);

    bool flag = 0;
    for(auto x : ans){
      if(flag){
        cout << ' ';
      }
      else{
        flag = 1;
      }
      cout << x.first << '^' << x.second;
    }
    cout << '\n';
  }

  return 0;
}
