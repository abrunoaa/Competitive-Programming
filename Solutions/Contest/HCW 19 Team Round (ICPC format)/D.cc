#include<bits/stdc++.h>
using namespace std;

// const int maxn = 5e5+100;


int main(){
  // freopen("din","r",stdin);
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie();

  long long x0,y0,r,n,y,x;
  cin >> x0 >> y0 >> r >> n;
  r*=r;
  // int ans = 0;
  set<long double> st;
  for(int i = 0 ; i < n ; ++i){
    cin >> x >> y;
    if(r >=  (x-x0)*(x-x0) + (y-y0)*(y-y0)) st.insert(atan2(y-y0,x-x0));
  }
  cout << st.size() << '\n';

  return 0;
}
