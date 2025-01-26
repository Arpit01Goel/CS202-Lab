import time

def fibb(n):
    a=0
    b=1
    c=1
    for i in range(n):
        a=b
        b=c
        c=a+b
    #a is now nth fibb
    # print(a)

def tim():
    st = time.time()
    for i in range(50):
        fibb(100)
    
    ed = time.time()
    return (ed-st)*1000
    
total_time = 0
for i in range(200):
    total_time+= tim()

total_time/=200
print(total_time)