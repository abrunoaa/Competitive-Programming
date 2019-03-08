#include <bits/stdc++.h>
using namespace std;

#define maxn 100010

int n, a[maxn];

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  long long ans = 0;
  map<int,int> f;

  cin >> n;
  while(n--){
    int a;
    cin >> a;
    int &k = f[__builtin_popcount(a)];
    ans += k;
    ++k;
  }
  cout << ans << '\n';
}
