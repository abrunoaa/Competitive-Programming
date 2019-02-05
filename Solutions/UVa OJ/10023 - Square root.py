def isqrt(n):
  x = n
  y = (x + 1) // 2
  while y < x:
    x = y
    y = (x + n // x) // 2
  return x

t = 0
T = int(input())
while t < T:
  try:
    print (isqrt(int(input())))
    t += 1
    if t < T:
      print ('\n', end = '')
  except ValueError:
    continue
