from fractions import gcd

pair = 0
T = int(input())
for t in range(0, T):
  s1 = int(input(), 2)
  s2 = int(input(), 2)

  pair += 1
  print ('Pair #' + str(pair) + ': ' + ('All you need is love!' if gcd(s1,s2) > 1 else 'Love is not all you need!'))
