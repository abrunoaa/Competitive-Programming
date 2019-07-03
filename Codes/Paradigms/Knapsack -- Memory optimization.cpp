#include <cstring>

#include <iostream>
#include <vector>
using namespace std;

#define maxn 2003

int n, m;
int w[maxn], v[maxn];
int dp[maxn], middle[maxn];
vector<int> used;

void ks(int l, int r, int m){
  int mid = (l + r) / 2;
  memset(dp, 0, sizeof(dp));
  for(int i = l; i <= r; ++i){
    int v = ::v[i];
    int w = ::w[i];
    for(int j = m; j >= w; --j){
      if(dp[j - w] + v > dp[j]){
        dp[j] = dp[j - w] + v;
        middle[j] = middle[j - w];
      }
    }
    if(i == mid){
      for(int j = 0; j <= m; ++j){
        middle[j] = j;
      }
    }
  }
}

void rec(int l, int r, int m){
  if(l == r){
    if(w[l] <= m){
      used.push_back(l);
    }
    return;
  }
  ks(l, r, m);
  int mid = (l + r) / 2;
  int p = middle[m];
  rec(l, mid, p);
  rec(mid + 1, r, m - p);
}

void run(){
  used.clear();
  rec(0, n - 1, m);
  int ans = 0;
  for(int x : used){
    ans += v[x];
  }
  cout << ans << '\n';
}

int main(){
  // freopen("in", "r", stdin);
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  for(int i = 0; i < n; ++i){
    cin >> w[i] >> v[i];
  }
  run();
  return 0;
}
