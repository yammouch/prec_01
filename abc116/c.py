n = int(input())
h = [int(x) for x in input().split()]
h.append(0)

acc = 0
for i in range(len(h) - 1):
  acc += max(0, h[i] - h[i+1])

print(acc)
