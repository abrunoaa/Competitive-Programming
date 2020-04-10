for _ in range(int(input())):
  n = int(input())
  t = list(map(int, input().split()))
  if len(set(t)) == 1:
    c = [1] * n
  elif n % 2 == 0:
    c = [1, 2] * (n // 2)
  else:
    try:
      s = next(i for i in range(n) if t[i] == t[(i + 1) % n]) + 1
      c = [1, 2] * (s // 2) + [2 if s % 2 == 0 else 1] + [1, 2] * ((n - s) // 2)
    except StopIteration:
      c = [1, 2] * (n // 2) + [3]
  print(max(c))
  print(' '.join('{}'.format(x) for x in c))
