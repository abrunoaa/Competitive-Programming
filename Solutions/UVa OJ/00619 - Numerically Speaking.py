from sys import stdin

def gets(n):
  s = ''
  while n:
    m = n % 26
    n //= 26
    s += chr((m if m else 26) + 96)

  return s[::-1]

def getn(s):
  n = 0
  for c in s:
    n = 26 * n + ord(c) - 96
  return n

for line in stdin:
  line = line.split()[0]
  if line == '*':
    break

  try:
    n = int(line)
    s = gets(n)
  except ValueError:
    n = getn(line)
    s = line

  print (s + ' ' * (22 - len(s)) + '{:,}'.format(n))
