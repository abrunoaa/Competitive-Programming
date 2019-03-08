a,k = input(), int(input())
n,m = len(a), 10 ** 9 + 7

ans = 0
t = (pow(2, k * n, m) - 1) * pow(pow(2, n, m) - 1, m - 2, m) % m
for i in range(n - 1, -1, -1):
  if int(a[i]) % 5 == 0:
    ans = (ans + pow(2, i, m) * t) % m

print(ans)

# comentario