for t in range(int(input())):
  vote = [0 for i in range(1001)]
  for i in range(int(input())):
    vote[int(input())] += 1

  r = 1
  for i in range(1001):
    if vote[i] > vote[r]:
      r = i

  print(r)
