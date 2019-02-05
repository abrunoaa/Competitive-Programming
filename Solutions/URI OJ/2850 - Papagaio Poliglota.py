d = {'esquerda':'ingles', 'direita':'frances', 'nenhuma':'portugues', 'as duas':'caiu'}

try:
  while True:
    print(d[input()])
except EOFError:
  exit(0)
