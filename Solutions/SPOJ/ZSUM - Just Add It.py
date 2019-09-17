mod = 10000007
while True:
  n, k = map(int, input().split())
  if n == 0 and k == 0:
    break
  print((2 * (pow(n - 1, k, mod) + pow(n - 1, n - 1, mod)) + pow(n, k, mod) + pow(n, n, mod)) % mod)
