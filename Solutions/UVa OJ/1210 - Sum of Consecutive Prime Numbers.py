pr = []

def sieve(n):
  isp = [True for i in range(0, n)]
  for i in range(2, n):
    if isp[i]:
      pr.append(i)
      j = i * i
      while j < n:
        isp[j] = False
        j += i

sieve(10010)

while True:
  n = int(input())
  if n == 0:
    break

  i = 0
  j = -1
  ans = 0
  s = 0
  while True:
    if s == n:
      ans += 1
    if s < n:
      j += 1
      if j == len(pr):
        break
      s += pr[j]
    else:
      s -= pr[i]
      i += 1

  print (ans)
