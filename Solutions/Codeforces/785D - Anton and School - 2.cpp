#include <bits/stdc++.h>
using namespace std;

#define maxn 200010
#define mod 1000000007

typedef long long ll;

int n, open[maxn], close[maxn], fat[maxn], finv[maxn];
string s;

int mpow(int b, int e, int m){
  int x = 1;
  while(e){
    if(e % 2) x = (ll)x * b % m;
    b = (ll)b * b % m;
    e /= 2;
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
  build();
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> s;
  n = s.size();

  open[0] = (s[0] == '(');
  for(int i = 1; i < n; ++i){
    open[i] = open[i - 1] + (s[i] == '(');
  }
  for(int i = n - 1; i >= 0; --i){
    close[i] = close[i + 1] + (s[i] == ')');
  }

  int ans = 0;
  for(int i = 0; i < n && close[i] > 0; ++i){
    if(s[i] == '('){
      ans = (ans + C(open[i] + close[i] - 1, open[i])) % mod;
    }
  }
  cout << ans << '\n';

  return 0;
}
