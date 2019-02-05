#include <bits/stdc++.h>
using namespace std;

/** retorna int(sqrt(n)) sem perder precisão **/
int isqrt(int n){
  int x = n, y = (n + 1) / 2;
  while(x > y){
    x = y;
    y = (x + n / x) / 2;
  }
  return x;
}

/** Square Free: Conta qtos nº não são divisíveis por nenhum x² **/
typedef long long ll;

#define maxn 10000010 // sqrt(maxn)

bitset<maxn> sf;  // square free < maxn
char ndpf[maxn];  // num distinct prime factors

void sieve(){       // O(n * lg lg n)
  sf.set();
  for(int i = 2; i < maxn; ++i)
    if(ndpf[i] == 0){
      for(int j = i; j < maxn; j += i)
        ++ndpf[j];
      if((ll)i * i < maxn)   // elimina os múltiplos de i² (x*i² não é square free)
        for(int k = i * i, j = k; j < maxn; j += k)
          sf[j] = 0;
    }
}

// qtd de números <= n que é divisível por um quadrado perfeito
ll nonSquareFree(ll n){     // O(sqrt(n))
  ll ans = 0;
  for(ll i = 2; i * i <= n; ++i)
    if(sf[i])
      ans += n / (i * i) * (ndpf[i] % 2 ? 1 : -1);
  return ans;
}

// qtd de números <= n que NÃO é divisível por um quadrado perfeito
ll squareFree(ll n){ return n - nonSquareFree(n); }

/** Odd Sigma: Conta qtos nº x <= n com sigma(x) = ímpar **/
ll oddSigma(ll n) { return (int)(sqrt(n) + 1e-9) + (int)(sqrt(n / 2) + 1e-9); }

/** Primitive Root: checa se r¹, r², ..., r^(p-1) são diferentes
 * (i.e. uma permutação de 1, 2, ..., p-1) (p deve ser primo) **/
bool primitiveRoot(int p, int r){       // O(factors) + [ndpf <= 10] * O(mpow)
  for(int f : factors(p - 1))           // factors(n) = fatores primos de n
    if(mpow(r, (p - 1) / f, p) == 1)
      return 0;
  return 1;
}

int main(){
  return 0;
}
