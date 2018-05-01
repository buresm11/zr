#!/bin/sh

TEST_COUNT=6
BIN="../build/zr"

I=1

while [  $I -le $TEST_COUNT ]; do
    ./$BIN -o -s "in$I" > "o$I"
    ./$BIN -n -s "in$I" > "n$I" 

	if diff "n$I" "out$I" >/dev/null ; then
	  echo -n "Good $I  "
	else
	  echo -n "Non optimalized is diff $I  "
	fi

	if diff "o$I" "out$I" >/dev/null ; then
	  echo "Good $I"
	else
	  echo "Optimalized is diff $I"
	fi

    I=$((I+1)) 
done