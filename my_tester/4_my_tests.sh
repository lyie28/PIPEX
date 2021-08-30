#!/bin/bash
echo "bad input + fake cmd1 + bad output test"
../pipex "notreal.txt" "fake" "cat" "";
out=$?;
sleep 0.5;
echo my output $out?
exec < notreal.txt fake | cat > "";
echo real output $?
cmp output1.txt output2.txt;
if [ $? -ne 0 ]; then
	echo "DIFFERENT OUTPUT";
fi
echo "----------------------"

echo "!!bad input + fake cmd 1 + 2 + bad output file test"
../pipex "notreal.txt" "fake" "fake" "";
out=$?;
sleep 0.5;
echo my output $out?
exec < notreal.txt fake | fake > "";
echo real output $?
echo "----------------------"

echo "!!bad everything"
../pipex "notreal.txt" "fake" "fake" "";
out=$?;
sleep 0.5;
echo my output $out?
exec < notreal.txt fake | fake > "";
echo real output $?
echo "----------------------"
