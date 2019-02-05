#include <iostream>
#include <deque>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std;

#define maxn 10002
#define maxm 10002
#define inf 0x3f3f3f3f
#define st first
#define nd second

typedef pair<int,int> ii;

template<class T> struct MaxQueue{
  int n;
  T lazy;
  deque<pair<T,int>> q;
  MaxQueue() : n(0), lazy(0), q() {}
  
  int size(){ return n; }
  void clear(){ n = 0; lazy = 0; q.clear(); }
  void push(T x){
    ++n;
    x -= lazy;
    int k = 1;
    for(; !q.empty() && q.back().st <= x; q.pop_back()) k += q.back().nd;
    q.push_back({x,k});
  }
  void pop(){ --n; if(!--q.front().nd) q.pop_front(); }
  void add(T x){ lazy += x; }
  T front(){ return q.front().st + lazy; }
};

int n, m;// itens, tamanho da mochila
int v[maxn], w[maxn], b[maxn];// valor, peso, nº de repetições
int dp[maxm];
MaxQueue<int> q[maxm];

/// cache friends
// knapsack 0-1
void knapsack(){
  memset(dp, 0, sizeof dp);
  for(int i = 0; i < n; ++i){
    int v = ::v[i], w = ::w[i];
    for(int j = m; j >= w; --j)
      dp[j] = max(dp[j], dp[j - w] + v);
  }
}

// knapsack com infinitas repetições (0..n knapsack)
void unboundedKnapsack(){
  memset(dp, 0, sizeof dp);
  for(int i = 0; i < n; ++i){
    int v = ::v[i], w = ::w[i];
    for(int j = w; j <= m; ++j)
      dp[j] = max(dp[j], dp[j - w] + v);
  }
}

// knapsack com b[i] repetições do item i
void boundedKnapsack(){
  memset(dp, 0, sizeof dp);
  for(int i = 0; i < n; ++i){
    int v = ::v[i], w = ::w[i], b = ::b[i];
    for(int j = 0; j < w; ++j) q[j].clear(), q[j].push(dp[j]);
    for(int j = w; j <= m; ++j){
      auto& p = q[j % w];
      if(p.size() > b) p.pop();
      p.add(v);
      p.push(dp[j]);
      dp[j] = p.front();
    }
  }
}

/// checa se um peso pode ser atingido na mochila
void boundedKnapsack_weigthOnly(){
  memset(dp, 0, sizeof dp);
  dp[0] = 1;
  for(int i = 0; i < n; ++i){
    int w = ::w[i], b = ::b[i];// se w repetir, soma os b's
    for(int j = m - w; j >= 0; --j)
      if(dp[j])
        for(int k = 1; k <= b && j + k * w <= m && !dp[j + k * w]; ++k)
          dp[j + k * w] = 1;
  }
}

/// unbounded com m muito grande (ex 10^18) e w pequeno
int wm;// menor w[i]
int t[maxn];// t[i] = menor mochila que pode ser obtida com i = m mod wm
int g[maxm][maxm];// grafo com wm vértices

inline bool bigm(int m){ return m >= t[m % wm]; }

void bigm(){// O(wm² + n*wm)
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
  q.push({0,0});
  while(!q.empty()){
    ii f = q.top();
    q.pop();
    int u = f.nd;
    int d = f.st;
    if(d > t[u]) continue;
    for(int v = 0; v < wm; ++v)
      if(d + g[u][v] < t[v]){
        t[v] = d + g[u][v];
        q.push({t[v],v});
      }
  }
}

/// knapsack 0-1 apenas w com remoção
#define mod int(1e9 + 7) // menos chance de dar errado: usar vários primos

void knapsack_weigthOnly_withRemove(){
  memset(dp, 0, sizeof dp);
  dp[0] = 1;// dp[j] ≠ 0 -> o peso é possível
  for(int i = 0; i < n; ++i){
    int w = ::w[i];
    for(int j = m; j >= w; --j)
      dp[j] = (dp[j] + dp[j - w]) % mod;// n° de maneiras de conseguir peso j
  }
}

void remove(int i){// assume que i está na mochila
  // remove todas as combinações que o item i adiciona
  int w = ::w[i];
  for(int j = w; j <= m; ++j)
    dp[j] = (dp[j] - dp[j - w] + mod) % mod;
}

/// reconstrução
int memo[maxn][maxm];

int rec(int i = n, int j = m){
  if(!i) return 0;// retorna para teste
  int v = ::v[i-1], w = ::w[i-1];
  for(int k = 0; ; ++k)
    if(memo[i][j] == memo[i-1][j - k * w] + k * v)
      return rec(i-1, j - k * w) + k * v;// o item i aparece k vezes
}

void recBoundedKnapsack(){// todos os knapsacks seguem a mesma ideia
  memset(memo[0], 0, sizeof memo[0]);
  for(int i = 1; i <= n; ++i){
    int v = ::v[i-1], w = ::w[i-1], b = ::b[i-1];
    for(int j = 0; j <= m; ++j){
      auto& p = q[j % w];
      if(j < w) p.clear();
      else if(p.size() > b) p.pop();
      p.add(v);
      p.push(memo[i-1][j]);
      memo[i][j] = p.front();
    }
  }
}





/// testes
void bruteBoundedKnapsack(){
  memset(dp, 0, sizeof dp);
  for(int i = 0; i < n; ++i){
    int v = ::v[i], w = ::w[i], b = ::b[i];
    for(int j = m; j >= w; --j)
      for(int k = 1; k <= b && j >= k * w; ++k)
        dp[j] = max(dp[j], dp[j - k * w] + k * v);
  }
}

void test(int N, int M, int B){
  n = rand() % N + 1;
  m = rand() % M + 1;
  for(int i = 0; i < n; ++i){
    v[i] = rand() % n + 1;
    w[i] = rand() % m + 1;
    b[i] = rand() % B + 1;
    // cout << v[i] << ' ' << w[i] << ' ' << b[i] << endl;
  }
  bruteBoundedKnapsack();
  int ans = dp[m];
  boundedKnapsack();
  int ans2 = dp[m];
  recBoundedKnapsack();
  int ans3 = memo[n][m], r = rec();
  // cout << ans << ' ' << ans2 << ' ' << ans3 << ' ' << r << endl;
  assert(ans == ans2);
  assert(ans == ans3);
  assert(ans == r);
  
  m = M;
  bigm();
  // cout << " ## t ="; for(int i = 0; i < wm; ++i) cout << ' ' << t[i]; cout << endl;
  for(int i = 0; i < n; ++i) v[i] = w[i];
  unboundedKnapsack();// calcula dp[j]
  for(int j = 0; j <= m; ++j){
    // cout << " >> " << bigm(j) << ' ' << j << ' ' << dp[j] << endl;
    assert(bigm(j) == (dp[j] == j));
  }
  
  --n;
  knapsack();
  ++n;
  vector<int> ks(dp, dp + m + 1);// ambos usam o vetor dp
  knapsack_weigthOnly_withRemove();
  remove(n - 1);
  for(int j = 0; j <= m; ++j){
    // cout << " >> " << j << ' ' << ks[j] << ' ' << dp[j] << endl;
    assert((bool)dp[j] == (ks[j] == j));// pode dar errado por causa do mod
  }
}

int main(){
  srand(0);
  int T = 100;
  for(int t = 1; t <= T; ++t){
    cout << "test " << t << endl;
    test(100, 1000, 3);
  }
  cout << "ok!\n";
  return 0;
}