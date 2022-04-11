set title "Analyse du temps de calcul du produit matriciel en fonction\nde l'ordre des matrices et du nombre de threads utilisés"

set logscale x

set key spacing 15

set xlabel "Ordre matriciel" offset -11
set ylabel "Nombre de thread(s)" offset 6
set zlabel "Durée du calcul (sec)" offset -2 rotate by 90

set dgrid3d 30,30
set pm3d

set term png size 800,600
set output "img/res_xlog_exec.png"

splot "res.dat" using 1:2:3 with lines

set logscale y
set logscale x

set output "img/res_xylog_exec.png"

splot "res.dat" using 1:2:3 with lines
