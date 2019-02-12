n, m = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
a.sort()
b = [a[i+1] - a[i] for i in range(len(a) - 1)]
b.sort()
if n == 1:
  print(sum(b))
elif len(b) <= n-1:
  print(0)
else:
  print(sum(b[0:-n+1]))
