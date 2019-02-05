n = int(input())
a = list(map(int, input().split()))

f = [0] * 102

ans = [0] * n
for i in range(n - 1, -1, -1):
  ans[i] = '*' if f[a[i]] == 0 else a[f[a[i]]]
  for j in range(1, a[i]):
    f[j] = i

print(ans[0], end = '')
for i in range(1, n):
  print('', ans[i], end = '')
print()
