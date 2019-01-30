from __future__ import print_function
import sys

n = int(sys.stdin.readline())

acc = ''
la = 0

for i in range(n):
  rd = sys.stdin.readline()
  rd = rd[:-1]
  lr = len(rd)
  for j in range(min(lr, la), -1, -1):
    if all([acc[la-j+k] == rd[k] for k in range(0, j)]):
      break
  acc += rd[j:]
  la += lr - j

print(acc)
