def countSetBits(n): 
    count = 0
    while (n): 
        n &= (n - 1) 
        count = count + 1
      
    return count 

t = int(input())
while t :
    a,b = map(int,input().split())
    c=0
    for i in range(a,b+1):
        c += countSetBits(i)
    
    print(c)    
    t = t-1
