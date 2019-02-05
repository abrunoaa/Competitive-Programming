#include <bits/stdc++.h>
using namespace std;

#define maxn 100010

#define b first.first
#define f first.second
#define d second

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,ll> tri;

int n;
ll xxx[maxn], ft[maxn];
tri v[maxn];
map<int,int> mp;

ll qry(int i){
  ll s = 0;
  for(; i > 0; i -= i & -i){
    s = max(s, ft[i]);
  }
  return s;
}

void upd(int i, ll d){
  for(; i < maxn; i += i & -i){
    ft[i] = max(ft[i], d);
  }
}

int main(){
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> v[i].b >> v[i].f >> v[i].d;
    mp[v[i].f];
  }
  sort(v, v + n);

  int k = 0;
  for(auto& p : mp){
    p.second = ++k;
  }

  int m = 0;
  for(int i = 0; i < n; ){
    v[m] = v[i];
    while(++i < n && v[i - 1].b == v[i].b && v[i - 1].f == v[i].f){
      v[m].d += v[i].d;
    }

    ++m;
  }

  ll ans = 0;
  for(int i = 0, j; i < m; i = j){
    for(j = i; v[j].b == v[i].b; ++j){
      ll d = qry(mp[v[j].f]) + v[j].d;
      ans = max(ans, d);
      xxx[j] = d;
    }
    for(j = i; v[j].b == v[i].b; ++j){
      upd(mp[v[j].f] + 1, xxx[j]);
    }
  }

  cout << ans << '\n';

  return 0;
}
