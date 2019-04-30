#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__(){cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}

void debug(){}
template<class t,class... u> void debug(const t&x,const u&...y){cerr<<' '<<x,debug(y...);}
# define debug(x...) cerr<<"\x1b[91m"<<__LINE__<<" ["#x"] =",debug(x),cerr<<"\x1b[0m\n"
# define sleep(x) this_thread::sleep_for(chrono::milliseconds(x))
#else
# define assert(x) void(0)
# define debug(...) void(0)
# define freopen(...) void(0)
# define sleep(x) void(0)
#endif

bool usado[21], resp[21];
int n, t, numUsado, fita, numFita, cd[21];

void f(int i, int total, int numUsado){
  if(total > n) return;
  if(i == t){
    if(total > fita || (total == fita && numUsado > numFita)){
      numFita = numUsado;
      fita = total;
      memcpy(resp, usado, sizeof(usado));
    }
    return;
  }

  f(i + 1, total, numUsado);
  usado[i] = 1;
  f(i + 1, total + cd[i], numUsado + 1);
  usado[i] = 0;
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  while(cin >> n >> t){
    for(int i = 0; i < t; ++i) cin >> cd[i];

    numUsado = 0;
    numFita = 0;
    fita = 0;
    f(0, 0, 0);

    for(int i = 0; i < t; ++i)
      if(resp[i])
        cout << cd[i] << ' ';
    cout << "sum:" << fita << '\n';
  }

  return 0;
}
