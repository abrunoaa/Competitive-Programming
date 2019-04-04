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
#define inf 0x3f3f3f3f
#define maxn 100003

typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;

vector<int> g[maxn];
int dis[maxn], p[maxn];

void rec(int u){
  if(u == 1){
    cout << '1';
  }
  else{
    rec(p[u]);
    cout << ' ' << u;
  }
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
      g[i].clear();
    }
    for(int i = 1; i <= n - 1; ++i){
      int m;
      cin >> m;
      for(int j = 0; j < m; ++j){
        int x;
        cin >> x;
        g[i].push_back(x);
      }
      sort(g[i].begin(), g[i].end());
    }

    memset(dis, inf, sizeof dis);
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
      int u = q.front();
      q.pop();
      for(int v : g[u]){
        if(dis[v] == inf){
          p[v] = u;
          dis[v] = dis[u] + 1;
          q.push(v);
        }
      }
    }

    if(dis[n] == inf){
      cout << "-1\n\n";
    }
    else{
      cout << dis[n] << '\n';
      rec(p[n]);
      cout << "\n\n";
    }
  }

  return 0;
}
