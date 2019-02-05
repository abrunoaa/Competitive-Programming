#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define inf 0x3f3f3f3f
#define st first
#define nd second

typedef pair<int,int> ii;

int nxt[maxn], bit[2 * maxn];
ii tv[maxn];

int find(int u){
  return (u == nxt[u] ? u : nxt[u] = find(nxt[u]));
}

int main(){
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; ++i){
    cin >> tv[i].st >> tv[i].nd;
  }

  sort(tv + 1, tv + n + 1, [](const ii& x, const ii& y){
    return x.nd != y.nd ? x.nd < y.nd : x.st > y.st;
  });

  int ans = 0;
  multiset<int> s;
  for(int i = 1; i <= n; ++i){
    // cerr << " $$ ";
    // for(int x : s){
      // cerr << x << ' ';
    // }
    // cerr << endl;
    auto it = s.upper_bound(tv[i].st);
    if(it == s.begin()){
      // cerr << " >> " << tv[i].st << ' ' << s.size() << endl;
      if((int)s.size() < k){
        s.insert(tv[i].nd);
        ++ans;
      }
    }
    else{
      --it;
      // cerr << " ## " << *it << ' ' << tv[i].st << endl;
      s.erase(it);
      s.insert(tv[i].nd);
      ++ans;
    }
  }

  cout << ans << '\n';

  return 0;
}
