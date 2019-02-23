n, k = [int(x) for x in input().split()]
tops = {}
rest = []
for _ in range(n):
  t, s = [int(x) for x in input().split()]
  if t not in tops:
    tops[t] = s
  elif tops[t] < s: 
    rest.append(tops[t])
    tops[t] = s
  else:
    rest.append(s)
    
tops = [tops[k] for k in tops]
tops.sort(reverse=True)
for i in range(1, len(tops)):
  tops[i] += tops[i-1]
rest.sort(reverse=True)
for i in range(1, len(rest)):
  rest[i] += rest[i-1]

if len(tops) < k:
  i_rest = k - len(tops) - 1
  base = tops[-1] + rest[i_rest]
  max_score = base + len(tops)**2
else:
  i_rest = -1
  base = tops[k-1]
  max_score = base + k**2

i_rest += 1

for i in range(i_rest, min([len(rest), k])):
  base_old = base
  base = tops[k-i-2] + rest[i]
  if (base <= base_old):
    break
  score = base + (k-i-1)**2
  if max_score < score:
    max_score = score

print(max_score)
