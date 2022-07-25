
#include "uti.h"
complex < double >
trace (complex < double >act[N][N], complex < double >&y)
{
  y = complex < double >(0.0, 0.0);
  for (int row = 0; row < N; row++)
    {
      y += act[row][row];

    }

  return y;

}
