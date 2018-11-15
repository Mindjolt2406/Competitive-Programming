def recursion(arr,pos,length,finalarray,mini):
	for i in arr[pos:]:
		if(len(finalarray)==0):
        print "here"
		    # finalarray.append(i)
			  recursion(arr,pos+1,length,finalarray,mini)
			  # finalarray.pop()
		else:
			if(i>=finalarray[len(finalarray)-1]):
			  # finalarray.append(i)
				if(len(finalarray)==length):
					if(finalarray[len(finalarray)-1]<mini):
					    mini=finalarray[len(finalarray)-1]
				else:
				    recursion(arr,pos+1,length,finalarray,mini)
				finalarray.pop()
			
	
t=input()
for i in range(t):
    mini=1000001
    n=input()
    arr=[]
    arr = [int(x) for x in raw_input().split()]
    l=input()
    recursion(arr,0,l,[],mini)
    if(mini==1000001):
        print "-1"
    else:
        print mini