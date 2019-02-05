from sys import stdin

maxn = 2 ** 16

# sieve
isprime = [i >= 2 for i in range(maxn)]
primes = []
for i in range(2, maxn):
  if isprime[i]:
    primes.append(i)
    j = i * i
    while j < maxn:
      isprime[j] = False
      j += i

def numDiv(n):
  div = 1
  for p in primes:
    if p * p > n:
      break
    if n % p == 0:
      e = 0
      while n % p == 0:
        n //= p
        e += 1
      div *= e + 1
  if n > 1:
    div *= 2
  return div

def totient(n):
  t = n
  for p in primes:
    if p * p > n:
      break
    if n % p == 0:
      t -= t // p
      while n % p == 0:
        n //= p
  if n > 1:
    t -= t // n
  return t

for n in stdin:
  n = int(n)

  # todos - (coprimos - exceto 1) - (divisores de n, pois gcd(n, div(n)) == div(n))
  print (n - (totient(n) - 1) - numDiv(n))
