# from math import *

t = int(raw_input())
MOD = 8589934592
for h in range(1,t+1):
  n = long(raw_input())
  print "Case "+str(h)+":",(pow(2,n,MOD) - 1 + MOD) % MOD