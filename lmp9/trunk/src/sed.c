// program sed

#include "mat_io.h"

int sed(Matrix *mat, Matrix *b, int col)
{
	int r_num = mat->r;
	int c_num = mat->c;
	int max = mat->data[col][col]; // ustawiamy max na kolumne i wiersz o tych samych numerach w macierzy mat
	int row;
	int i = col + 1;
	int k = 0;
	double tmp, temp;

	for(; i < r_num; i++) //najwieksza wartosc pod diagonala
	{
		if(max < mat->data[i][col] && mat->data[i][col] != 0)
		{
			max = mat->data[i][col]; // zmieniamy max 
			row = i; // ustawiamy numer wiersza inny niz kolumny
		
			for(; k < c_num; k++) //zamiana miejscami w macierzy mat
			{
				tmp = mat->data[row][k];
				mat->data[row][k] = mat->data[col][k];
				mat->data[col][k] = tmp;
			}
			
			//zamiana miejscami w macierzy b
			temp = b->data[row][0];
			b->data[row][0] = b->data[col][0];
			b->data[col][0] = temp;
		
		}
		else row = col;
	}

	if(max == 0 ) 
		return 1; 

	return 0;
}
