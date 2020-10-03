def proc():
  a = list(map(int, input().split()))
  p = [0 for i in range(201)]
  for i in range(a[0], a[1] + 1):
    for j in range(a[2], a[3] + 1):
      p[i + j] += 1
  return p


a = proc()
b = proc()

win = sum(a[k] * sum(b[j] for j in range(k)) for k in range(201))
lose = sum(a[k] * sum(b[j] for j in range(k + 1, 201)) for k in range(201))

#  print(win, lose)
print('Tie' if win == lose else 'Gunnar' if win > lose else 'Emma')
