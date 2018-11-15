while True:
    try: s = raw_input()
    except:break;exit()
    n = len(s)
    d = {}
    MOD = 4084061
    prod = 1
    k  = 26
    hashs,hasht,count = 0,0,0
    max = 0
    for i in range(n-1,-1,-1):
        hashs*=k
        hashs+=ord(s[i])-97
        hashs%=MOD
        hasht+=(ord(s[i])-97)*prod
        hasht%=MOD
        if hashs==hasht:max = n-i
        prod*=k
    count  = max
    print s[:n-count]+s[n-count:]+s[:n-count][::-1]
