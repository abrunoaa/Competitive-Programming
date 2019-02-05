from fractions import gcd

mod = 10**9 + 7
for t in range(int(input())):
  n, k = map(int, input().split())
  print('Case ' + str(t + 1) + ':', sum(pow(k, gcd(n, i), mod) for i in range(1, n + 1)) * pow(n, mod - 2, mod) % mod)
