n,k = map(int,input().split())
mod = 10 ** 9 + 7
print(pow(k, k - 1, mod) * pow(n - k, n - k, mod) % mod)
