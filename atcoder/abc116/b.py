s = int(input())
i = 1
d = set()
d.add(s)

while True:
  i += 1
  if s % 2:
    s = 3*s + 1
  else:
    s = s // 2
  if s in d:
    print(i)
    break
  d.add(s)
