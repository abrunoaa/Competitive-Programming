while True:
  n = int(input())
  if n == -1:
    break

  ans = 0
  last = 0
  for i in range(0, n):
    s,t = map(int, input().split())
    ans += s * (t - last)
    last = t

  print (ans, 'milhas')
