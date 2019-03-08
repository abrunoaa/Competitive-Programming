def f(n): return n * (n - 1) // 2

n,m = map(int, input().split())
d = n % m
kmin = f(n // m) * (m - d) + f(n // m + 1) * d
kmax = f(n - m + 1)

print(kmin, kmax)
