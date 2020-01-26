We are using a script which generates testcases randomly. We write 2 programmes, one our brute force, which we assume to be correct,
and our actual code which we need to test against. We generate these testcases and run them against both the programmes and compare
their outputs. If they're same, we will generate a new case. Else, we will stop and print the wrong 
testcase in the file 'testcase.in', the correct output in 'AC.out' and what the testing code tests in 'WA.out'

We have written two major programmes. We have implemented the BFPRT Algorithm (Median finding algorithm which runsin O(n)).

Our code 'gen.py' generates the tests randomly. For convenience the tests for the median and the chords code are generated using the
same script. In 'gen.py' the variable 'n' is the length of the array, and 'upperbound' is the bound on the weights in the input. One
can change that if necessary.

In order to see our code doesn't take that much time at all, we've commented out the lines which calculate the time taken.
For our large testcases (n is approx 1e5), the code doesn't take more than 200ms.

TESTING

The brute force code is 'brute_median.cpp'. It sorts the array and returns the middle element -> O(nlogn)
Our actual code which has been used in the final programme is 'median.cpp'.

To test it do the following
1. g++ -std=c++14 brute_median.cpp
2. mv a.out Brute
3. g++ -std=c++14 median.cpp
4. mv a.out A
5. bash test.sh

The code will keep generating cases until there's a mismatch, or it generates 100 correct testcases.

Now that our median algorithm is correct (We tested it with more than 3000 testcases), we can use it in our chords code

For the chords code, we've proved that the answer will always be the sum of the largest n elements - the sum of the smallest n elements
So, our brute force code does exactly that.
The question however demands we not only get the max cost, but also the chords themselves.
So, in our chords code, we are printing the chords (That's in the code which is outside this folder), but here we aren't
Here, we're taking those chords, and getting the cost of those chords and adding them up. We're printing that cost.
This max cost is what is being compared in both the programmes.

The brute force code is 'brute_chords.cpp'. It takes O(nlogn)
The actual code to be tested is 'chords.cpp'. This takes O(n)

To test it do the following
1. g++ -std=c++14 brute_chords.cpp
2. mv a.out Brute
3. g++ -std=c++14 chords.cpp
4. mv a.out A
5. bash test.sh

Again, while we are only generating 100 testcases here, we've tested it more than 2000 testcases.
