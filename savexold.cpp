
#include "uti.h"
#include "gauss.h"

complex < double >
savexold (complex <double> x[L][M][N][N], complex <double> x_old[L][M][N][N])
{
       for (int l = 0; l < L ; l++)
	    {
      for (int m = 0; m < M ; m++)
		{
        for (int row = 0; row < N; row++)
	    {
	      for (int col = 0; col < N; col++)
		{
		  x_old[l][m][row][col] = x[l][m][row][col] ; 
		}
		
		}
		
		}
    }
}
