
#include "uti.h"
#include "gauss.h"
#include "herm.h"

complex < double >
update (complex < double >x[L][M][N][N], complex < double >x_new[L][M][N][N])
{
  complex < double >jump[L][M][N][N];

  for (int l = 0; l < L; l++)
    {
      for (int m = 0; m < M; m++)
	{
	  for (int row = 0; row < N; row++)
	    {
	      for (int col = 0; col < N; col++)
		{
		  x_new[l][m][row][col] = x[l][m][row][col];	//
		}
	    }
	}
    }
  for (int j = 0; j < trajec; j++)
    {
      herm (jump);
      for (int l = 0; l < L; l++)
	{
	  for (int m = 0; m < M; m++)
	    {
	      for (int row = 0; row < N; row++)
		{
		  for (int col = 0; col < N; col++)
		    {
		      x_new[l][m][row][col] = x_new[l][m][row][col] + DT * jump[l][m][row][col];	//
		    }
		}
	    }
	}
    }
}
