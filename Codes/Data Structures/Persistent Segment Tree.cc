/// Persistent Segment Tree

#include <bits/stdc++.h>
using namespace std;

void debug(){}
template<class t, class... u> void debug(t x, u ...y){ cerr << ' ' << x, debug(y...); }
#define debug(x...) cerr << "\x1b[91m[" #x "] =", debug(x), cerr << "\x1b[0m\n"

typedef vector<int> vi;

#define maxn 100010
#define maxq 100010
#define maxs (2 * maxn + maxq * ((int)log2(maxn) + 1))  // 2n + q*lg n

#define M ((l + r) / 2)

int n, arr[maxn];
int root[maxq];             // raízes das versões
int nno;                    // nº de nós "alocados"
int st[maxs];               // segtree
int lc[maxs], rc[maxs];     // filhos esquerda(lc) e direita(rc)

// cria uma cópia do nó v em uma nova posição, salvando em u
int copy(int& u, int v){
  lc[nno] = lc[v];
  rc[nno] = rc[v];
  st[nno] = st[v];
  return u = nno++;
}

// constrói a versão 0 da segtree
/// ==> não é necessário se o valor inicial for 0
int build(int k, int l = 1, int r = n){
  if(l == r) return st[k] = arr[l];
  lc[k] = nno++;
  rc[k] = nno++;
  return st[k] = build(lc[k], l, M) + build(rc[k], M+1, r);
}

// atualiza uma segtree (criando novos nós)
/// ==> antes executar: copy(root[**NOVA VERSÃO**], root[**VERSÃO ANTERIOR**]) <==
// i = posição para atualizar
// x = valor para somar
// k = raiz da nova versão
int upd(int i, int x, int k, int l = 1, int r = n){
  if(l == r) return st[k] += x;
  if(i <= M) return st[k] = upd(i, x, copy(lc[k], lc[k]), l, M) + st[rc[k]];
  return st[k] = st[lc[k]] + upd(i, x, copy(rc[k], rc[k]), M+1, r);
}

// k = raiz da versão para consulta
int qry(int i, int j, int k, int l = 1, int r = n){
  if(r < i || j < l) return 0;
  if(i <= l && r <= j) return st[k];
  return qry(i, j, lc[k], l, M) + qry(i, j, rc[k], M+1, r);
}

int main(){
  // debug
  nno = -1e9;
  memset(st, -1, sizeof st);
  memset(lc, -1, sizeof lc);
  memset(rc, -1, sizeof rc);
  memset(root, -1, sizeof root);

  // inicializa
  nno = 0;

  // valores aleatórios ==> deve rodar em O(n^3)!
  n = 100;
  for(int i = 1; i <= n; ++i){
    arr[i] = rand() % 1000;
  }

  int nv = 100; // nº de versões
  vi v[nv];

  // versão 0
  v[0].assign(arr, arr + n + 1);
  root[0] = nno++;
  build(root[0]);

  // versão i a partir da versão j
  for(int i = 1; i < nv; ++i){
    int j = rand() % i;
    int k = rand() % n + 1;
    int x = rand() % 1000;

    // atualiza força bruta
    v[i] = v[j];
    v[i][k] += x;

    // atualiza segtree
    copy(root[i], root[j]);
    upd(k, x, root[i]);
  }

  // força bruta para teste
  for(int r = 0; r < nv; ++r){
    for(int i = 1; i <= n; ++i){
      for(int j = i; j <= n; ++j){
        int fb = 0;
        for(int k = i; k <= j; ++k){
          fb += v[r][k];
        }
        assert(fb == qry(i, j, root[r]));
      }
    }
  }

  cout << "Ok, it's working!\n";

  return 0;
}
