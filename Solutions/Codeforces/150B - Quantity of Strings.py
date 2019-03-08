n,m,k = map(int, input().split())
mod = 1000000007

if k == 1 or k > n:
  ans = pow(m, n, mod)
elif k == n:
  ans = pow(m, (n + 1) // 2, mod)
elif k % 2 == 0:
  ans = m
else:
  ans = m * m

print(ans)
