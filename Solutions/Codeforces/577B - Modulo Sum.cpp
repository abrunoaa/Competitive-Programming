#include <bits/stdc++.h>
using namespace std;

#define maxn 1010

char memo[maxn][maxn][2];
int n, m, a[maxn];

bool f(int i, int x, bool added){
  if(i == n)
    return added && x == 0;

  auto &pd = memo[i][x][added];
  if(pd != -1)
    return pd;
  return (pd = f(i + 1, x, added) || f(i + 1, (x + a[i]) % m, 1));
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  memset(memo, -1, sizeof memo);

  cin >> n >> m;
  if(n > m){
    cout << "YES\n";
    return 0;
  }

  for(int i = 0; i < n; ++i)
    cin >> a[i];
  cout << (f(0, 0, 0) ? "YES" : "NO") << '\n';

  return 0;
}
