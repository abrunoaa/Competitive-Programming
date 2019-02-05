#include <bits/stdc++.h>
using namespace std;

#define maxf 20     // limit for factorial (inclusive)

typedef long long ll;
typedef vector<int> vi;

ll fact[maxf + 1];

// retorna a k-ésima permutação (lexicográfica) dos números de 0 a n - 1
// n = tamanho do vetor, k = nº da permutação
vi kthPermutation(int n, ll k){         // O(n^2)
  assert(n > maxf || k < fact[n]);
  vi perm(n);

  for(int i = max(0, n - maxf - 1); i < n; ++i){
    perm[i] = k / fact[n - i - 1];
    k %= fact[n - i - 1];
  }

  for(int i = n - 1; i > 0; --i)
    for(int j = i - 1; j >= 0; --j)
       if(perm[j] <= perm[i])
          ++perm[i];

  return perm;
}

int main(){
  fact[0] = 1;
  for(int i = 1; i <= maxf; ++i){
    fact[i] = i * fact[i - 1];
  }

  return 0;
}
