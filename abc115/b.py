n = int(input())

max_price = 0
sum_price = 0

for _ in range(n):
  p = int(input())
  if max_price < p:
    max_price = p
  sum_price += p

print(sum_price - max_price // 2)
