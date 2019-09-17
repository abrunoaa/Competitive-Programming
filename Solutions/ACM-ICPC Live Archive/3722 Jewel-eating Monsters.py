def rem(x, y, m):
  return x % (y * m) // y

while True:
  x, a, n, c = map(int, input().split())
  if x == 0 and a == 0 and n == 0 and c == 0:
    break
  print((pow(a, n, c) * x % c - (pow(a, n + 1, (a - 1) * c) - 1) // (a - 1) + 1 + c) % c)
