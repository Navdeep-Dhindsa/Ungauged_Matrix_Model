
#include "uti.h"
#include "trace.h"
#include "comm.h"
#include "matfive_mult.h"
//#include "mat_mult.h"

complex < double >
energy (complex < double >x[L][M][N][N], complex < double >&E)
{
  complex < double >x_comm[L][M][M][N][N], x_comm_sq[L][M][M][N][N],
    Energy[N][N];
  E = complex < double >(0.0, 0.0);
  complex < double >y;



  comm (x, x, x_comm);
  matfive_mult (x_comm, x_comm, x_comm_sq);



  for (int row = 0; row < N; row++)
    {
      for (int col = 0; col < N; col++)
	{
	  Energy[row][col] = complex < double >(0.0, 0.0);
	  for (int l = 0; l < L; l++)
	    {
	      for (int m = 0; m < M; m++)
		{
		  for (int m2 = m + 1; m2 < M; m2++)
		    {
		      Energy[row][col] -= 1.5 * x_comm_sq[l][m][m2][row][col];
		    }
		}
	    }
	}
    }

  trace (Energy, y);
  E += (N * 0.25 * T / lambda) * y;


  return E;
}
