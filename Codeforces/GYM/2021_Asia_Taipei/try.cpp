N <= 16, K <= 200
1 1 2 2 9 9 % K = maxMod -> highest permutation which gives you maxMod

N <= 9 or 10

DP + Bitmasking

1 2 3 4

12 -> 10 M. (M * 10 + newDigit) % K -> newMod
21 -> 10 104  

Hackerearth -> Hamiltonian Cycle

4123

32145 -> 5.... 

dp[subset][mod] true / false -> mask you can make mod 

dp[mask][mod] = dp[submask][newMod]

dp[2^n - 1][maxMod]

[1, 100] [4, 40] [3, 4000]


Matrix -> n x m <= 40 x 40
Cell -> height of a mountain
Xs, Ys -> cell which has 0.
G <= 10
Each guard guards at most 8 cells. 0, 3, 5, 7

3 3 3
0 1 2
  1

(i, j) -> (i - 1, j)
       -> (i, j - 1)

Cycle of guards = LCM of all their cycles = K
3 5 7 8 ->  (i, j, timestamp % K)
