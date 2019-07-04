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

#define maxn 41
#define maxs (41 * 1000)

int n, f, a[maxn];
char memo[maxn][2 * maxs];
bool pos[maxn], neg[maxn];

bool run(int i, int s){
  if(i == n) return s == f;

  auto &pd = memo[i][s + maxs];
  if(pd != -1) return pd;
  pd = 0;
  if(run(i + 1, s + a[i])) pd = pos[i] = 1;
  if(run(i + 1, s - a[i])) pd = neg[i] = 1;
  return pd;
}

void init(){
  memset(memo, -1, sizeof memo);
  memset(pos, 0, sizeof pos);
  memset(neg, 0, sizeof neg);
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  while(cin >> n >> f && (n || f)){
    for(int i = 0; i < n; ++i){
      cin >> a[i];
    }
    init();
    if(!run(0, 0)){
      cout << "*\n";
    }
    else{
      for(int i = 0; i < n; ++i){
        cout << (!(pos[i] ^ neg[i]) ? '?' : pos[i] ? '+' : '-');
      }
      cout << '\n';
    }
  }

  return 0;
}
