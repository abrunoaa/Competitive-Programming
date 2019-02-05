from math import factorial

def func(n):

  print (n)
  func(n + 1)

  return

k=0
print(k)
func(0)

while True:
  try:
    c = str(factorial(int(input())))
    s = 0
    for x in c:
      s += int(x)
    print (s)
  except EOFError:
    break
