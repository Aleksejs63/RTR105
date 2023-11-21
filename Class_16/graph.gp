#!/usr/bin/gnuplot -persist
set title "Funkcija cos(sqrt(x))"
set xlabel "X Ass"
set ylabel "Y Ass"
set grid

set xrange[0:20]
set yrange[-10:10]
plot cos(sqrt(x))

a0(x) = 1
a1(x) = -x / (1*2)
a2(x) = x**2 / (1*2*3*4)
a3(x) = -x**3 / (1*2*3*4*5*6)
s0(x) = a0(x)
s1(x) = a0(x) + a1(x)
s2(x) = a0(x) + a1(x) + a2(x)
s3(x) = a0(x) + a1(x) + a2(x) + a3(x)

replot s0(x)
replot s1(x)
replot s2(x)
replot s3(x)

set term png
set output "grafiks.png"
replot