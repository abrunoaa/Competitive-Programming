from math import sqrt

def win(n):
  return 'Yes' if n == (int(sqrt(n)) ** 2) else 'No'

T = int(input())
for t in range(1, T+1):
  print ('Case %d:' % t, win(int(input())))
