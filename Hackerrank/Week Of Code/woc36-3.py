def printf(l): #. Prints the matrix
  for i in l:
    for j in i:
      print j,
    print ""
def rook(l,i,j): #It checks whether the squares between i,j are empty for a rook. This has been done for knight and bishop as well
  if i[0]==j[0]:
    for k in range(min(i[1],j[1])+1,max(i[1],j[1])):
      if l[i[0]][k]!="#":return False
    return True
  elif i[1]==j[1]:
    for k in range(min(i[0],j[0])+1,max(i[0],j[0])):
      if l[k][i[1]]!="#":return False
    return True

def knight(l,i,m):
  if (abs(i[0]-m[0])==2 and abs(i[1]-m[1])==1) or (abs(i[0]-m[0])==1 and abs(i[1]-m[1])==2):
    return True
  return False

def bishop(l,i,j):
  if abs(i[0]-j[0])==abs(i[1]-j[1]):
    boo = False
    if i[0]<j[0] and i[1]<j[1]:
      a,b = i[0],i[1]
      boo = False
      for k in range(1,j[0]-i[0]):
        if l[a+k][b+k]!="#":
          return False
      return True
    elif i[0]<j[0] and i[1]>j[1]:
      a,b = i[0],i[1]
      for k in range(1,j[0]-i[0]):
        if l[a+k][b-k]!="#":
          return False
      return True
    elif i[0]>j[0] and i[1]>j[1]:
      a,b = i[0],i[1]
      for k in range(1,i[0]-j[0]):
        if l[a-k][b-k]!="#":
          return False
      return True
    elif i[0]>j[0] and i[1]<j[1]:
      a,b = i[0],i[1]
      for k in range(1,i[0]-j[0]):
        if l[a-k][b+k]!="#":
          return False
      return True
  else:return False  


t = int(raw_input())

for h in range(t):
  l = []
  for i in range(8):
    l.append(list(raw_input()))
  kingpos = (0,0)
  mypos = []
  otherpos = []
  pawnpos = []
  for i in range(8):
    if l[1][i]=="P":
      if l[0][i]=="#":pawnpos.append((0,i))
  bool = True
  for i in range(8):
    for j in range(8):
      if l[i][j]=="k":#The position of K is needed so that if I move a pawn, my king shouldn't be checked
        m = (i,j)
      elif l[i][j]=="K":
        m1 = (i,j)
        t = ("K",m1[0],m1[1]) # However K is an obstacle otherwise, and must be treated as such
        otherpos.append(t)
      elif l[i][j] in "qnbrp":
        otherpos.append((l[i][j],i,j))
      elif l[i][j] in "QNBR":
        mypos.append((l[i][j],i,j))
  count = 0
  boo = False
  for i in mypos: # This loop, which I feel may be useless, checks the 'check' condition of my king beforehand
    if i[0]in "QR" and rook(l,i[1:],m):boo = True
    elif i[0] in "QB"and bishop(l,i[1:],m):boo = True
    elif i[0]=="K" and knight(l,i[1:],m):boo = True
  if boo:
    #print len(pawnpos)*4;continue
    print 0
    continue
  e = False
  for i in pawnpos: 
    '''This is the function for discovered checks. I first move the pawn forward, and check whether my king is under check or not. If it is, I leave. Otherwise, I check whether there is a check for the opponent's king. If there is, I'll add 4, as I can change ,y pawn to whatever I want to'''
    #print i
    l[i[0]+1][i[1]],l[i[0]][i[1]] = l[i[0]][i[1]],l[i[0]+1][i[1]]
    c = False
    d = False
    for j in otherpos:
      if j[0] in "qr" and rook(l,j[1:],m1):c = True
      elif j[0] in "qb" and bishop(l,j[1:],m1):c = True
      elif j[0] =="k" and knight(l,j[1:],m1): d = True
    if c:continue
    elif d:print 0;e = True;break
    for j in mypos:
      if j[0] in "QR" and rook(l,j[1:],m):count+=4
      elif j[0] in "QB" and bishop(l,j[1:],m):count+=4
      elif j[0] in "K" and knight(l,j[1:],m):count+=4
    l[i[0]+1][i[1]],l[i[0]][i[1]] = l[i[0]][i[1]],l[i[0]+1][i[1]]
  if e:continue
  for i in pawnpos:# These are the stratightforward checks, i.e. without any fancy stuff like distributed checks or illegal moves
    if rook(l,i,m):count+=2
    elif bishop(l,i,m):count+=2
    elif knight(l,i,m):count+=1
  print count
  
