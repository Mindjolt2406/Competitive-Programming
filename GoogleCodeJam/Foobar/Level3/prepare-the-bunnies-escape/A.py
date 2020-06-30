from collections import deque

dx = [1,-1,0,0]
dy = [0,0,1,-1]

def check(i,j,n,m):
  if(i<0 or j<0 or i>=n or j>=m): return False
  return True

def bfs(l):
  n,m = len(l),len(l[0])
  vis = [[0]*m for i in range(n)]
  q = deque()

  q.append([0,0])
  vis[0][0] =  1
  q.append([-1,-1])
  dist = 0

  while(len(q)):
    u = q.popleft()
    # print u,q,len(q)
    if(u == [-1,-1]):
      dist+= 1
      if(len(q) == 0): break
      q.append([-1,-1])
      continue

    for k in range(4):
      p = [u[0]+dx[k],u[1]+dy[k]]
      if(p == [n-1,m-1]): return dist
      if(check(p[0],p[1],n,m) and l[p[0]][p[1]] == 0 and vis[p[0]][p[1]] == 0):
        vis[p[0]][p[1]] = 1
        q.append(p)
        
  return 10000

def printer(l,x):
  for i in l: 
    print(i)
  print("bfs: ",x)

def solution(l):
  min1 = 10000
  min1 = min(min1,bfs(l))
  # printer(l,bfs(l))

  for i in range(len(l)):
    for j in range(len(l[0])):
      if(l[i][j] == 1):  
        l[i][j] = 0
        min1 = min(min1,bfs(l))
        # printer(l,bfs(l))
        l[i][j] = 1

  return min1+2

if(__name__ == "__main__"):
  print(solution([[0, 1, 1, 0], [0, 0, 0, 1], [1, 1, 0, 0], [1, 1, 1, 0]]))
  print(solution([[0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 0], [0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0]]))