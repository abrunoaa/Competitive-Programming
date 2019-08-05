#include <bits/stdc++.h>
using namespace std;

#define size(x) (ll)x.size()

typedef long long ll;
typedef pair<int, int> ii;

// https://wcipeg.com/wiki/Convex_hull_trick
struct lowerEnvelope {
  int p;
  vector<ll> m, b;

  // seta a 1ª melhor linha, que é 0, pois inicialmente qualquer linha pode ser a melhor
  lowerEnvelope () : p(0) {}

  /*
   * Checar se [1] ou [3] é sempre melhor que [2]:
   *
   * Usando a equação da reta,
   *    y = m1 * x + b1
   *    y = m2 * x + b2
   *
   * igualando as duas equações,
   *        m1 * x + b1 = m2 * x + b2
   *    m1 * x - m2 * x = b2 - b1
   *      (m1 - m2) * x = b2 - b1
   *                  x = (b2 - b1) / (m1 - m2)
   *
   * logo,
   *    X(interseção(l1, l2)) = (b2 - b1) / (m1 - m2)
   *    X(interseção(l1, l3)) = (b3 - b1) / (m1 - m3)
   *
   * Para [2] ser inútil, o x da nova linha ([3]) deve ser menor que o anterior, já que
   * o anterior é a melhor solução para todos os x' <= x. Portanto,
   *    (b3 - b1) / (m1 - m3) < (b2 - b1) / (m1 - m2)
   *
   * multiplicando cruzado para evitar a divisão,
   *    (b3 - b1) * (m1 - m2) < (b2 - b1) * (m1 - m3)
   */
  inline bool bad (int l1, int l2, int l3)
  { return (b[l3] - b[l1]) * (m[l1] - m[l2]) < (b[l2] - b[l1]) * (m[l1] - m[l3]); }

  // adiciona a linha y = mm * x + bb
  void add (ll mm, ll bb) {
    // adiciona no fim dos vetores
    m.push_back(mm), b.push_back(bb);

    // se a penúltima se tornar inútil entre as outras, remove ela
    // repete quantas vezes for necessário
    while (size(m) >= 3 && bad(size(m) - 3, size(m) - 2, size(m) - 1)) {
      m.erase(end(m) - 2), b.erase(end(b) - 2);
    }
  }

  // retorna o menor y possível da interseção com a reta em x
  ll query (ll x) {
    // se removeu a melhor opção da consulta anterior, a melhor agora é a última inserida
    if (p >= size(m)) { p = size(m) - 1; }

    // como as consultas não estão em ordem decrescente (estão ordenadas),
    // uma linha melhor que a atual deve estar à sua direita
    while (p < size(m) - 1 && m[p + 1] * x + b[p + 1] < m[p] * x + b[p]) { ++p; }

    // retorna o valor de y
    return m[p] * x + b[p];
  }
};

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, i, j;
  vector<ii> temp, r;
  lowerEnvelope h;

  // entrada dos dados dos retângulos
  cin >> n;
  temp.resize(n);
  for (i = 0; i < n; ++i) { cin >> temp[i].first >> temp[i].second; }

  // ordena pela largura e então pelo comprimento
  sort(begin(temp), end(temp));

  // remove os retângulos inúteis, i.e. os que estão dentro de outros
  r.reserve(n);
  for (i = 0; i < n; ++i) {
    // checa se o i-ésimo retângulo contém o(s) retângulo(s) anterior(es)
    // a largura do i-ésimo é maior (está ordenado): checa apenas o comprimento
    while (!r.empty() && r.back().second <= temp[i].second) { r.pop_back(); }

    // o i-ésimo não contém mais nenhum outro anterior: insere no novo vetor
    r.push_back(temp[i]);
  }

  n = size(r);  // atualiza qtde de retângulos

  // note que agora a largura estará estritamente crescente
  // e o comprimento estritamente decrescente
  // senão significa que os retângulos inúteis não foram removidos do vetor
  // portanto já podemos utilizar o convex hull
  // note que se os comprimentos não estiverem estritamente decrescente,
  // deverá ser usado um convex hull dinâmico, multiplicando a complexidade por O(lg n)

/// solução O(n²) + O(n lg n) = O(n²)
  // *** aparentemente uma solução com PD recebe WA ***
  /**
    vector<ll> custo(n + 1, 1e9);
    custo[0] = 0;
    for (i = 1; i <= n; ++i)
      for (j = 0; j < i; ++j)
        custo[i] = min(custo[i], r[i - 1].first * r[j].second + custo[j]);

    cout << custo.back() << '\n';
  */
  /*
   * Note que
   *    custo[i] = r[i - 1].first * r[j].second + custo[j]
   *
   * é equivalente a
   *    y = m * x + b
   *
   * e que o loop no qual ele está inserido está tentando minimizá-lo, escolhendo o j
   * apropriado. Ou seja, está fazendo em tempo linear exatamente o mesmo que o
   * convex hull pode fazer em tempo constante.
   */

  for (auto p : r) { cerr << p.first << ' ' << p.second << endl; }
  cerr << endl;

/// solução O(n) + O(n lg n) = O(n lg n), devido à ordenação
  h.add(r[0].second, 0);
  for (i = 1; i < n; ++i) {
    h.add(r[i].second, h.query(r[i - 1].first));
  }

  cout << h.query(r.back().first) << '\n';

  return 0;
}
