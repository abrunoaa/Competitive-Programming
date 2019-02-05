maxn = 2 ** 20 + 10

isprime = [i >= 2 for i in range(maxn)]
primes = []
for i in range(2, maxn):
  if isprime[i]:
    primes.append(i)
    j = i * i
    while j < maxn:
      isprime[j] = False
      j += i

def compositePrime(n):
  for p in primes:
    if p * p > n:
      break
    if n % p == 0:
      return isprime[n // p]
  return False

try:
  while True:
    ans = 0
    n = int(input())
    for x in map(int, input().split()):
      if compositePrime(x):
        ans += 1
    print (ans)
except EOFError:
  exit()
