import sys

memo = [[-1 for i in range(0, 1001)] for j in range(0, 1001)]

sys.setrecursionlimit(1200)

def f(n, s):
  if s > n:
    return 0
  if s == n:
    return 1
  if memo[n][s] == -1:
    memo[n][s] = 2 * f(n, s + 1) + f(n, s + 2) + f(n, s + 3)
  return memo[n][s]

for n in sys.stdin:
  print (f(int(n), 0))
