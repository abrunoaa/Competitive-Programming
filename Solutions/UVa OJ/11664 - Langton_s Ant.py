X = [-1, 0, 1, 0]
Y = [0, 1, 0, -1]

while True:
  n,c,x,y = map(int, input().split())
  if not(n or c or x or y):
    break

  mat = [ [0 for i in range(0, n)] for j in range(0, n) ]
  for i in range(0, n):
    for j in reversed(range(0, n)):
      mat[i][j] = c & 1
      c >>= 1

  # x,y de c nao da matriz!
  b = y
  y = x - 1
  x = n - b
  d = 0
  while True:
    if x < 0 or y < 0 or x >= n or y >= n or (x == 0 and y == n - 1):
      break
    if mat[x][y] == 0:
      d = (d - 1 + 4) % 4
    else:
      d = (d + 1) % 4

    mat[x][y] ^= 1
    x += X[d]
    y += Y[d]

  print ('Yes' if x == 0 and y == n - 1 else 'Kaputt!')
