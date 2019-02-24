x = int(input())

acc = 0

for a, b in [(250, 500), (50, 100), (25, 50), (5, 10), (3, 5)]:
  q = (x + a) // b
  x = x - q*b
  acc += abs(q)
  #print(q)

acc += abs(x)

print(acc)

#q = (x + 250) // 500
#x = x - q*500
#acc += q

#q = (x + 50) // 100
#x = x - q*100
#acc += q

#q = (x + 25) // 50
#x = x - q*50
#acc += q

#q = (x + 5) // 10
#x = x - q*10
#acc += q

#q = (x + 3) // 5
#x = x - q*5
#acc += q

