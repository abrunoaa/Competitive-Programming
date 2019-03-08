n = int(input())
a = input().split()

ans = 1
last = -1
for i in range(n):
  x = int(a[i])
  if x == 1:
    if last != -1: ans *= i - last
    last = i

print(0 if last == -1 else ans)
