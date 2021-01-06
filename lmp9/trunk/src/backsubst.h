#include "backsubst.h"

int backsubst(Matrix *x, Matrix *mat, Matrix *b)
{
	if(mat->r != mat->c)
		return 2;

	int n = x->r;

	for(int row = n - 1; row >= 0; row--)
	{
		double sum = 0;
		
		for(int column = row + 1; column < n; column++)
			sum += mat->data[row][column] * x->data[column][0];
		
		if(mat->data[row][row] == 0)
			return 1;
		
		x->data[row][0] = (b->data[row][0] - sum) / mat->data[row][row]; 
	}

	return 0;
}
