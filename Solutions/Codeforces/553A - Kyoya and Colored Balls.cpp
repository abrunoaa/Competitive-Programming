#include <bits/stdc++.h>
using namespace std;

#define maxn 1010
#define mod 1000000007

typedef long long ll;

int c[maxn], fat[maxn], finv[maxn];

int mpow(int b, int e, int m){
  int x = 1;
  while(e){
    if(e % 2) x = (ll)x * b % m;
    e /= 2;
    b = (ll)b * b % m;
  }
  return x;
}

void build(){
  fat[0] = finv[0] = 1;
  for(int i = 1; i < maxn; ++i){
    fat[i] = (ll)fat[i - 1] * i % mod;
    finv[i] = (ll)finv[i - 1] * mpow(i, mod - 2, mod) % mod;
  }
}

int C(int n, int k){
  return (ll)fat[n] * finv[k] % mod * finv[n - k] % mod;
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  build();

  int k;
  while(cin >> k){
    for(int i = 0; i < k; ++i){
      cin >> c[i];
    }

    int s = c[0];
    int ans = 1;
    for(int i = 1; i < k; ++i){
      s += c[i];
      ans = (ll)ans * C(s - 1, c[i] - 1) % mod;
    }
    cout << ans << '\n';
  }

  return 0;
}
