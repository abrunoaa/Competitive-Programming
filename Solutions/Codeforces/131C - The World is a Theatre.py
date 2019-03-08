from math import factorial as f
def C(n, k): return f(n) // (f(n - k) * f(k)) if n >= k else 0

n,m,t = map(int, input().split())
ans = 0
for i in range(4, t): ans += C(n, i) * C(m, t - i)

print(ans)
