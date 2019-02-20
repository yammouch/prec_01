import heapq

n, k = [int(x) for x in input().split()]

data = [[int(x) for x in input().split()] for _ in range(n)]
data.sort(reverse=True, key=lambda x: x[1])

eat = {}
noeat = {}

for x in data[0:k]:
  if x[0] in eat:
    heapq.heappush(eat[x[0]], x[1])
  else:
    eat[x[0]] = [x[1]]

for x in data[k:]:
  if x[0] in noeat:
    heapq.heappush(noeat[x[0]], -x[1])
  else:
    noeat[x[0]] = [-x[1]]

max_score = 0

while True:
  #print(eat)
  #print(noeat)
  score = 0
  for x in eat:
    score += sum(eat[x])
  score += len(eat)**2
  if max_score < score:
    max_score = score
  remove = None
  min_score1 = 10**12+1
  for x in eat:
    if 1 < len(eat[x]) and eat[x][0] < min_score1:
      remove = x
      min_score1 = eat[x][0]
  add = None
  max_score1 = 0
  for x in noeat:
    if max_score1 < -noeat[x][0] and not(x in eat):
      add = x
      max_score1 = -noeat[x][0]
  if remove == None or add == None:
    break
  else:
    eat[add] = [max_score1]
    heapq.heappop(eat[remove])
    if 1 < len(noeat[add]):
      heapq.heappop(noeat[add])
    else:
      noeat.pop(add)

print(max_score)
