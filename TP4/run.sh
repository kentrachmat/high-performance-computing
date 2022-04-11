#!/bin/bash
#

if [ $# -eq 0 ] ; then 
echo "Usage : $0 a.out "; 
exit 1
fi

EXEC=$1
OUTPUT_FILE="data_${EXEC}.txt"

echo "#N	GFLOP/S " > $OUTPUT_FILE

for ((N=64; N <= 2048 ; N = N +128)); do
    echo -n "For N=$N ... " 
    PERF=$( ./$EXEC $N | grep performance | awk '{ print $(NF-1)}')
    echo "$N	$PERF" >> $OUTPUT_FILE
    echo " done!"  
done 


