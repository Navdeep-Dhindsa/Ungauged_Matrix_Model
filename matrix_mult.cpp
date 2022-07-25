
#include "uti.h"

complex < double >
matrix_mult (complex < double >x1[L][M][N][N],
	     complex < double >x2[L][M][N][N],
	     complex < double >x_sq[L][M][N][N])
{

  for (int l = 0; l < L; l++)
    {
      for (int m = 0; m < M; m++)
	{
	  for (int row = 0; row < N; row++)
	    {
	      for (int col = 0; col < N; col++)
		{
		  x_sq[l][m][row][col] = complex < double >(0, 0);
		  for (int k = 0; k < N; k++)
		    {
		      x_sq[l][m][row][col] +=
			x1[l][m][row][k] * x2[l][m][k][col];
		    }


		}
	    }

	}

    }
}
