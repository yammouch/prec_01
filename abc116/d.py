n, k = [int(x) for x in input().split()]

data = {}

for _ in range(n):
  t, d = [int(x) for x in input().split()]
  if t in data:
    data[t].append(d)
  else:
    data[t] = [d]

for k in data:
  data[k].sort(reverse=True)
  for i in range(1, len(data[k])):
    data[k][i] += data[k][i-1]

ts = [k for k in dic]
ts.sort()
tmax = len(ts)

init_stack = [[tmax, k, i] for i in range(tmax, 0, -1)]
stack = init_stack[:]
memo = {}

while stack:
  if stack[-1] in memo:
    stack = stack[0:-1]
  elif any(x == 0 for x in stack[-1]):
    memo[stack[-1]] = 0
    stack = stack[0:-1]
  else:
    rt, rk, dt = stack[-1] # rest of type, rest of k, duty of type
    c0 = [[rt-1, i, dt-1] for i in
          range(dt-1, min(rk, len(data[ts[rt]]))+1)]
    c1 = [[rt-1, rk, dt-1]]
    if (not c0) and (not c1):
      stack = stack[0:-1]
    elif all(x in memo for c0 + c1):
      a = []
      for k in c0:
        a.append(memo[k] + ((rk - data[ts[k[1] - 1]]) if k[1] > 0 else 0))
      if not c1:
        a.append(memo[c1[0]])
      if a:
        memo[stack[-1]] = max(a)
      stack = stack[0:-1]
    else:
      stack = stack + c0 + c1

print(max([memo[k] + k[2]**2 for k in init_stack])
