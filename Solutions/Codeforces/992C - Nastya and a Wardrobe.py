x,k = map(int, input().split())
mod = 10 ** 9 + 7
print(0 if x == 0 else (x * pow(2, k + 1, mod) - pow(2, k, mod) + 1 + mod) % mod)
