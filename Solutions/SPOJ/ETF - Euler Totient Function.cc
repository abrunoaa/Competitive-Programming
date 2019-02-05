#include <bits/stdc++.h>
using namespace std;

#define maxn 1000010

typedef long long ll;

bitset<maxn> isp;
vector<int> primes;

void sieve(){
  int n = maxn;
  isp.set();
  isp[0] = isp[1] = 0;
  primes.reserve(2 * int(n / log(n)));

  for(ll i = 2; i < n; ++i){
    if(isp[i]){
      primes.push_back(i);
      for(ll j = i * i; j < n; j += i){
        isp[j] = 0;
      }
    }
  }
}

int totient(int n){
  int ans = n;
  for(int p : primes){
    if(p * p > n){
      break;
    }
    if(n % p == 0){
      ans -= ans / p;
    }
    while(n % p == 0){
      n /= p;
    }
  }
  if(n > 1){
    ans -= ans / n;
  }
  return ans;
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  sieve();

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << totient(n) << '\n';
  }

  return 0;
}
