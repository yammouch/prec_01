from __future__ import print_function
import sys

d = {'W': 2, 'D': 1, 'L': 0, '-': 0}

n = int(sys.stdin.readline())
i_max = -1
score_max = -1
detail_max = ""

for i in range(n):
  s = sys.stdin.readline()
  s = s[:-1]
  score = sum([d[c] for c in s])
  if score_max < score:
    i_max = i
    score_max = score
    detail_max = s

print(i_max+1, end=' ')
print(score_max, end=' ')
print(len([x for x in detail_max if x == 'W']), end=' ')
print(len([x for x in detail_max if x == 'D']), end=' ')
print(len([x for x in detail_max if x == 'L']))
