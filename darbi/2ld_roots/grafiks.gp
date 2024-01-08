#!/usr/bin/gnuplot -persist
set title "Funkcija cos(sqrt(x))"
set xlabel "X Ass"
set ylabel "Y Ass"
set grid

set xrange[2:3]
set yrange[-0.1:0.1]
set style line 2 lc rgb 'black' 

plot cos(sqrt(x)), \
"roots.dat" every ::1 using 1:2 with points title "Sakne"



set term png
set output "grafiks.png"
replot