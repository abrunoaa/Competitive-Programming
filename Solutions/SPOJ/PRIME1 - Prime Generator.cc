#include <bits/stdc++.h>
using namespace std;

#define maxn 32000 // sqrt(maxn)

bitset<maxn> isp;
vector<int> primes;

void sieve(){
  int n = maxn;
  isp.set();
  isp[0] = isp[1] = 0;
  primes.reserve(2 * int(n / log(n)));
  for(int i = 2; i < n; ++i){
    if(isp[i]){
      primes.push_back(i);
      for(int j = i * i; j < n; j += i){
        isp[j] = 0;
      }
    }
  }
}

bool isprime(int n){
  if(n < maxn){
    return isp[n];
  }
  for(int p : primes){
    if(p * p > n){
      break;
    }
    if(n % p == 0){
      return 0;
    }
  }
  return 1;
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  sieve();

  int t;
  cin >> t;
  while(t--){
    int l, u;
    cin >> l >> u;
    for(int i = l; i <= u; ++i){
      if(isprime(i)){
        cout << i << '\n';
      }
    }
    if(t){
      cout << '\n';
    }
  }

  return 0;
}
