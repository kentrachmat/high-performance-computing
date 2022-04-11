set title "Analyse du temps de calcul de l'ensemble de Mandelbrot en fonction du nombre de threads"

set key spacing 15

set xlabel "Nombre de thread(s)"

set ylabel "Durée du calcul"

set logscale y

set term png size 800,600
set output "img/res_q2_exec.png"

plot "res_q2.dat" using 1:2 with lines

set title "Accélération du calcul de l'ensemble de Mandelbrot en fonction du nombre de threads"

set key spacing 15

set xlabel "Nombre de thread(s)"

set ylabel "Accélération"

set logscale y

set term png size 800,600
set output "img/res_q2_acc.png"

plot "res_q2.dat" using 1:3 with lines


set title "Efficacité du calcul de l'ensemble de Mandelbrot en fonction du nombre de threads"

set key spacing 15

set xlabel "Nombre de thread(s)"

set ylabel "Efficacité"

#set logscale y#

set term png size 800,600
set output "img/res_q2_eff.png"

plot "res_q2.dat" using 1:4 with lines


