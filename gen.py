import random
import sys


len = int(sys.argv[1])
list = random.sample(range(-2147483648, 2147483647), len)

result = str(list)
print(*list, sep=' ')