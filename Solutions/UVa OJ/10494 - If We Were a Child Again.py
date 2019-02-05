import sys

for line in sys.stdin:
  x,c,y = " ".join(line.split()).split(' ')

  x = int(x)
  y = int(y)
  if c == '/':
    print (x // y)
  else:
    print (x % y)
