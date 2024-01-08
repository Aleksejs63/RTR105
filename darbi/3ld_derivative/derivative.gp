#!/usr/bin/gnuplot --persist

set terminal pngcairo enhanced font "arial,10" fontscale 1.0 size 600, 400 
set output 'derivative.png'

set grid


plot [0.1:30]  "derivative.dat" every ::1 using 1:2 with lines title "cos(sqrt(x)) (from file)", \
                "derivative.dat" every ::1 using 1:3 with lines title "cos'(sqrt(x)) (analytical)", \
                "derivative.dat" every ::1 using 1:4 with lines title "cos'(sqrt(x)) (forward difference)", \
                "derivative.dat" every ::1 using 1:5 with lines title "cos''(sqrt(x)) (forward difference)", \
                "derivative.dat" every ::1 using 1:6 with lines title "cos''(sqrt(x)) (analytical)"
                
                
