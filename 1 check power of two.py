import math

def log2(x):
    if x==0:
        return False
    return math.log10(x) / math.log10(2)


def ispower(n):
    return math.ceil(log2(n)) == math.floor(log2(n))

i = int(input())
if(ispower(i)):
    print("Yes")
else:
    print("No")
