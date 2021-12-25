n, k = map(int, input().split())
v = list(map(int, input().split()))
prefMap = {}
prefMap[0] = 1

prefSum = 0
countK = 0
for i in range(n):
    prefSum += v[i]
    if (prefSum - k) in prefMap:
        countK += prefMap[prefSum - k]

    if prefSum in prefMap:    
        prefMap[prefSum] += 1
    else:
        prefMap[prefSum] = 1

print(countK)