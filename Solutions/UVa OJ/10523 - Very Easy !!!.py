import sys
for line in sys.stdin:
  n,a = " ".join(line.split()).split()
  n = int(n)
  a = int(a)

  ans = 0
  for i in range(1, n + 1):
    ans += i * a ** i

  print (ans)
