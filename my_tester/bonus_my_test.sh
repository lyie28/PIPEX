#!/bin/bash
echo "multi cmd 1"
../pipex_bonus "input.txt" "grep hello" "cat" "ls" "cat" "grep txt" "test1.txt";
out=$?;
sleep 0.5;
echo my output $out?
exec < input.txt grep hello | cat | ls | cat | grep txt > test2.txt;
echo real output $?
cmp test1.txt test2.txt;
if [ $? -ne 0 ]; then
	echo "DIFFERENT OUTPUT";
fi
echo "----------------------"

echo "multi cmd 2"
../pipex_bonus "input.txt" "ls" "cat" "wc -l" "wc -w" "test1.txt";
out=$?;
sleep 0.5;
echo my output $out?;
exec < input.txt ls | cat | wc -w | wc -w > test2.txt;
echo real output $?;
cmp test1.txt test2.txt;
if [ $? -ne 0 ]; then
	echo "DIFFERENT OUTPUT";
fi
echo "----------------------";
