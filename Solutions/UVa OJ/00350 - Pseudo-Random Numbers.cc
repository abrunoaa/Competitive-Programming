#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

/** Function Cycles: Encontra o ciclo em uma função f(x)
 * Encontra μ(início) e λ(tamanho) do ciclo de uma função em O(μ + λ) **/
typedef pair<int,int> ii;

ii floydCycle(int(*f)(int), int x0){
  int tortoise = f(x0), hare = f(f(x0));
  while(tortoise != hare){
    tortoise = f(tortoise);
    hare = f(f(hare));
  }

  int mu = 0;
  hare = x0;
  while(tortoise != hare){
    tortoise = f(tortoise);
    hare = f(hare);
    ++mu;
  }

  int lambda = 1;
  for(hare = f(tortoise); tortoise != hare; hare = f(hare))
    ++lambda;

  return ii(mu, lambda);
}

ii brentCycle(int(*f)(int), int x0){
  int mu = 0, lambda = 0, p = 1;

  int tortoise = x0, hare = f(x0);
  for(; tortoise != hare; hare = f(hare))
    if(++lambda == p){
      tortoise = hare;
      p *= 2;
      lambda = 0;
    }
  ++lambda;

  tortoise = hare = x0;
  for(int i = 0; i < lambda; ++i)
    hare = f(hare);
  while(tortoise != hare){
    tortoise = f(tortoise);
    hare = f(hare);
    ++mu;
  }

  return ii(mu, lambda);
}

int z, i, m, l;

int f(int x){ return (z * x + i) % m; }

int main(){
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  for(int t = 1; cin >> z >> i >> m >> l, z || i || m || l; ++t){
    ii ans = brentCycle(f, l);
    cout << "Case " << t << ": " << ans.second << '\n';
  }

  return 0;
}
