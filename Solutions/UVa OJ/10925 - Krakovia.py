cs = 0
while True:
  n,f = map(int, input().split())
  if n == 0 and f == 0:
    break
  s = 0
  for i in range(0, n):
    s += int(input())
  cs += 1
  print ('Bill #' + str(cs) + ' costs ' + str(s) + ': each friend should pay ' + str(s // f), end = '\n\n')
