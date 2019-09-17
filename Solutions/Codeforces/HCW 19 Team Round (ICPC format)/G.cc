#include<bits/stdc++.h>
using namespace std;
#define maxn 300000
#define nd second
#define pb push_back
#define st first

typedef pair<int, int > ii;

int n1, n2;
vector<int> g1[maxn], g2[maxn];

ii dfs(int u, int p, vector<int> * g){
  ii sub = ii(0, u);
  for(int v : g[u]){
    if(v == p) continue;
    sub = max(sub, dfs(v, u, g));
  }
  sub.st++;
  return sub;
}

int main(){

  // freopen("gin","r",stdin);
  cin.sync_with_stdio(0);

  cin>>n1;
  for(int i = 0; i < n1-1; i++){
    int u, v;
    cin>>u>>v;
    g1[u].pb(v), g1[v].pb(u);
  }
  cin>>n2;
  for(int i = 0; i < n2-1; i++){
    int u, v;
    cin>>u>>v;
    g2[u].pb(v), g2[v].pb(u);
  }

  int d1 = dfs(dfs(1, -1, g1).nd, 1, g1).st;
  int d2 = dfs(dfs(1, -1, g2).nd, 1, g2).st;
  d2 = ceil(d2/2.);

  if(d1 > d2) cout<<"GGEZ"<<endl;
  else cout<<"FF"<<endl;

}
