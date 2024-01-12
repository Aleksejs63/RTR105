#!/usr/bin/gnuplot -persist
set title "Funkcija cos(sqrt(x))"
set xlabel "X Ass"
set ylabel "Y Ass"
set grid

set style line 2 lc rgb 'black' 

plot [30:35] [0:1] cos(sqrt(x))  w filledcurves below x1 lc rgb "gray"




set term png
set output "grafiks.png"
replot