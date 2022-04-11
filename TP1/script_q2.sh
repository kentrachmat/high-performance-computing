MANDEL=./mandel
RES=res_q2.dat

gcc -fopenmp lib/mandel.c -o mandel -lm

#echo -n "" > $RES

#export OMP_NUM_THREADS=1
#echo `$MANDEL` >> $RES

export OMP_NUM_THREADS=2
echo `$MANDEL` >> $RES

export OMP_NUM_THREADS=4
echo `$MANDEL` >> $RES

export OMP_NUM_THREADS=6
echo `$MANDEL` >> $RES


