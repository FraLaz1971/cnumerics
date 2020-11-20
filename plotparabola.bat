#!/usr/bin/env bash
.\parabola -50 50 1 | gnuplot -p -e "set term png;set output 'parabola.png';set xlabel 'x'; set ylabel 'y'; set title 'Parabola:  x = x^2'; plot '-' with lines"
