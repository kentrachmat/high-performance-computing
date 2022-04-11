MATUL=./matul
RES=res.dat

make

echo -n "" > $RES

for ((i = 1; i <= 100;i += 1));do
  export OMP_NUM_THREADS=1
  echo `$MATUL $i $OMP_NUM_THREADS` >> $RES
  export OMP_NUM_THREADS=2
  echo `$MATUL $i $OMP_NUM_THREADS` >> $RES
  export OMP_NUM_THREADS=4
  echo `$MATUL $i $OMP_NUM_THREADS` >> $RES
  export OMP_NUM_THREADS=6
  echo `$MATUL $i $OMP_NUM_THREADS` >> $RES
done
  


