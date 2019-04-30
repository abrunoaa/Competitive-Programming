T = int(input())
for t in range(0, T):
  x,y,n = map(int, input().split())
  print (pow(x, y, n))
