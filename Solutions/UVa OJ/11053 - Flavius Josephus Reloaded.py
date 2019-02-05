# gives TLE
def floydCycle(f, x0):
  tortoise = f(x0)
  hare = f(f(x0))

  while tortoise != hare:
    tortoise = f(tortoise)
    hare = f(f(hare))

  mu = 0
  hare = x0
  while tortoise != hare:
    tortoise = f(tortoise)
    hare = f(hare)
    mu += 1

  lamb = 1
  hare = f(tortoise)
  while tortoise != hare:
    hare = f(hare)
    lamb += 1

  return (mu, lamb)

def brentCycle(f, x0):
  lamb = 1
  p = 1
  tortoise = x0
  hare = f(x0)
  while tortoise != hare:
    if lamb == p:
      tortoise = hare
      p <<= 1
      lamb = 0
    lamb += 1
    hare = f(hare)

  mu = 0
  tortoise = hare = x0
  for i in range(lamb):
    hare = f(hare)
  while tortoise != hare:
    tortoise = f(tortoise)
    hare = f(hare)
    mu += 1

  return (mu, lamb)

# import sys
# sys.stdin = open('in','r')

try:
  while True:
    n,a,b = map(int, input().split())
    print(n - brentCycle(lambda x : (a * x ** 2 + b) % n, 0)[1])

    # floydCycle: judge = TLE
    # print(n - floydCycle(lambda x : (a * x ** 2 + b) % n, 0)[1])

except ValueError:
  exit(0)
