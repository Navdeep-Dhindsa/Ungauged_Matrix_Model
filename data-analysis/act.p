set terminal postscript eps enhanced color dashed lw 1 "Helvetica" 16
set output "act.eps"
plot "action.dat" using 0:1 title ""
