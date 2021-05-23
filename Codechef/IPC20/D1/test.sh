testcase=0
fail="False"

while [ $testcase -lt 10000 ]
do
	python gen.py > testcase.in
	./A < testcase.in > WA.out

	testcase=`expr $testcase + 1`
	echo $testcase
done
