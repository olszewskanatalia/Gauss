#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
	for(int k = 0; k < mat->c; k++)
	{
	
		if(sed(mat,b,k) == 0)
		{
		
			for(int w = k + 1; w < mat->r; w ++)
			{
				double wsp = mat->data[w][k] / mat->data[k][k];
				for(int j = k; j < mat->c; j ++)
					mat->data[w][j] -= mat->data[k][j] * wsp;
				b->data[w][0] -= b->data[k][0] * wsp;
			
			}
		}
		else 
		{
			return 1;
		}
	}
    	

		return 0;
}

