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

#define null nullptr
#define st first
#define nd second
#define mod 1000000007
#define maxn 503

typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;

char s[maxn];
int memo[maxn][maxn][2];

int f(int i, int j, int c){
  if(i > j) return 0;
  int &pd = memo[i][j][c];
  if(pd != -1) return pd;
  pd = f(i + 1, j, 1) + c;
  for(int k = i + 1; k <= j; ++k){
    if(s[k] == s[i]){
      pd = min(pd, f(i + 1, k - 1, 1) + f(k, j, 0) + c);
    }
  }
  return pd;
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n >> s;
  memset(memo, -1, sizeof memo);
  cout << f(0, n - 1, 1) << '\n';
  return 0;
}
