n = int(input())
c = [1 for i in range(n + 1)]
for i in range(2, n + 1):
  c[i] = c[i - 1] * 2 * i * (2 * i - 1) // (i * (i + 1))
print(sum(c[k] * c[n - k] for k in range(n + 1)))
