for t in range(int(input())):
  n = int(input())
  p = 0
  k = 1
  while k <= n:
    p += k
    k *= 2
  print(n * (n + 1) // 2 - 2 * p)
