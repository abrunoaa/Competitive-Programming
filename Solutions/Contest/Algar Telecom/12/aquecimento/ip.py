def f(s):
  return str(int(s, 2))

T = int(input())
for t in range(0, T):
  s = input()
  print (f(s[0:8]) + '.' + f(s[8:16]) + '.' + f(s[16:24]) + '.' + f(s[24:32]))
