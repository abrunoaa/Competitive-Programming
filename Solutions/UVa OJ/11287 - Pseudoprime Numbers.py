maxn = 32000
isp = [i >= 2 for i in range(0, maxn)]
primes = []

for i in range(2, maxn):
  if isp[i]:
    primes.append(i)
    j = i * i
    while j < maxn:
      isp[j] = False
      j += i

def isprime(n):
  if n < maxn:
    return isp[n]

  for p in primes:
    if p * p > n:
      return True
    if n % p == 0:
      return False
  return True

while True:
  p,a = map(int, input().split())
  if p == 0 and a == 0:
    break
  print ('yes' if not isprime(p) and pow(a, p, p) == a else 'no')
