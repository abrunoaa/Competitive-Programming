from fractions import gcd

for t in range(int(input())):
  a, b = map(int,input().split())

  g = a
  while a < b and g > 1:
    a += 1
    g = gcd(g, a)

  print(g)
