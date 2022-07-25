
#include "uti.h"

complex < double >
matfive_mult (complex < double >x1[L][M][M][N][N],
	      complex < double >x2[L][M][M][N][N],
	      complex < double >x_sq[L][M][M][N][N])
{

  for (int l = 0; l < L; l++)
    {
      for (int m = 0; m < M; m++)
	{
	  for (int m2 = m + 1; m2 < M; m2++)
	    {
	      for (int row = 0; row < N; row++)
		{
		  for (int col = 0; col < N; col++)
		    {
		      x_sq[l][m][m2][row][col] = complex < double >(0, 0);
		      for (int k = 0; k < N; k++)
			{
			  x_sq[l][m][m2][row][col] +=
			    x1[l][m][m2][row][k] * x2[l][m][m2][k][col];
			}

		    }
		}
	    }

	}

    }
}
