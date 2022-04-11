set title "Analyse du temps de calcul de l'ensemble de Mandelbrot en fonction du nombre de threads"

set key spacing 15

set xlabel "Nombre de thread(s)"

set ylabel "Durée du calcul (sec)"

set logscale y

set term png size 800,600
set output "img/res_q1_exec.png"

plot "res.dat" using 1:2 with lines

set title "Accélération du calcul de l'ensemble de Mandelbrot en fonction du nombre de threads"

set key spacing 15

set xlabel "Nombre de thread(s)"

set ylabel "Accélération"

set logscale y

set term png size 800,600
set output "img/res_q1_acc.png"

plot "res.dat" using 1:3 with lines


set title "Efficacité du calcul de l'ensemble de Mandelbrot en fonction du nombre de threads"

set key spacing 15

set xlabel "Nombre de thread(s)"

set ylabel "Efficacité"

#set logscale y

set term png size 800,600
set output "img/res_q1_eff.png"

plot "res.dat" using 1:4 with lines


