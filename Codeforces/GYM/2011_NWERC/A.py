from math import *
N = int(1.1e4)
d = {}

def nC2(k):
    n = (1 + sqrt(8*k+1))/2

    n = int(n)
    if((n * (n-1))/2 == k):
        return n
    else: 
        return -1

def nC3(n):
    return (n * (n-1) * (n-2))/6


def precompute():
    global d
    for i in range(4, N+1):
        prod = 1
        for j in range(1, int(i/2) + 1):
            prod *= (i -j + 1)
            prod /= j
            if(j >= 4):
                if(prod not in d):
                    d[prod] = [(i, j)]
                else:
                    d[prod].append((i, j))

            if(prod > 1e16): break

    
    for i in range(4, int(2e5)):
        k = nC3(i)
        if(k in d):
            d[k].append((i, 3))
        else: 
            d[k] = [(i, 3)]
    # print(d)

def solve():
    k = int(input())

    l = []
    if(k in d):
        l = d[k]

    r2 = nC2(k)
    if(r2 != -1):
        l.append((r2, 2))
    
    l.append((k, 1))

    m = []
    for i in l:
        m.append((i[0], i[0] - i[1]))
    
    for i in m:
        l.append(i)

    l = list(set(l))
    l.sort()

    print(len(l))
    for i in l:
        print("(" + str(i[0]) + "," + str(i[1]) + ")", end = " ")
    print("")


precompute()
t = int(input())
for h in range(t):
    solve()