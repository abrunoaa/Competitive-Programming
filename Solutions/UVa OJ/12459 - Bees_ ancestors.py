fib = [1, 1]
for i in range(2, 81):
  fib.append(fib[i - 1] + fib[i - 2])

while True:
  n = int(input())
  if n == 0:
    break
  print (fib[n])
