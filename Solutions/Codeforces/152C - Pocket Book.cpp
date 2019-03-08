#include <bits/stdc++.h>
using namespace std;

#define maxn 110
#define mod 1000000007

typedef long long ll;

char s[maxn];
int letters[maxn];

int main(){
  cin.sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    cin >> s;
    for(int j = 0; j < m; ++j){
      letters[j] |= 1 << (s[j] - 'A');
    }
  }
  int ans = 1;
  for(int i = 0; i < m; ++i){
    ans = (ll)ans * __builtin_popcount(letters[i]) % mod;
  }
  cout << ans << '\n';

  return 0;
}
