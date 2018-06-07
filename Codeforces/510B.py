import copy
import sys
sys.setrecursionlimit(10000)
def recur(l,i,j,a,b,n,m,boo,c):
  print n,m
  if i>=n or j>=m or i<0 or j<0:return 0;
  if i==a and j==b and boo>3:return 1;
  if l[i][j] == "*":return 0;
  if l[i][j]==c:
    #printf(l)
    l[i][j]="*"
    if recur(l,i+1,j,a,b,n,m,boo+1,c):return 1
    elif recur(l,i,j+1,a,b,n,m,boo+1,c):return 1
    elif recur(l,i,j-1,a,b,n,m,boo+1,c):return 1
    elif recur(l,i-1,j,a,b,n,m,boo+1,c):return 1
  return 0;

def printf(l):
  for i in l:
    for j in i:
      print j,
    print ""
  print ""

n,m = map(int,raw_input().split())
l = []
e = []

for i in range(n):
  l.append(list(raw_input()))
e = copy.deepcopy(l)
for i in range(n):
  for j in range(m):
    c = l[i][j]
    l = copy.deepcopy(e)
    boo = recur(l,i,j,i,j,n,m,1,c)
    if boo:print "Yes";exit();
print "No"
