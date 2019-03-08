#include <bits/stdc++.h>
using namespace std;

#define maxn 200010

int n, a[maxn], b[maxn];

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  while(cin >> n){
    multimap<int,int> m;

    for(int i = 0; i < n; ++i){
      cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
      cin >> b[i];
      m.insert(make_pair(b[i], 0));
    }

    sort(a, a + n);
    int i = n - 1;
    for(auto& it : m){
      it.second = a[i];
      --i;
      // cerr << " >> " << it.first << ' ' << it.second << endl;
    }

    for(int i = 0; i < n; ++i){
      if(i) cout << ' ';

      auto it = m.find(b[i]);
      cout << it->second;
      m.erase(it);
    }
    cout << '\n';
  }

  return 0;
}
