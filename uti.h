#ifndef UTI_H
#define UTI_H

#include <iostream>
#include <fstream>
using namespace std;
#include <math.h>
#include <stdlib.h>
#include <complex>
#include <string.h>

const int L = 12;/*Number of lattice sites | Fix this to 1 in zero dimensional model*/
const int M = 9; /*Number of Scalars | Vary it in between 2 and 10 depending upon how many scalars you have in picture i.e. value of 'd' in various actions*/
const double DT = 0.00022;/*Shifting parameter | Tune this to control acceptance */
const int N =	6;/*Rank of Matrices */
const double T = 0.5;/*Temp*/
const double lambda = 1.0/(L*L*L*T*T*T) ; //
const int trajec = 15;

#endif
