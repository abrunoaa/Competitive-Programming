from fractions import gcd

a,b,x,y = map(int, input().split())

g = gcd(x, y)
x //= g
y //= g
a = min(a, b * x // y)
b = min(b, a * y // x)

print(b // y)
