#include <iostream>
using namespace std;

#define maxn 5003
#define infl 0x3f3f3f3f3f3f3f3f

typedef long long ll;

int n, k, a[maxn];
ll x[maxn][maxn], cost[maxn][maxn], memo[maxn][maxn];

void calc(int p, int x = 0, int y = n - 1, int l = 0, int r = n - 1){
  if(l > r) return;
  int m = (l + r) / 2;
  auto &dp = memo[p][m] = infl;
  int best = -1;
  for(int k = max(x, m); k <= y; ++k){
    if(memo[p - 1][k + 1] + cost[m][k] < dp){
      dp = memo[p - 1][k + 1] + cost[m][k];
      best = k;
    }
  }
  calc(p, x, best, l, m - 1);
  calc(p, best, y, m + 1, r);
}

int main(){
  //assert(freopen("in","r",stdin));
	cin.sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; ++i){
	  cin >> a[i];l
	}
	for(int i = 0; i < n; ++i){
	  for(int j = i - 1; j >= 0; --j){
	    x[i][j] = x[i][j + 1] + (a[i] ^ a[j]);
	  }
	}
	for(int i = 0; i < n; ++i){
	  for(int j = i + 1; j < n; ++j){
	    cost[i][j] = cost[i][j - 1] + x[j][i];
	  }
	}
	for(int i = 0; i < n; ++i){
	  memo[0][i] = cost[i][n - 1];
	}
	for(int i = 1; i <= k; ++i){
	  calc(i);
	}
	cout << memo[k][0] << '\n';
	return 0;
}