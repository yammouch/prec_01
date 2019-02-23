def gcd(a, b):
  if a < b:
    tmp = b
    b = a
    a = tmp
  while b != 0:
    tmp = a % b
    a = b
    b = tmp
  return a

n, m = [int(x) for x in input().split()]
s, t = [input() for _ in range(2)]

d = gcd(n, m)

nd = n // d
md = m // d

if all(s[nd*i] == t[md*i] for i in range(d)):
  print(n*m//d)
else:
  print(-1)
