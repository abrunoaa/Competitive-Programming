#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define inf 0x3f3f3f3f

typedef pair<int,int> ii;

#define maxn 1000003

map<int,ii> memo[maxn][2];

int p;
string l, ans;

ii f(int i, int r, bool z){
  if(i == (int)l.size()) return ii(-inf * (r != 0 || !z), -1);

  if(memo[i][z].count(r)) return memo[i][z][r];
  auto &pd = memo[i][z][r];

  if(!z && l[i] == '0') return pd = max(ii(1, 0), f(i + 1, 0, 0));

  pd = f(i + 1, r, z);
  ii t = f(i + 1, (r * 10 + l[i] - '0') % p, 1);
  ++t.st;
  t.nd = l[i] - '0';
  return pd = max(pd, t);
}

void rec(int i, int r, bool z){
  if(i == (int)l.size()) return;
  if(!z && l[i] == '0'){
    if(memo[i][z][r] != memo[i + 1][0][0]){
      ans = "0";
      return;
    }
    return rec(i + 1, 0, 0);
  }
  if(!memo[i][z][r].st) return;
  if(memo[i][z][r] == memo[i + 1][z][r] && l[i] - '0' != memo[i + 1][z][r].nd) return rec(i + 1, r, z);
  ans.push_back(l[i]);
  rec(i + 1, (r * 10 + l[i] - '0') % p, 1);
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> l >> p;
  if(f(0, 0, 0).st <= 0){
    cout << "-1\n";
    return 0;
  }
  rec(0, 0, 0);
  cout << ans << '\n';
  return 0;
}
