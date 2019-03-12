#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__(){ cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n"; }

void debug(){}
template<class t,class... u> void debug(const t& x,const u& ...y){ cerr<<' '<<x,debug(y...); }
#define debug(x...) cerr<<"\x1b[91m[" #x "] =",debug(x),cerr<<"\x1b[0m\n"
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

int red[50], memo[50][50];

int f(int l, int r){
  if(l > r) return 1;
  if((r - l + 1) % 3) return 0;

  int &pd = memo[l][r];
  if(pd != -1) return pd;

  pd = 0;
  for(int i = l + 1; i <= r; ++i){
    for(int j = i + 1; j <= r; ++j){
      if(red[l] + red[i] + red[j] <= 1){
        pd += f(l + 1, i - 1) * f(i + 1, j - 1) * f(j + 1, r);
      }
    }
  }
  return pd;
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t){
    int p;
    cin >> p;
    for(int i = 0; i < p; ++i){
      char c;
      cin >> c;
      red[i] = c == 'R';
    }
    memset(memo, -1, sizeof memo);
    cout << "Case " << t << ": " << f(0, p-1) << '\n';
  }

  return 0;
}
