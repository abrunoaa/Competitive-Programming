table = [[chr((i + j) % 26 + 97) for j in range(26)] for i in range(26)]

key = [ord(c) - 97 for c in str(input())]
for i in range(int(input())):
  k = 0
  flag = False
  for s in input().split():
    if s[0] not in ('a', 'e', 'i', 'o', 'u'):
      t = str()
      for c in s:
        t += table[key[k]][ord(c) - 97]
        k = (k + 1) % len(key)
    else:
      t = s
    if flag:
      print('', t, end = '')
    else:
      flag = True
      print(t, end = '')
  print()
