#ifndef MATRIX_H
#define MATRIX_H

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
	time_t t;
	/* Intializes random number generator */
	srand((unsigned) time(&t));
	unsigned **matrix = malloc(dimension * sizeof(unsigned*));
	for(unsigned row = 0; row < dimension; row++){
		matrix[row] = malloc(dimension * sizeof(unsigned));
		for (unsigned column = 0; column < dimension; column++){
			matrix[row][column] = (unsigned) rand();
		}
	}
	return matrix;
}

void printMatrix(unsigned dimension, unsigned** matrix){
	for(int row = 0; row < dimension; row++){
		for(int column = 0; column < dimension; column++){
			printf("%u\t", matrix[row][column]);
		}
		printf("\n");
	}
}

int equals(unsigned dimension, unsigned** matrixA, unsigned** matrixB){
	for(int row = 0; row < dimension; row++){
		for(int column = 0; column < dimension; column++){
			if(matrixA[row][column] != matrixB[row][column]){
				return 0;
			}
		}
	}
	return 1;
}

unsigned **copyMatrix(unsigned dimension, unsigned **matrix){
	unsigned **newMatrix = malloc(dimension * sizeof(unsigned*));
	for(int row = 0; row < dimension; row++){
		newMatrix[row] = malloc(dimension * sizeof(unsigned));
		for(int column = 0; column < dimension; column++){
			newMatrix[row][column] = matrix[row][column];
		}
	}
	return newMatrix;
}

unsigned ***copyMatrices(unsigned numberOfMatrices, unsigned dimension, unsigned ***matrices){
	unsigned ***newMatrices = malloc(numberOfMatrices * sizeof(**newMatrices));
	for(int matrix = 0; matrix < numberOfMatrices; matrix++){
		newMatrices[matrix] = copyMatrix(dimension, matrices[matrix]);
	}
	return newMatrices;
}
#endif
