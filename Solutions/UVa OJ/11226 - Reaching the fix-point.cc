#include <bits/stdc++.h>
using namespace std;

#define maxn 500010

typedef long long ll;

bitset<maxn> isp;
vector<int> primes, memo(maxn, -1);

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

int sopf(int n){
  int s = 0;
  for(int p : primes){
    if(p * p > n){
      break;
    }
    while(n % p == 0){
      n /= p;
      s += p;
    }
  }
  if(n > 1){
    s += n;
  }
  return s;
}

int lsopf(int n){
  int &pd = memo[n];
  if(pd != -1){
    return pd;
  }
  int s = sopf(n);
  if(s == n){
    return pd = 1;
  }
  return pd = lsopf(s) + 1;
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  sieve();

  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t){
    int n, m;
    cin >> n >> m;
    if(m < n){
      swap(n, m);
    }

    int ans = 0;
    for(int i = n; i <= m; ++i){
      ans = max(ans, lsopf(i));
    }
    cout << "Case #" << t << ":\n" << ans << '\n';
  }

  return 0;
}
