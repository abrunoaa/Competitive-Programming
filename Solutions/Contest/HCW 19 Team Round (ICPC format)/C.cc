#include <bits/stdc++.h>
using namespace std;

#define maxn 2003
#define inf (int)1e9

typedef long long ll;

int n, dp[maxn][maxn];
ll arr[maxn];

int f(int i, int disp, int w){
  if(i >= n) return 0;
  auto & r = dp[i][disp];
  if(r != -1) return r;
  r = inf;

  if(disp > 0){
    int idx = (int)(upper_bound(arr, arr+n, (ll)arr[i]+w-1) - arr);
    r = min(r, f(idx, disp-1, w));
  }
  int idx2 = (int)(upper_bound(arr, arr+n, (ll)arr[i]+2ll*w-1) - arr);
  return r = min(r, f(idx2, disp, w) + 1);
}

int main(){
  // assert(freopen("cin","r",stdin));
  cin.sync_with_stdio(0), cin.tie(0);

  int p, q;
  cin>>n>>p>>q;
  if (p + q >= n) {
    cout << "1\n";
    return 0;
  }

  for(int i = 0; i < n; i++){
    cin>>arr[i];
    // cout<<arr[i]<<' ';
  }
  // cout<<endl;
  sort(arr, arr+n);
  p = min(p, 2000);
  q = min(q, 2000);
  int L = 1 , R = (int)1e9;
  while(L < R){
    memset(dp, -1, sizeof dp);
    int mid = (L+R)/2;
    if(f(0, p, mid) <= q) R = mid;
    else L = mid+1;
  }
  // memset(dp, -1, sizeof dp);
  // cout<< ">> "<<f(0, p, 4)<<endl;
  cout<<L<<endl;
}
