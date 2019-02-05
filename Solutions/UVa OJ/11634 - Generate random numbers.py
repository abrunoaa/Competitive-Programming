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

def f(x):
  return (x ** 2 // 100) % 10000

while True:
  a0 = int(input())
  if a0 == 0:
    break

  # print(sum(floydCycle(f, a0)))
  print(sum(brentCycle(f, a0)))
