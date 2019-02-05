#include <bits/stdc++.h>
using namespace std;

typedef pair < int, int > ii;
typedef pair < double, ii > dii;

int i, j, k, l, qtd, cc, n, s;
double cost;
ii coord[505];                                          // lista de coordenadas
dii v;
vector < int > p, vis, used;
vector < dii > edge;                                    // lista de arestas

// union find
int find (int a)
{ return p[a] == a ? a : p[a] = find(p[a]); }

inline bool isUnion (int a, int b)
{ return find(a) == find(b); }

inline void unionSet (int a, int b)
{
  used[a] = used[b] = 1;                                // a e b foram usados
  p[find(a)] = find(b);
}
// \union find

// distancia entre 2 pontos
inline double dist (ii c1, ii c2)
{ return hypot(c1.first - c2.first, c1.second - c2.second); }

// conta qtde de componentes conexas
int numCC ()
{
  register int i, j, f, cc = 0;
  vis.assign(p.size(), 0);

  for (i = 0, j = p.size(); i < j; ++i)
    if (used[i])
    {
      f = find(i);
      if (!vis[f])
        vis[f] = 1, ++cc;                               // 2 linhas em 1!!!
    }

  return cc;
}

// qtde de vertices usados
int usedQtd ()
{
  register int i = used.size(), qtd = 0;
  while (i)
    if (used[--i])
      ++qtd;
  return qtd;
}

// kruskal (mod)
double kruskal ()
{
  sort(edge.begin(), edge.end());                     // ordena pelo peso

  cost = 0.0;                                         // custo mínimo
  for (i = 0, j = edge.size(), k = s; i < j; ++i)     // varia arestas
  {
    v = edge[i];                                      // pega aresta
    if (!isUnion(v.second.first, v.second.second))
    {
      cost = v.first;                                 // é o menor custo possível
      unionSet(v.second.first, v.second.second);

      qtd = usedQtd();                                // qtde de usados
      cc = numCC();                                   // nº de componentes conexos

      if ((qtd == l && cc <= k) || qtd + k - cc == l)
        break;                      // usou todos e não ultrapassa nº de satelites
    }                           // ou se conectar os restantes via satelite resolve
  }

  return cost;
}

int main()
{
  scanf("%d", &n);
  while (n--)
  {
    scanf("%d%d", &s, &l);
    edge.resize(0);                                     // limpa arestas
    p.resize(l);                                        // vetor de 'pais'
    used.assign(l, 0);                                  // vetor de usados

    for (i = l; --i >= 0; p[i] = i);                    // reseta p

    for (i = 0, j = l; i < j; ++i)                      // leitura
    {
      scanf("%d%d", &coord[i].first, &coord[i].second);

      // adiciona arestas com distância entre todos os outros pontos
      for (k = 0; k < i; ++k)
        edge.push_back(dii(dist(coord[i], coord[k]), ii(i, k)));
    }

    printf("%.2lf\n", kruskal());
  }

  return 0;
}
