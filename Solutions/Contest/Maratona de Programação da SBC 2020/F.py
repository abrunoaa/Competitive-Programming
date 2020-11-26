s = 0
p = [0, 0]
g = [0, 0]
done = 0
winner = "error!"
for c in input():
  if c == 'Q':
    if done:
      print(winner)
    else:
      ch = ["*", ""] if s == 0 else ["", "*"]
      print("{} ({}{}) - {} ({}{})".format(g[0], p[0], ch[0], g[1], p[1], ch[1]))
  elif not done:
    if c == 'R':
      s ^= 1
    p[s] += 1
    if p[s] == 10 or p[s] >= 5 and abs(p[0] - p[1]) >= 2:
      g[s] += 1
      p = [0, 0]
    if max(g) == 2:
      done = 1
      winner = ("{} (winner) - {}" if g[0] > g[1] else "{} - {} (winner)").format(g[0], g[1])
