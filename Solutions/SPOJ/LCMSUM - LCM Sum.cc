#include <bits/stdc++.h>
using namespace std;

#define maxn 1000010

typedef long long ll;
typedef vector<int> vi;

int phi[maxn];
ll ans[maxn];

void solve(){
  int n = maxn;
  for(int i = 1; i < n; ++i){
    phi[i] = i;
  }
  for(int i = 2; i < n; ++i){
    if(phi[i] == i){
      --phi[i];
      for(int j = 2 * i; j < n; j += i){
        phi[j] -= phi[j] / i;
      }
    }
  }

  // http://oeis.org/A051193
  // https://forthright48.blogspot.com.br/2015/08/spoj-lcmsum-lcm-sum.html
  // https://math.stackexchange.com/questions/761670/
  //          how-to-find-this-lcm-sum-function-textlcm1-n-textlcm2-n-cdots-t
  for(int i = 1; i < n; ++i){
    for(int j = i; j < n; j += i){
      ans[j] += (ll)i * phi[i];
    }
    ans[i] = (ll)i * (ans[i] + 1) / 2;
  }
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  solve();

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << ans[n] << '\n';
  }

  return 0;
}
