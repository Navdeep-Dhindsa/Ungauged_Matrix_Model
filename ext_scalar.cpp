
#include "uti.h"
#include "trace.h"
#include "matrix_mult.h"

complex < double >
ext_scalar (complex < double >x[L][M][N][N], complex < double >&Ext_scalar)
{
  complex < double >x_sq[L][M][N][N], Ext_s[N][N];
  Ext_scalar = complex < double >(0.0, 0.0);
  complex < double >y;

  matrix_mult (x, x, x_sq);

  for (int row = 0; row < N; row++)
    {
      for (int col = 0; col < N; col++)
	{
	  Ext_s[row][col] = complex < double >(0.0, 0.0);
	  for (int l = 0; l < L; l++)
	    {
	      for (int m = 0; m < M; m++)
		{
		  Ext_s[row][col] += 1.0 * x_sq[l][m][row][col];

		}
	    }
	}
    }

  trace (Ext_s, y);
  Ext_scalar += (N * 0.5 / (lambda * T * L * L)) * y;


  return Ext_scalar;
}
