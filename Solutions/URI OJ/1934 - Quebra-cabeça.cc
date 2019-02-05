#include <bits/stdc++.h>
using namespace std;

#define maxn 102
#define inf 0x3f3f3f3f

typedef long long ll;
typedef pair<string,int> P;

int value[maxn * maxn], var[maxn][maxn];
ll sum_line[maxn], sum_colum[maxn], sum[maxn];
string rev_mp[maxn * maxn];

void solve(map<int,int>& mp, ll sum){
  auto it = *mp.begin();
  int x = it.first;
  int f = it.second;
  value[x] = sum / f;
}

int main(){
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  int l, c;
  cin >> l >> c;

  int cnt = 0;
  map<string,int> mp;
  for(int i = 0; i < l; ++i){
    for(int j = 0; j < c; ++j){
      string s;
      cin >> s;

      int& k = mp[s];
      if(!k){
        k = ++cnt;
        rev_mp[k] = s;
      }

      var[i][j] = k;
    }
    cin >> sum_line[i];
  }
  for(int j = 0; j < c; ++j){
    cin >> sum_colum[j];
  }

  memset(value, inf, sizeof value);

  bool variable = 1;
  while(variable){
    variable = 0;

    memcpy(sum, sum_colum, sizeof sum);

    map<int,int> v[c];
    for(int i = 0; i < l; ++i){
      ll sum_i = sum_line[i];
      map<int,int> u;

      for(int j = 0; j < c; ++j){
        int x = var[i][j];
        if(value[x] == inf){
          variable = 1;
          ++u[x];
          ++v[j][x];
        }
        else{
          sum_i -= value[x];
          sum[j] -= value[x];
        }
      }

      if(u.size() == 1){
        solve(u, sum_i);
      }
    }

    for(int j = 0; j < c; ++j){
      if(v[j].size() == 1){
        solve(v[j], sum[j]);
      }
    }
  }

  vector<P> ans;
  ans.reserve(cnt);
  for(int k = 1; k <= cnt; ++k){
    ans.push_back(P(rev_mp[k], value[k]));
  }

  sort(ans.begin(), ans.end());
  for(auto p : ans){
    cout << p.first << ' ' << p.second << '\n';
  }

  return 0;
}
