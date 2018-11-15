#Since the substrings may not be distinct, we don't need to count the number of times the subtring occurs in the string. Therefore, store {substring:no. of occurences}
def find(b,s):
      #b is substring in the list, s is the actual substring
        k = b[0]
          count=0
            for i in range(len(s)-len(k)+1):
                    if s[i]==k:
                              #print s[i:i+len(b)],b
                                    if s[i:i+len(b)]==b:
                                                count+=1
                                                  #return count  
                                                    d[b] = count
                                                    n = int(raw_input())
                                                    m = raw_input().split()
                                                    l = [int(x) for x in raw_input().split()]
                                                    t = int(raw_input())
                                                    res = [] #The list where all the values are appended. The max and min will be taken from here. 
                                                    max,min = 0,max(l)*n
                                                    for h in range(t):
                                                          d = {}
                                                            count = 0
                                                              z = [x for x in raw_input().split()]
                                                                i,j,s = int(z[0]),int(z[1]),z[2]
                                                                  #c = m[i:j+1]
                                                                    #e = l[i:j+1]
                                                                      for g in range(i,j+1):#For every substring located in the given list
                                                                              q = m[g] in s
                                                                                  if m[g] in d and q:
                                                                                            count+=d[m[g]]*l[g]
                                                                                                  #print d[c[i]]*e[i],"product"
                                                                                                      elif q:
                                                                                                                find(m[g],s)
                                                                                                                      count+=d[m[g]]*l[g]
                                                                                                                          #count+=find(c[i],s)*e[i]
                                                                                                                                #print d[m[g]]*l[g],"product"
                                                                                                                                  if count<min:
                                                                                                                                          min = count
                                                                                                                                            if count>max:
                                                                                                                                                    max = count
                                                                                                                                                      #print d,
                                                                                                                                                      print min,max
                                                                                                                                                        
