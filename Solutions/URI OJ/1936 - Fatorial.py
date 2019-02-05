f = [1] * 20

for i in range(1, 20):
  f[i] = i * f[i - 1]

n = int(input())

ans = 0
for k in range(19, 0, -1):
  while n >= f[k]:
    ans += 1
    n -= f[k]

print(ans)
