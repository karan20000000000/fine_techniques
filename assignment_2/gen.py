import random

n = 1 << 4

print(n)

for i in range(n):
    print(random.randint(1, n), "", end = "")