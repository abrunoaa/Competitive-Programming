import calendar

v = [ 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 ]

def weekday(d, m, y):
  y -= m < 3
  return (y + y // 4 - y // 100 + y // 400 + v[m - 1] + d + 6) % 7

try:
  while True:
    s = input().split()
    d = int(s[0])
    m = list(calendar.month_name).index(s[1])
    y = int(s[2])
    print(calendar.day_name[weekday(d, m, y)])
except EOFError:
  exit
