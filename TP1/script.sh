MANDEL=./mandel_q1
RES=res.dat

gcc -fopenmp lib/mandel_q1.c -o mandel_q1 -lm

#echo -n "" > $RES

#export OMP_NUM_THREADS=1
#echo `$MANDEL` >> $RES

export OMP_NUM_THREADS=2
echo `$MANDEL` >> $RES

export OMP_NUM_THREADS=4
echo `$MANDEL` >> $RES

export OMP_NUM_THREADS=6
echo `$MANDEL` >> $RES
