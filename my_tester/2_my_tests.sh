#!/bin/bash

echo "!!fake cmd1 test"
../pipex "input1.txt" "fake" "echo hello" "output1.txt";
out=$?;
sleep 0.5;
echo my output $out?
exec < input1.txt fake | echo hello > output2.txt;
echo real output $?
cmp output1.txt output2.txt;
if [ $? -ne 0 ]; then
	echo "DIFFERENT OUTPUT";
	echo "my file";
	cat output1.txt;
	echo "real file";
	cat output2.txt;
fi
echo "----------------------"

echo "!!fake command 1 + 2 test"
../pipex "input1.txt" "fake" "fake" "output1.txt";
out=$?;
sleep 0.5;
echo my output $out?
exec < input1.txt fake | fake > output2.txt;
echo real output $?
cmp output1.txt output2.txt;
if [ $? -ne 0 ]; then
	echo "DIFFERENT OUTPUT";
fi
echo "----------------------"

echo "!!fake cmd1 + bad output test"
../pipex "input1.txt" "fake" "cat" "";
out=$?;
sleep 0.5;
echo my output $out?
exec < input1.txt fake | cat > "";
echo real output $?
echo "----------------------"

echo "!!fake cmd 1 + 2 + bad output file test"
../pipex "input1.txt" "fake" "fake" "";
out=$?;
sleep 0.5;
echo my output $out?
exec < input1.txt fake | fake > "";
echo real output $?
echo "----------------------"

echo "!!fake command 2 test"
../pipex "input1.txt" "ls" "fake" "output1.txt";
out=$?;
sleep 0.5;
echo my output $out?
exec < input1.txt ls | fake > output2.txt;
echo real output $?
cmp output1.txt output2.txt;
if [ $? -ne 0 ]; then
	echo "DIFFERENT OUTPUT";
fi
echo "----------------------"
