from __future__ import print_function
import sys

hf, wf, n = [int(s) for s in sys.stdin.readline().split()]

outfield = [[0] * wf for _ in range(hf)]

for i in range(1, n+1):
  h, w, r, c = [int(s) for s in sys.stdin.readline().split()]

  if   r == 0   and h <  hf and w <= wf:
    for y, x in [(y, x) for y in range(1, h+1) for x in range(   w  )]:
      outfield[y][x] = i
    break
  elif r == h-1 and h <  hf and w <= wf:
    for y, x in [(y, x) for y in range(   h  ) for x in range(   w  )]:
      outfield[y][x] = i
    break
  elif c == 0   and h <= hf and w <  wf:
    for y, x in [(y, x) for y in range(   h  ) for x in range(1, w+1)]:
      outfield[y][x] = i
    break
  elif c == w-1 and h <= hf and w <  wf:
    for y, x in [(y, x) for y in range(   h  ) for x in range(   w  )]:
      outfield[y][x] = i
    break

for row in outfield:
  print(' '.join([str(x) for x in row]))
