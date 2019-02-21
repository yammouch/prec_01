s = input()
minv = 1000
for i in range(len(s)-2):
  x = int(s[i:i+3])
  d = abs(753 - x)
  if d < minv:
    minv = d
print(minv)
