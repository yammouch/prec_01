x = int(input())

table10r = [0, 1, 2, -2, -1, 0, 1, 2, -2, -1]
table5r  = [0, 1, 0, 1, 0, 1, 0, -1, 0, -1]

acc = 0

for i in range(4):
  ####
  #q = x // 10
  q = x // 5
  r = x % 10
  r5 = x % 5

  if 3 <= r5:
    q += 1

  #print(x, table10r[r])
  acc += abs(table10r[r])
  x = q

  ####
  #q = x // 10
  if (i < 3):
    q = x // 2
    r = x % 10

    if r == 7 or r == 9:
      q += 1
    #if 6 <= r:
    #  q += 1
    #if 9 <= r:
    #  q += 5
    #elif 7 <= r:
    #  q += 4
    #elif 6 <= r:
    #  q += 3
    #elif 4 <= r:
    #  q += 2
    #elif 2 <= r:
    #  q += 1
    acc += abs(table5r[r])
    #print(x, table5r[r])
    x = q


print(acc)
