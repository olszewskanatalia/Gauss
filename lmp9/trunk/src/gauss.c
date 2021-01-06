#include "gauss.h"

int sed(Matrix *mat, Matrix *b, int kol)
{
	int max = mat->data[kol][kol];
	int wiersz = kol;
	int i = kol + 1;
	int k = 0;

	for(; i < mat -> r; i ++)  // wyszukuje najwiekszej wartosci pod diagonala
	{
		if(max < mat->data[i][kol] && mat->data[i][kol] != 0)
		{
			max = mat->data[i][kol];
			wiersz = i;
		}
	}

	if(wiersz != kol)   // zamienia wiersze miejscami
	{
		for(;k < mat->c; k++)	// dla macierzy
		{
			double tmp = mat->data[wiersz][k];
			mat->data[wiersz][k] = mat->data[kol][k];
			mat->data[kol][k] = tmp;
		}
		// dla prawej strony

		double tnp = b->data[wiersz][0];
		b->data[wiersz][0] = b->data[kol][0];
		b->data[kol][0] = tnp;



	}

	if(mat->data[kol][kol] == 0 ) return 1; // wartosc na diagonali wciaz jest zerem;

	return 0;
}

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

