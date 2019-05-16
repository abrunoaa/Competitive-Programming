#define st first
#define nd second
typedef pair<int,int> ii;

int n, m;// itens, tamanho da mochila
int v[maxn], w[maxn];// valor, peso
int dp[maxm];

// knapsack com infinitas repetições (0..n knapsack)
void unboundedKnapsack(){
  memset(dp, 0, sizeof dp);
  for(int i = 0; i < n; ++i){
    int v = ::v[i], w = ::w[i];
    for(int j = w; j <= m; ++j)
      dp[j] = max(dp[j], dp[j - w] + v);
  }
}

/// unbounded com m muito grande (ex 10^18) e w pequeno
int wm;// menor w[i]
int t[maxn];// t[i] = menor mochila que pode ser obtida com i = m mod wm
int g[maxm][maxm];// grafo com wm vértices

// checa em O(1)
inline bool bigm(int m){ return m >= t[m % wm]; }

void build(){// pré-calculo em O(wm² + n*wm)
  wm = inf;
  for(int i = 0; i < n; ++i) wm = min(wm, w[i]);
  for(int i = 0; i < wm; ++i)
    for(int j = 0; j < wm; ++j)
      g[i][j] = inf;
  for(int i = 0; i < n; ++i)
    for(int j = 0, w = ::w[i]; j < wm; ++j){
      int& r = g[j][(w + j) % wm];
      r = min(r, w);
    }

  // dijkstra
  memset(t, inf, sizeof t);
  t[0] = 0;
  priority_queue<ii,vector<ii>,greater<ii>> q;
  q.push({0, 0});
  while(!q.empty()){
    ii f = q.top();
    q.pop();
    int u = f.nd;
    int d = f.st;
    if(d > t[u]) continue;
    for(int v = 0; v < wm; ++v)
      if(d + g[u][v] < t[v]){
        t[v] = d + g[u][v];
        q.push({t[v], v});
      }
  }
}
