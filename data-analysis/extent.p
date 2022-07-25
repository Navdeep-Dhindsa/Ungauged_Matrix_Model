set terminal postscript eps enhanced color dashed lw 1 "Helvetica" 16
set output "extent.eps"
plot "extent.dat" using 0:1 title ""
