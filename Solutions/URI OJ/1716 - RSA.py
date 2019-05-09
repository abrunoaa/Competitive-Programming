from math import sqrt

def findPrimes(n):
  for p in range(3, n, 2):
    if n % p == 0:
      return p, n // p

def phi(n):
  ans = n
  for p in range(2, n):
    if p * p > n:
      break
    if n % p == 0:
      ans -= ans // p
      while n % p == 0:
        n //= p
  if n > 1:
    ans -= ans // n
  return ans

n, e, c = map(int, input().split())
p, q = findPrimes(n)
totn = (p - 1) * (q - 1)
d = pow(e, phi(totn) - 1, totn)
print(pow(c, d, n))
