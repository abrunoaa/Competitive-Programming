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
// #define mod 1000000007
#define maxn 1000003

typedef long long ll;

struct State{
  int g, r, n0, n3;
};

bool mod[2][maxn];

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n;
  while(cin >> n){
    memset(mod, 0, sizeof mod);
    bool flag = 0;
    queue<State> q;
    q.push({1, 0, 0, 0});
    debug(n);
    while(!q.empty()){
      State s = q.front();
      q.pop();

      if(flag){
        if(s.r == 0){
          cout << s.n0 + s.n3 << ' ' << s.n3 << ' ' << s.n0 << '\n';
          break;
        }

        int r0 = s.r * 10 % n;
        if(!mod[0][r0]){
          debug(s.r, r0);
          mod[0][r0] = 1;
          q.push({0, r0, s.n0 + 1, s.n3});
        }
      }
      flag = 1;

      if(!s.g) continue;
      int r3 = (s.r * 10 + 3) % n;
      if(!mod[1][r3]){
        debug(s.r, r3);
        mod[1][r3] = 1;
        q.push({1, r3, s.n0, s.n3 + 1});
      }
    }
  }

  return 0;
}
