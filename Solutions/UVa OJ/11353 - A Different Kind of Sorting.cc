#include <bits/stdc++.h>
using namespace std;

#define maxn 2000010

typedef long long ll;

int v[maxn];
vector<int> pfac(maxn, 0);

void sieve(){
  int n = maxn;
  for(ll i = 2; i < n; ++i){
    if(pfac[i] == 0){
      pfac[i] = 1;
      for(ll j = 2 * i; j < n; j += i){
        for(ll k = j; k % i == 0; k /= i){
          ++pfac[j];
        }
      }
    }
  }
}

void sort(){
  int n = 2000000;
  for(int i = 0; i <= n; ++i){
    v[i] = i;
  }
  sort(v, v + n + 1, [](int x, int y){
    return (pfac[x] != pfac[y] ? pfac[x] < pfac[y] : x < y);
  });
  assert(v[0] == 0);
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  sieve();
  sort();

  int n, cs = 0;
  while(cin >> n && n){
    cout << "Case " << ++cs << ": " << v[n] << '\n';
  }

  return 0;
}
