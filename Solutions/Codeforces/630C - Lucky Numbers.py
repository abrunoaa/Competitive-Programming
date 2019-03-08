def f(n): return 2 if n == 1 else 2 ** n + f(n - 1)
print (f(int(input())))
