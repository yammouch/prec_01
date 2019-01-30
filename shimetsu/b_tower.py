from __future__ import print_function
import sys

n = int(sys.stdin.readline())

acc = ''

for i in range(n):
  rd = sys.stdin.readline()
  rd = rd[:-1]
  k = 0
  for j in range(max(0, len(acc) - len(rd)), len(acc)):
    if acc[j] == rd[k]:
      k += 1
    else:
      k = 0
  acc += rd[k:]

print(acc)
