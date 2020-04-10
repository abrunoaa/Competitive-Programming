from math import ceil, sqrt

for _ in range(int(input())):
  n, k = map(int, input().split())
  i = int(ceil((-1 + sqrt(8 * k + 1)) / 2))
  k -= i * (i - 1) // 2 + 1
  print('a' * (n - i - 1) + 'b' + 'a' * (i - k - 1) + 'b' + 'a' * k)
