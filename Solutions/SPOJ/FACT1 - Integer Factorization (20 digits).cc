#include <bits/stdc++.h>
using namespace std;

#define gcd __gcd

typedef long long ll;
typedef __int128 big;
typedef map<big,int> mii;

big mul(big a, big b, big m){
  big x = 0, y = a % m;
  while(b){
    if(b % 2) x = (x + y) % m;
    y = 2 * y % m;
    b /= 2;
  }
  return x;
}

big pow(big b, big e, big m){
  b %= m;
  big x = 1;
  while(e){
    if(e % 2) x = mul(x, b, m);
    b = mul(b, b, m);
    e /= 2;
  }
  return x;
}

#define abs(x) ((x) < 0 ? -(x) : (x))

big rho(big n){
  int c = 1;
again:
  int i = 0, k = 2;
  big x = 2, y = 2;
  while(1){
    x = (mul(x, x, n) + c) % n;
    big g = gcd(n, abs(x - y));
    if(g == n){
      ++c;
      goto again;
    }
    if(g > 1) return g;
    if(++i == k) y = x, k *= 2;
  }
}

bool miller(big n, int k){
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

  big s = n - 1;
  while(s % 2 == 0){
    s /= 2;
  }

  for(int i = 0; i < k; ++i){
    big x = pow(2 + rand() % (n - 4), s, n);
    if(x == 1 || x == n - 1){
      continue;
    }

    for(big d = s; d != n - 1 && x != 1 && x != n - 1; d *= 2){
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

mii fatora(big n){
  if(miller(n, 10)){
    mii t;
    t[n] = 1;
    return t;
  }
  big x = rho(n);
  return merge(fatora(x), fatora(n / x));
}

istream& operator >> (istream& in, big& x){
  string s;
  if(cin >> s){
    x = 0;
    for(char c : s) x = x * 10 + c - '0';
  }
  return in;
}

ostream& operator << (ostream& out, big x){
  string s;
  if(!x)
    s = "0";
  else{
    while(x){
      s.push_back(x % 10 + '0');
      x /= 10;
    }
    reverse(s.begin(), s.end());
  }
  return out << s;
}

int main(){
  // freopen("in","r",stdin);
  srand(1998);

  big n;
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
