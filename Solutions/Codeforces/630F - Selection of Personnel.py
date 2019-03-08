from math import factorial as f
def C(n,k): return f(n) // f(n - k) // f(k)
n = int(input())
print(C(n,5) + C(n,6) + C(n,7))
