def impossible():
  print('impossible')
  exit(0)


c, n = map(int, input().split())
p = 0
for k in range(n):
  x, y, z = map(int, input().split())
  if min(x, y, z) < 0:
    impossible()

  p -= x
  if p < 0:
    impossible()

  p += y
  if p > c:
    impossible()

  if z > 0 and p != c:
    impossible()
  if z > 0 and k == n - 1:
    impossible()

if p > 0:
  impossible()
print('possible')
