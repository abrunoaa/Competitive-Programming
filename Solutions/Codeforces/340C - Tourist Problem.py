from fractions import gcd

n = int(input())
a = sorted([int(x) for x in input().split()])

ans = 0
l = 0
for i in range(n):
  ans += i * a[i] - l
  l += a[i]

ans = sum(a) + 2 * ans
g = gcd(ans, n)

print(ans // g, n // g)
