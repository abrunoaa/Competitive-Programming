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
#define maxn 300003

typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;

bool vis[maxn], used[maxn];
vector<ii> g[maxn];

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  
  int n, k, d;
  cin >> n >> k >> d;
  
  queue<ii> q;
  for(int i = 0; i < k; ++i){
    int p;
    cin >> p;
    q.push({p,0});
    vis[p] = 1;
  }
  
  for(int i = 1; i <= n - 1; ++i){
    int u, v;
    cin >> u >> v;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  
  while(!q.empty()) {
    ii f = q.front();
    q.pop();
    
    int u = f.st;
    int dis = f.nd;
    if(dis == d){
      continue;
    }
    
    for(ii p : g[u]){
      int v = p.st;
      int i = p.nd;
      if(!vis[v]){
        vis[v] = 1;
        used[i] = 1;
        q.push({v, dis + 1});
      }
    }
  }
  
  vector<int> down;
  for(int i = 1; i <= n - 1; ++i){
    if(!used[i]){
      down.push_back(i);
    }
  }
  cout << down.size() << '\n';
  for(int x : down){
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}
