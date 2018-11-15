''' Given an arithmetic expression as a string. To compute it's value '''
def solve(indexn,number,e):
    if d[e]==1:
       number[indexn-1]+=number.pop()
    elif  d[e]==2:
       number[indexn-1]-=number.pop()
    elif  d[e]==3:
       number[indexn-1]*=number.pop()
    elif  d[e]==4:
       number[indexn-1]/=number.pop()
    elif  d[e]==5:
       number[indexn-1]**=number.pop()
    elif d[e]==0:
        pass
    return number

s = raw_input()
s = "(" + s + ")"
d = {"+" : 1,"-" : 2,"*" : 3,"/" : 4,"(" : 0,")" : 0,"^":5}
index = -1
indexn = -1
number = []
stack = []
n = len(s)
i = 0

while i<n:
    #if indexn>-1:print number[indexn]
    #print stack,number,s[i]
    if 48<=ord(s[i])<=57:
        k = ''
        while 48<=ord(s[i])<=57 or s[i]==".":
            k+=s[i]
            i+=1
        number.append(float(k))
        indexn+=1
        continue
    elif s[i]==" ":
        i+=1
        continue
    else:
        if s[i]=="(": #Opening bracket
            stack.append(s[i])
            index+=1
        elif s[i]==")":
            while stack[index] !="(": # All operations will be in increasing order of precedence, so keep operating until you get the '('
                e = stack.pop()
                number = solve(indexn,number,e)
                index-=1
                indexn-=1
            stack.pop() #Remove the '(' out
            index-=1
        elif d[s[i]]>d[stack[index]]: #If the operator precedence is higher than that of its predecessor
            stack.append(s[i])
            index+=1
        elif d[s[i]]<=d[stack[index]]: #If it's not, don't add it until it is 
            while index>=0 and d[s[i]]<=d[stack[index]]:
                e = stack.pop()
                number = solve(indexn,number,e)
                indexn-=1
                index-=1
            stack.append(s[i])
            index+=1
    #print s[i]
    i+=1
print number[indexn]

