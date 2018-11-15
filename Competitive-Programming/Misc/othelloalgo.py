# True will be mapped to X and False to O
l = [["-" for x in range(8)] for y in range(8)] #Initialisation of the matrix
l[3][3],l[4][4],l[3][4],l[4][3]= "O","O","X","X"
bo = False #This variable signifies whose turn it is.
switch = lambda x: not x
def printf(l): #Prints the board
    ''' This function prints the matrix in a readable manner'''
    print " ",
    for i in range(8):
        print i,
    print
    k = 0
    for i in l:
        print k,
        for j in i:
            print j,
        print ""
        k+=1
def counter(l): # Counts the number of X's and O's
    ''' This function counts the number of X's and O's'''
    #Try to shorten
    countX,countO = 0,0
    for i in l:
        for j in i:
            if j=="X":
                countX+=1
            elif j=="O":
                countO+=1
    return [countX,countO]

def check(l,c): #This function returns a dictionary of coordinates of all the empty positions around X or O
    ''' This function returns a dictionary of coordinates of all the empty positions around X or O.
    The dictionary return type is of the form {(coordinates):[list of tuples of coordinates around
    it.]}'''
    m = []
    b=  []
    d = {}
    #Try to shorten the codes
    for i in range(8):
        for j in range(8):
            if l[i][j] == c:
                m.append((i,j))
    for i in m:
        x,y = i
        for j in range(-1,2):
            for k in range(-1,2):
                if j==0 and k==0:
                    continue
                elif x+j >7 or x+j<0 or y+k>7 or y+k<0:
                    continue
                elif l[x+j][y+k]!= "-":
                    continue
                elif (x,y) in d:
                    d[(x,y)].append((x+j,y+k))
                else:
                    d[(x,y)]=[(x+j,y+k)]
                    #print d
    return d

def checkValidity(l,k): 
    m = []
    if k: c = "X";e = "O"
    else: c = "O";e = "X"
    if e == "X":checkdict = check(l,c)
    else: checkdict = check(l,c)
    d = checkdict
    d1 = {}
    for i in d:
        '''For each possible sqaure around the coin, check if a move is valid.''' 
        for j in range(len(d[i])):
            count = 0 #This is the score of each move
            t = (i[0] - d[i][j][0],i[1] - d[i][j][1]) #This indicates the direction to move in
            if d[i][j] not in d1:
                d1[d[i][j]] = []
            k = recur(d[i][j],d[i][j],i,t,d1)
            if k[1]:
                l[d[i][j][0]][d[i][j][1]] = '+'
                d1.update(k[0])
    d2,count = {},0
    for i in d1:
        if d1[i]:
            d2[i] = d1[i]
            count+=1
    if count: return [d2,True]
    else: return [{},False]

def recur(first,old,t,dif,d1):
    ''' Old is the guy who undergoes recursion. first is the starting pint of the recursion(the square for whose validity is being checked.) d1 is the ditionary being passed repatedly to get updated. dif is the tuple of the direction co-ordinates. '''
    x,y = t #t is the coin around which we are trying to validate moves in 
    a,b = dif #Direction
    n,m = old 
    p,q = n+a,m+b #The new square
    if p>7 or p<0 or q>7 or q<0:
        return [{},False] #Subject to change
    elif l[p][q]=='+':
        return [d1,False]
    elif l[p][q]=='-':
        return [{},False] #Subject to change
    elif l[x][y]== l[p][q]:
        z =  recur(first,(p,q),t,dif,d1)
        if z[1]:
            if first in d1:
                d1[first].append((p,q))
            else:
                d1[first] = [(p,q)]
        return z
    elif (l[x][y]=='O' and l[p][q]=='X') or (l[x][y]=='X' and l[p][q]=='O'):
        return [d1,True] 

def change(l,c,d,t):
    ''' This function changes the blacks to whites and vice-versa. It also removes the markers for the available moves. '''
    m = d[t]
    x,y = t
    l[x][y] = c
    for i in m:
        x,y = i
        l[x][y] = c
    for i in range(8):
        for j in range(8):
            if l[i][j]=="+":
                l[i][j] = "-"
            elif l[i][j] =="#": l[i][j] = "X"
            elif l[i][j] == "0": l[i][j] = "O"


while True:
    #printf(l)
    if bo: c = "O"
    else: c = "X"
    b = checkValidity(l,bo)
    if b[1]:
        count=0
        dictionary = b[0]
    else:
        count+=1 
        if count==2:
            w= counter(l)
            print "    X :",w[0],
            print "O :",w[1]
            print "The game is over"
            break
        print("The type "+c+" has no valid moves. On to the next turn")
        switch(bo)
        continue
    w= counter(l)
    print "    X :",w[0],
    print "O :",w[1]
    printf(l)
    m = l[:][:]
    p = True
    while p:
        #inp = raw_input().split()
        #if len(inp)==1 and inp[0]=='u':
        #    l = m
        #    switch(bo)
        m = map(int,raw_input("Enter the co-ordinates of the coin of type "+c+" ").split())
        t = tuple(m)
        if t in dictionary: p = False
        else: print "The move isn't valid"
    #x,y = t
    change(l,c,dictionary,t)
    #if c == "X": l[x][y] = "#"
    #else: l[x][y] = "0"
    bo = switch(bo)
    #printf(l)
