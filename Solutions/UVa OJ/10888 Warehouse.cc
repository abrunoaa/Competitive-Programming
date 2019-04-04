// #pragma GCC optimize("O2")
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

#define st first
#define nd second
#define inf 0x3f3f3f3f
#define maxn 16
#define maxh 41

typedef pair<int,int> ii;

const int I[] = {0,0,1,-1}, J[] = {1,-1,0,0};
int n, h, w, dis[maxh][maxh], xid[maxh][maxh], cost[maxn][maxn], pd[1 << maxn];
char grid[maxh][maxh];

void bfs(int b, int i, int j){
  memset(dis, inf, sizeof dis);
  dis[i][j] = 0;
  queue<ii> q;
  q.push({i,j});
  while(!q.empty()){
    int i = q.front().st;
    int j = q.front().nd;
    q.pop();
    for(int k = 0; k < 4; ++k){
      int x = i + I[k];
      int y = j + J[k];
      if(x < 0 || x >= h || y < 0 || y >= w) continue;
      if(grid[x][y] == '#') continue;
      if(dis[x][y] < inf) continue;
      dis[x][y] = dis[i][j] + 1;
      q.push({x, y});
      if(grid[x][y] == 'X') cost[b][xid[x][y]] = dis[x][y];
    }
  }
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    cin >> h >> w;
    for(int i = 0; i < h; ++i)
      for(int j = 0; j < w; ++j)
        cin >> grid[i][j];

    memset(xid, inf, sizeof xid);
    for(int i = 0, n = 0; i < h; ++i)
      for(int j = 0; j < w; ++j)
        if(grid[i][j] == 'X')
          xid[i][j] = n++;

    int n = 0;
    memset(cost, inf, sizeof cost);
    for(int i = 0; i < h; ++i)
      for(int j = 0; j < w; ++j)
        if(grid[i][j] == 'B')
          bfs(n++, i, j);

    vector<int> mask[maxn];
    for(int i = 0; i < (1 << n); ++i)
      mask[__builtin_popcount(i)].push_back(i);

    memset(pd, inf, sizeof pd);
    pd[0] = 0;
    for(int i = 0; i < n; ++i)
      for(int m : mask[i])  // só com i itens (o resto não importa, vai dar repetido)
        for(int j = 0; j < n; ++j)
          if((m & (1 << j)) == 0)
            pd[m | (1 << j)] = min(pd[m | (1 << j)], pd[m] + cost[i][j]);

    cout << pd[(1 << n) - 1] << '\n';
  }

  return 0;
}
