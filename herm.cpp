
#include "uti.h"
#include "gauss.h"

complex < double >
herm (complex < double >H[L][M][N][N])
{
  for (int l = 0; l < L; l++)
    {
      for (int m = 0; m < M; m++)
	{
	  complex < double >trace = (0.0, 0.0);
	  for (int row = 0; row < N; row++)
	    {
	      for (int col = 0; col < N; col++)
		{
		  if (row == col)
		    {
		      H[l][m][row][col] =
			complex < double >(2.0 * drand48 () - 1.0, 0.0);
		      trace = trace + H[l][m][row][col];	
		    }
		  if (row > col)
		    {
		      H[l][m][row][col] =
			complex < double >(2.0 * drand48 () - 1.0,
					   2.0 * drand48 () - 1.0);
		      H[l][m][col][row] = complex < double >(real (H[l][m][row][col]), (-1.0) * imag (H[l][m][row][col]));	
		    }
		}
	    }

	  for (int row = 0; row < N; row++)
	    {
	      H[l][m][row][row] =
		complex <
		double >(real (H[l][m][row][row]) - real (trace) / N,
			 imag (H[l][m][row][row]));
	    }
	}
    }


}
