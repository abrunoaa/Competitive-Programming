/* Sparse table's friend: Exemplo de multiplicação */

#define clz __builtin_clzll
#define lg(x) (63 - clz(x))
#define maxn (2 << lg(1000000)) // 2 * (menor potência de dois >= n)

typedef long long ll;

int n, a[maxn];
int st[lg(maxn)][maxn];

void build(){
  for(int i = 0; (1 << i) <= n; ++i){
    int *v = st[i];
    for(int s = 1; (s << i) <= n; s += 2){
      int k = s << i;
      v[k] = a[k] % mod;
      v[k - 1] = a[k - 1] % mod;
      for(int j = 1; j < (1 << i); ++j){
        v[k + j] = (int)((ll)a[k + j] * v[k + j - 1] % mod);
        v[k - j - 1] = (int)((ll)a[k - j - 1] * v[k - j] % mod);
      }
    }
  }
}

int qry(int i, int j){
  if(i == j) return a[i] % mod;
  int k = 63 - clz(i ^ j);
  return (int)((ll)st[k][i] * st[k][j] % mod);
}
