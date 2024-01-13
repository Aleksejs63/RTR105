#!/usr/bin/gnuplot -persist
set title "Burtu frekvence teksta rindaa"
set xlabel "Burts"
set ylabel "Frekvence"
set grid
set boxwidth 0.9 relative
set style fill solid 1.0
set yrange [0:]



plot "sort.dat" every ::1 using 2:xtic(1) with boxes linestyle 1 notitle




set term png
set output "grafiks.png"
replot