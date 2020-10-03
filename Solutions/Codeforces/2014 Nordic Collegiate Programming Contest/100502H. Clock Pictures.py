n = int(input())
a = sorted(list(map(int, input().split())))
b = sorted(list(map(int, input().split())))
b += [x + 360000 for x in b]

for i in range(n - 1, 0, -1):
  a[i] -= a[i - 1]
for i in range(2 * n - 1, 0, -1):
  b[i] -= b[i - 1]
del a[0]
del b[0]
#  print(a, b)

p = [-1 for i in range(len(a) + 1)]
j = -1
for i in range(len(a)):
  while j >= 0 and a[i] != a[j]:
    j = p[j]
  j += 1
  p[i + 1] = j

j = 0
for i in range(len(b)):
  while j >= 0 and b[i] != a[j]:
    j = p[j]
  j += 1
  if j == len(a):
    print('possible')
    exit(0)

print('impossible')

#  3
#  0 270000 300000
#  180000 210000 270000
