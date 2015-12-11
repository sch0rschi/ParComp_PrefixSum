#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void multiplyResultInA(unsigned dimension, unsigned** matrixA, unsigned** matrixB) {
	unsigned *actualRow = malloc( dimension * sizeof(*actualRow) );
	unsigned sum;

    /* dimension checking
    if( (sizeof(matrixA) / sizeof(int*)) != dimension ){ printf("Matrix A has unexpected many rows.\n%d %d %d\n", sizeof(matrixA), sizeof(int*), dimension); return;}
    if( (sizeof(matrixB) / sizeof(int*)) != dimension ){ printf("Matrix B has unexpected many rows.\n%d %d %d\n", sizeof(matrixB), sizeof(int*), dimension); return;}
    for(int row = 0; row < dimension; row++){
        if( (sizeof(matrixA[row]) / sizeof(int)) != dimension ){ printf("Matrix A has unexpected many columns.\n"); return;}
        if( (sizeof(matrixB[row]) / sizeof(int)) != dimension ){ printf("Matrix B has unexpected many columns.\n"); return;}
    } end of dimension checking */

    /* calculating the result */
    for(unsigned calculatingRow = 0; calculatingRow < dimension; calculatingRow++){      /* calculate row */
        memcpy(actualRow, matrixA[calculatingRow], dimension * sizeof(unsigned) );
        for(unsigned calculatingColumn = 0; calculatingColumn < dimension; calculatingColumn++){ /* calculate column in row */
            sum = 0;
            for(unsigned row = 0; row < dimension; row++){                               /* sum of row times column */
                sum += actualRow[row] * matrixB[row][calculatingColumn];
            }
            (matrixA[calculatingRow])[calculatingColumn] = sum;
            sum = 0;
        }
    } /* end of calculating the result */
}

unsigned** randomMatrix(unsigned dimension){
	srand (time(NULL));
	unsigned **matrix = malloc(dimension * sizeof(unsigned*));
	for(unsigned row = 0; row < dimension; row++){
		matrix[row] = malloc(dimension * sizeof(unsigned));
		for (unsigned column = 0; column < dimension; column++){
			matrix[row][column] = (unsigned) rand();
		}
	}
	return matrix;
}