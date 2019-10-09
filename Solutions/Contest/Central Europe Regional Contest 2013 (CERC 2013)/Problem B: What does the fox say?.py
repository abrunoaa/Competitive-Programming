for t in range(int(input())):
  words = input().split()
  forbidden = set()
  while True:
    s = input().split()
    if len(s) != 3:
      break
    forbidden.add(s[2])
  print(" ".join(s for s in words if s not in forbidden))

