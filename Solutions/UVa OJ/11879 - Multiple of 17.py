while True:
  n = int(input())
  if n == 0:
    break
  print (int(n >= 10 and (n // 10 - 5 * (n % 10)) % 17 == 0))
