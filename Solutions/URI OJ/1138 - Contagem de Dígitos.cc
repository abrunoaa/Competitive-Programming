#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi nil = {0,0,0,0,0,0,0,0,0,0,1}, memo[10][2][2];
string n;

vi& f(int i, bool less, bool zero){
  if(i == (int)n.size()) return nil;

  auto &pd = memo[i][less][zero];
  if(!pd.empty()) return pd;
  pd.assign(11, 0);

  int lim = (less ? 9 : n[i] - '0');
  for(int d = 0; d <= lim; ++d){
    vi& t = f(i + 1, less || d < lim, zero && d == 0);

    for(int k = 0; k <= 10; ++k){
      pd[k] += t[k];
    }
    pd[d] += (!zero || d) * t[10];
  }

  return pd;
}

void init(int x){
  n = to_string(x);
  for(int i = 0; i < 10; ++i){
    for(int j = 0; j < 2; ++j){
      for(int k = 0; k < 2; ++k){
        memo[i][j][k].clear();
      }
    }
  }
}

int main(){
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  int a, b;
  while(cin >> a >> b && (a || b)){
    init(b);
    vi u = f(0, 0, 1);
    init(a - 1);
    vi v = f(0, 0, 1);

    for(int i = 0; i < 10; ++i){
      if(i) cout << ' ';
      cout << u[i] - v[i];
    }
    cout << '\n';
  }

  return 0;
}
