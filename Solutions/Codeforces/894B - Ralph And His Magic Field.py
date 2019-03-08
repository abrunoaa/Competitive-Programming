n,m,k = map(int, input().split())
print(0 if k == -1 and (n % 2) != (m % 2) else pow(2, (n - 1) * (m - 1), 10 ** 9 + 7))
