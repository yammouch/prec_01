s = input()

acc = 0

for i in range(len(s)):
  if s[i] != 'W':
    break

for j in range(i, len(s)):
  if s[j] == 'W':
    acc += j - i
    i += 1

print(acc)
