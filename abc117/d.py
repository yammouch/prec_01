n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

v = [0] * 41
for x in a:
  for i in range(41):
    v[i] += x & 1
    x >>= 1

max_acc = 0
max_bit = 0
for i in range(41):
  if (k >> i) & 1:
    max_acc = max( (1 << i)*(n-v[i]) + max_acc,
                   (1 << i)*   v[i]  + max_bit )
  else:
    max_acc += (1 << i)*v[i]
  max_bit += (1 << i)*max(v[i], n-v[i])

print(max_acc)
