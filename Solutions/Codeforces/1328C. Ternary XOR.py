for _ in range(int(input())):
  n = int(input())
  x = input()
  i = 0
  a = ''
  b = ''
  for i in range(len(x)):
    if x[i] == '2':
      a += '1'
      b += '1'
    elif x[i] == '0':
      a += '0'
      b += '0'
    else:
      a += '1' + '0' * (n - i - 1)
      b += '0' + x[i + 1:]
      break
  print(a)
  print(b)

