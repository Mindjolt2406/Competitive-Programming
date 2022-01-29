Length -> K
A_i <= N

A[i + 1] % A[i] == 0

Array i, last element -> j
f(i, j)

sum f(k, m) m goes from 1 to n

f(i, j) = sum over all j' f(i - 1, j') check whether j % j' == 0 

f(i, j') -> f(i + 1, j) such that j is a multiple of j'


Arr k, 1 <= last element <= n

n + n / 2 + n / 3 + n / 4 + n / 5 + n / 6 + n / 7 + n / 8.... + 1 == nlogn
n + n / 2 + n / 2 + n / 4 + n / 4 + n / 4 + n / 4 + n / 8
n + n + n ...  