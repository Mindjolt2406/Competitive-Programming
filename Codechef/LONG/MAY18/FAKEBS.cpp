// Question +Editorial below
#include<bits/stdc++.h>
#define pu push_back
#define m make_pair
using namespace std;

pair<string, vector< long long int > >binarysearch(long long int l[], long long int n, long long int i)
{
  long long int beg = 0, end = n-1;
  string s="";
  vector<long long int> v;
  while(beg<=end)
  {
    long long int mid = (beg+end)/2;
    if(l[mid]==i) break;
    else if(l[mid]<i) {beg = mid+1; s+="1";}
    else {end = mid -1; s+="0";}
    v.pu(mid);
  }
  return m(s,v);
}

long long int bsearch(long long int l[],long long int n,long long int key)
{
  long long int beg = 0, end = n-1;
  while(beg<=end)
  {
    long long int mid = (beg+end)/2;
    if(l[mid]==key) return mid;
    else if(l[mid]<key) {beg = mid+1;}
    else {end = mid -1;}
  }
}
pair <long long int,long long int> count(string s)
{
  long long int a=0,b=0;
  for(long long int i=0;i<s.size();i++)
  {
    if(s[i]=='0')a++;
    else b++;
  }
  return m(a,b);
}

int main()
{
  long long int t;
  scanf("%lld",&t);
  while(t--)
  {
    // Ultra precomputation
    long long int n,q;
    scanf("%lld %lld",&n,&q);
    long long int m[n];
    vector < pair < string, vector <long long int> > > v;
    for(long long int i=0;i<n;i++) m[i] = i;
    for(long long int i=0;i<n;i++) v.pu(binarysearch(m,n,i));
    // long long int* d = (long long int*)calloc(n,sizeof(long long int));
    // Check how many larger ( and smaller )
    // if large>= large in logn, check for small
    // Similarly for small
    // If any of the two conditions aren't true, it's impossible
    // If it's possible, for all logn values, if it's a 1, the value should be greater. If not swap, swapcount++
    // Similarly, if the node value is 0, the value should be smaller. If not, swap, swapcount++
    long long int l[n],c[n];
    map <long long int,long long int> d1,d;
    for(long long int i=0;i<n;i++) {scanf("%lld",&l[i]);d1[l[i]] = i;c[i] = l[i];} //cin>>l[i];
    sort(c,c+n);
    for(long long int i=0;i<n;i++)
    {
      long long int key1 = d1[l[i]];
      long long int key2 = bsearch(c,n,l[i]);
      pair<string,vector<long long int> > p1 = v[key1];
      pair<string,vector<long long int> > p2 = v[key2];
      string s = p1.first;
      pair<long long int,long long int> p3= count(s);
      long long int b = p3.first;
      long long int a = p3.second;
      if(key2 >= a && n-key2-1 >= b)
      {
        long long int count1 = 0, count2 = 0;
        string s1 = p1.first;
        for(long long int j=0;j<p1.second.size();j++)
        {
          if(s1[j]=='0' && l[p1.second[j]]<l[i]) count1++;
          if(s1[j]=='1' && l[p1.second[j]]>l[i]) count2++;
        }
        d[l[i]] = count1 + count2 - min(count1,count2);
      }
      else d[l[i]] = -1;
    }
    for(long long int i=0;i<q;i++)
    {
      long long int k;
      scanf("%lld",&k);
      printf("%lld\n",d[k]);
    }
  }
  return 0;
}

/*
1
7 1
7 1 2 3 4 5 6
7

*/

/*
THE QUESTION
There are Q
 students in Chef's class. Chef's teacher has given the students a simple assignment:

Write a function that takes as arguments an array A
 containing only unique elements and a number X
 guaranteed to be present in the array and returns the (1
-based) index of the element that is equal to X
.

The teacher was expecting a linear search algorithm, but since Chef is such an amazing programmer, he decided to write the following binary search function:

integer binary_search(array a, integer n, integer x):
    integer low, high, mid
    low := 1
    high := n
    while low ≤ high:
        mid := (low + high) / 2
        if a[mid] == x:
            break
        else if a[mid] is less than x:
            low := mid+1
        else:
            high := mid-1
    return mid
All of Chef's classmates have copied his code and submitted it to the teacher.

Chef later realised that since he forgot to sort the array, the binary search algorithm may not work. Luckily, the teacher is tired today, so she asked Chef to assist her with grading the codes. Each student's code is graded by providing an array A
 and an integer X
 to it and checking if the returned index is correct. However, the teacher is lazy and provides the exact same array to all codes. The only thing that varies is the value of X
.

Chef was asked to type in the inputs. He decides that when typing in the input array for each code, he's not going to use the input array he's given, but an array created by swapping some pairs of elements of this original input array. However, he cannot change the position of the element that's equal to X
 itself, since that would be suspicious.

For each of the Q
 students, Chef would like to know the minimum number of swaps required to make the algorithm find the correct answer.

Input
The first line of the input contains a single integer T
 denoting the number of test cases. The description of T
 test cases follows.
The first line of each test case contains two space-separated integers N
 and Q
denoting the number of elements in the array and the number of students.
The second line contains N
 space-separated integers A1,A2,…,AN
.
The following Q
 lines describe queries. Each of these lines contains a single integer X
.
Output
For each query, print a single line containing one integer — the minimum required number of swaps, or −1
 if it is impossible to make the algorithm find the correct answer. (Do you really think Chef can fail?)

Constraints
1≤T≤10
1≤N,Q≤105
1≤Ai≤109
 for each valid i
1≤X≤109
all elements of A
 are pairwise distinct
for each query, X
 is present in A
sum of N
 over all test cases ≤5⋅105
sum of Q
 over all test cases ≤5⋅105

*/

/*
EDITORIAL

By looking at the constraints, I get a feeling that it should be an O(qlogn) algorithm with nlogn precomputation,
ie.O((n+q)logn)
Observation 1:
  On binary searching, we visit logn nodes. So technically for each query, we ony have to concern ourselves with these logn nodes.

Observation 2:
  In order for the bsearch, to be correct, each of these logn nodes have to 'point' to the right direction
  Eg , if I have to go to the left side, and then the right side, the node which made me look left has a value greater than X

All we need to do is check if these logn nodes are poiting in the right direction. If they aren't they need to be swapped. The answer is swapleft+ swapright - min(swapleft,swapright) = max(swapleft, swapright)

I precomputed the directions for each index 1 to n and stored it in a string, 0 for left and 1 for right. For each 0 or 1, I mantained an array of these visited nodes.
Then for ea
