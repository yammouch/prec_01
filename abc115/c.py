n, k = [int(x) for x in input().split()]
hs = []
for _ in range(n):
  hs.append(int(input()))
hs.sort()

min_diff = 10**9 + 1

for i in range(n - k + 1):
  x = hs[i+k-1] - hs[i]
  if x < min_diff:
    min_diff = x

print(min_diff)
