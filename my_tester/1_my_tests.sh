#! /bin/bash

echo "!!bad input"
../pipex "notreal.txt" "ls" "echo hello" "output1.txt";
echo my output $?
exec < notreal.txt ls | echo hello > output2.txt;
echo real output $?
cmp output1.txt output2.txt;
if [ $? -ne 0 ]; then
	echo "DIFFERENT OUTPUT";
fi
echo "----------------------"

echo "!!bad input + fake command 1"
../pipex "notreal.txt" "fake" "ls" "output1.txt";
echo my output $?
exec < notreal.txt fake | ls > output2.txt;
echo real output $?
cmp output1.txt output2.txt;
if [ $? -ne 0 ]; then
	echo "DIFFERENT OUTPUT";
fi
echo "----------------------"

echo "!!bad input + fake cmd1 + fake cmd2"
../pipex "notreal.txt" "fake" "fake" "out1.txt";
HELLO=$?;
sleep 0.5;
echo my output $HELLO;
< notreal.txt fake | fake > out2.txt
echo real output $?
cmp out1.txt out2.txt;
if [ $? -ne 0 ]; then
	echo "DIFFERENT OUTPUT";
fi
echo "----------------------"
