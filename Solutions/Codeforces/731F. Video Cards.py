from bisect import bisect_left

n = int(input())
a = sorted(list(map(int, input().split())))
ans = 0
for k in set(a):
  r = sum(n - bisect_left(a, j) for j in range(k, a[-1] + 1, k))
  ans = max(ans, k * r)
print(ans)
