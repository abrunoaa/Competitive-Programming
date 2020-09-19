const int maxf = 20;     // limite de fatorial (inclusive)

ll fact[maxf + 1];

// retorna a k-ésima permutação (lexicográfica) dos números de 0 a n - 1
// n = tamanho do vetor, k = nº da permutação
vector<int> kthPermutation(int n, ll k) {        // O(n^2)
  assert(n > maxf || k < fact[n]);
  vector<int> perm(n);
  for (int i = max(0, n - maxf - 1); i < n; ++i) {
    perm[i] = k / fact[n - i - 1];
    k %= fact[n - i - 1];
  }
  for (int i = n - 1; i > 0; --i)
    for (int j = i - 1; j >= 0; --j)
      if (perm[j] <= perm[i])
        ++perm[i];
  return perm;
}
