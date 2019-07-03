#include <bits/stdc++.h>
using namespace std;

#define maxn int(1e5 + 3)
#define x first
#define y second

typedef long long ll;
typedef pair<int,int> ii;

int n;
ll a[2 * maxn];
vector<ii> p;

inline ll cross(const ii& p, const ii& q){
  return (ll)p.x * q.y - (ll)q.x * p.y;
}

inline ll calc(int i, int j){
  if(j - i < 2) return 0; // error!
  return a[j - 1] - (i == 0 ? 0 : a[i - 1]) + cross(p[j], p[i]);
}

int main(){
  // assert(freopen("in","r",stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> n;
  p.reserve(2 * n + 2);
  for(int i = 0; i < n; ++i){
    int x, y;
    cin >> x >> y;
    p.push_back({ x, y });
  }
  p.insert(p.end(), p.begin(), p.end());
  p.push_back(p[0]);
  a[0] = 0;
  for(int i = 0; i < 2 * n; ++i){
    a[i + 1] = a[i] += cross(p[i], p[i + 1]);
  }
  ll ans = 0;
  ll total = calc(0, n - 1);
  for(int i = 0, j = 2; i < n; ++i){
    for(; i != j - n && 2 * calc(i, j) <= total; ++j);
    ll c0 = calc(i, j);
    ll c1 = calc(i, j - 1);
    ll choose = min(max(c0, total - c0), max(c1, total - c1));
    ans = max(ans, choose);
  }
  cout << ans << ' ' << total - ans << '\n';
  return 0;
}
