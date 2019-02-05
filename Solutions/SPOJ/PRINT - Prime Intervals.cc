#include <bits/stdc++.h>
using namespace std;

#define maxn 66000 // sqrt(maxn)

typedef long long ll;

bitset<maxn> isp;
bitset<1000010> ans;
vector<int> primes;

void sieve(){                           // sieve "trivial"
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

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  sieve();

  int t;
  cin >> t;
  while(t--){
    ll l, u;
    cin >> l >> u;

    // baseado no segmented sieve, ja que u - l <= 1e6
    ans.set();
    for(int p : primes){
      // encontra o primeiro numero > l multiplo de p
      // e ignora todos os multiplos de p entre l e u
      for(ll j = (p >= l ? 2 * p : (l + p - 1) / p * p); j <= u; j += p){
        ans[j - l] = 0;
      }
    }
    for(int i = 0; i <= u - l; ++i){    // percorre os elementos entre l e u
      if(ans[i]){                       // se nao foi deletado, e primo
        cout << l + i << '\n';
      }
    }
  }

  return 0;
}
