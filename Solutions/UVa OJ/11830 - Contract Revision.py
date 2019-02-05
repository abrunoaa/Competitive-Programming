while True:
  line = input().split()
  if int(line[0]) == 0 and int(line[1]) == 0:
    break
  n = line[1].replace(line[0], '')
  print (int(n) if len(n) else 0)
