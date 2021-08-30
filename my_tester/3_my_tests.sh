#!/bin/bash

echo "!!bad output only"
../pipex "input1.txt" "ls" "wc -w" "";
out=$?;
sleep 0.5;
echo my output $out?
exec < input1.txt ls | wc -w > "";
echo real output $?
echo "----------------------"

echo "!!fake cmd2 + bad output test"
echo "----------------------"
echo "My program:"
../pipex "input1.txt" "cat" "fake" "";
out=$?;
sleep 0.5;
echo my output $out?
exec < input1.txt cat | fake > "";
echo real output $?

echo "!!correct test 1"
../pipex "input1.txt" "ls" "cat" "output1.txt";
out=$?;
sleep 0.5;
echo my output $out?
exec < input1.txt ls | cat > "output2.txt";
echo real output $?
cmp output1.txt output2.txt;
if [ $? -ne 0 ]; then
	echo "DIFFERENT OUTPUT";
fi
echo "----------------------"

echo "!!correct test 2"
../pipex "input1.txt" "cat" "wc -l" "output1.txt";
out=$?;
sleep 0.5;
echo my output $out?
exec < input1.txt cat | wc -l > "output2.txt";
echo real output $?
cmp output1.txt output2.txt;
if [ $? -ne 0 ]; then
	echo "DIFFERENT OUTPUT";
fi
echo "----------------------"
