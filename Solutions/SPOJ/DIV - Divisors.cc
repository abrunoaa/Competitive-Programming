#include <bits/stdc++.h>
using namespace std;

#define maxn 1000010

typedef long long ll;

int d[maxn];
vector<int> primes;

void sieve(){
  int n = maxn;
  primes.reserve(2 * int(n / log(n)));
  for(int i = 1; i < n; ++i){
    d[i] = 1;
  }
  for(ll i = 2; i < n; ++i){
    if(d[i] == 1){
      primes.push_back(i);
      ++d[i];
      for(ll j = 2 * i; j < n; j += i){
        int e = 0;
        for(ll k = j; k % i == 0; k /= i){
          ++e;
        }
        d[j] *= e + 1;
      }
    }
  }
}

bool isans(int n){
  for(int p : primes){
    if(p * p >= n){
      break;
    }
    if(n % p == 0){
      return d[n / p] == 2;
    }
  }
  return 0;
}

void solve(){
  for(int i = 2, k = 0; i <= maxn; ++i){
    if(isans(d[i])){
      if(++k == 9){
        cout << i << '\n';
        k = 0;
      }
      // else cout << " >> " << i << '\n';
    }
  }
}

int main(){
  // freopen("out","w",stdout);
  sieve();
  solve();

  return 0;
}
