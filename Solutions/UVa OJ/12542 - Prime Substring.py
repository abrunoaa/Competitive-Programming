maxn = 100010
isp = [i >= 2 for i in range(0, maxn)]
primes = []

for i in range(2, maxn):
  if isp[i]:
    primes.append(str(i))
    j = i * i
    while j < maxn:
      isp[j] = False
      j += i

primes = primes[::-1]

while True:
  n = input()
  if int(n) == 0:
    break

  for x in primes:
    if n.find(x) != -1:
      print (x)
      break
