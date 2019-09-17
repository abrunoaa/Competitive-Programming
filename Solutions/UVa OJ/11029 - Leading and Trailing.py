from math import log10

for t in range(int(input())):
  n, k = map(int, input().split())
  x = k * log10(n)
  d = int(x) + 1
  print("{:03d}...{:03d}".format(int(pow(10, x - d + 3)), pow(n, k, 1000)))
