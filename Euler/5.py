def gcd(a,b):
    while b:
        a,b = b,a%b
    return a
def lcm(a,b):
    return a*b/gcd(a,b)
prod = 1
g = 2
for i in range(2,11):
    g = lcm(i,g)
print g
