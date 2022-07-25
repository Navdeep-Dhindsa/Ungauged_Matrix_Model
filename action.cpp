
#include "uti.h"
#include "trace.h"
#include "comm.h"
#include "matfive_mult.h"
#include "matrix_mult.h"

complex < double >
action (complex < double >x[L][M][N][N], complex < double >&S1)
{
  complex < double >x_kin[L][M][N][N], x_kin_sq[L][M][N][N],
    x_comm[L][M][M][N][N], x_comm_sq[L][M][M][N][N], act[N][N];
  S1 = complex < double >(0.0, 0.0);
  complex < double >y;

  for (int l = 0; l < L; l++)
    {
      for (int m = 0; m < M; m++)
	{
	  for (int row = 0; row < N; row++)
	    {
	      for (int col = 0; col < N; col++)
		{
		  x_kin[l][m][row][col] = x[l][m][row][col] - x[(l - 1 + L) % L][m][row][col];	//
		}
	    }
	}
    }

  matrix_mult (x_kin, x_kin, x_kin_sq);

  comm (x, x, x_comm);
  matfive_mult (x_comm, x_comm, x_comm_sq);



  for (int row = 0; row < N; row++)
    {
      for (int col = 0; col < N; col++)
	{
	  act[row][col] = complex < double >(0.0, 0.0);
	  for (int l = 0; l < L; l++)
	    {
	      for (int m = 0; m < M; m++)
		{
		  act[row][col] += x_kin_sq[l][m][row][col];
		  for (int m2 = m + 1; m2 < M; m2++)
		    {
		      act[row][col] -= 0.5 * x_comm_sq[l][m][m2][row][col];
		    }
		}
	    }
	}
    }

  trace (act, y);
  S1 += (N * 0.25 / lambda) * y;

  return S1;
}
