n = int(input())
h = sorted(list(map(int, input().split())))
ans = min(n, max(h), min(h[i] + n - i - 1 for i in range(n)))
print(ans)
