#!/usr/bin/env bash
./hyperbola -50 50 1 | gnuplot -p -e "set term png;set output 'hyperbola.png';set xlabel 'x'; set ylabel 'y'; set title 'Hyperbola:  y = 1/x'; plot '-' with lines"
