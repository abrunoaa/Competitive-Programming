bitset<maxn> sf;  // square free
char npf[maxn];   // num (distinct) prime factors

int non_square_free(int n){             // O(sqrt(n))
  int ans = 0;
  for(int i = 2, lim = (int)(sqrt(n) + eps); i <= lim; ++i)
    if(sf[i])
      ans += n / (i * i) * (npf[i] % 2 ? 1 : -1);
  return ans;
}
