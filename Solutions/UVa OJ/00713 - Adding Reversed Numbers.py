def reverse(s):
  s = s[::-1]
  return s

T = int(input())
for i in range(0, T):

  line = input().split()
  n1 = int(reverse(line[0]))
  n2 = int(reverse(line[1]))
  print (int(reverse(str(n1 + n2))))
