for _ in range(int(input())):
  a, b = map(int, input().split())
  print(0 if a % b == 0 else b - a % b)
