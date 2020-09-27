for t in range(int(input())):
  n = int(input())
  a = [tuple(map(float, input().split())) for i in range(n)]

  r = [1] * n
  for i in range(n):
    try:
      r[i] = max(r[j] for j in range(i) if a[j][0] < a[i][0] and a[j][1] > a[i][1]) + 1
    except ValueError:
      pass

  print(max(r))
