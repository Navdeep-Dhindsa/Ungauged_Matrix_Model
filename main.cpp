//GWW Matrix model serial code//
#include <iostream>
#include <fstream>
using namespace std;
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "uti.h"
#include "update.h"
#include "savexold.h"
#include "action.h"
#include "herm.h"
#include "energy.h"
#include "ext_scalar.h"

int
main ()
{
  complex < double >x[L][M][N][N], x_new[L][M][N][N], x_old[L][M][N][N],
    x_sq[L][M][N][N];
  complex < double >S1, E, Ext_scalar;
  double S_old, S_new, log_rand;
  int sweeps = 1000000;		//Total sweeps
  int gap = 1000;		//Gap between measurements
  int reject = 0;
  int sim;

  //write out parameters
  cout << "Lattice size L = " << L << "\n";
  cout << "Number of scalar matrices = " << M << "\n";
  cout << "Magnitude of DT = " << DT << "\n";
  cout << "Rank of matrix = " << N << "\n";
  cout << "Lambda = " << lambda << "\n";

//Initialization//

  herm (x);

  for (int l = 0; l < L; l++)
    {
      for (int m = 0; m < M; m++)
	{
	  for (int row = 0; row < N; row++)
	    {
	      for (int col = 0; col < N; col++)
		{
		  x[l][m][row][col] = x[l][m][row][col] * 0.12;
		}
	    }

	}
    }

  ofstream f_action;
  f_action.open ("data-analysis/action.dat");	//To store action values//

  ofstream f_acc;
  f_acc.open ("data-analysis/acc.dat");	//To store acceptance values//

  ofstream f_energy;
  f_energy.open ("data-analysis/energy.dat");	//To store Energy values//

  ofstream f_extent;
  f_extent.open ("data-analysis/extent.dat");	//To store Extent values//


  for (sim = 0; sim < sweeps; sim++)
    {


      savexold (x, x_old);	//Saving x matrix in x_old

      action (x, S1);		//Computing initial action

      S_old = real (S1);

      update (x, x_new);	//Updating x's

      action (x_new, S1);	//Computing final action

      S_new = real (S1);

//Metropolis Test//
      log_rand = log ((float) rand () / (float) RAND_MAX);
      if (log_rand > (S_old - S_new))	//MC Sweep rejected
	{
	  savexold (x_old, x);	//Reassigning old values to x's as current sweep is rejected
	  reject++;
	}
      else
	{
	  savexold (x_new, x);	//Assigning new values to x's as new sweep is rejected
	}
      if (sim % gap == 0)	//Recording observables after a given gap
	{
	  complex < double >y;
	  action (x, S1);	//Computing action 
	  energy (x, E);
	  ext_scalar (x, Ext_scalar);
	  f_action << real (S1) / (N * N) << endl;	//Storing action in file
	  f_energy << real (E) / (N * N) << endl;	//Storing energy in file
	  f_extent << real (Ext_scalar) / (N * N) << endl;	//Storing extent in file
	  f_acc << (sim + 1 - reject) * 100.0 / (sim + 1) << endl; //Storing acceptance rate in file
	}
    }
  cout << "Acceptance rate " << (sweeps + 1 - reject) * 100.0 / (sweeps + 1) << endl;	//Printing acceptance
  return 0;
}
