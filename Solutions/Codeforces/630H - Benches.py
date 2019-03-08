from math import factorial as f

n = int(input())
print(f(n) ** 2 // 120 // f(n - 5) ** 2)
