#include <stdio.h>

#include "matrix.c"

void sequentialSimulation(unsigned numberOfMatrices, unsigned dimensionOfMatrices) {
	unsigned ***matrices = malloc(numberOfMatrices * sizeof(**matrices));
	for(int matrix = 0; matrix < numberOfMatrices; matrix++){
		matrices[matrix] = randomMatrix(dimensionOfMatrices);
	}
	for(int matrix = 1; matrix < numberOfMatrices; matrix++){
		multiplyResultInA(dimensionOfMatrices, matrices[0], matrices[matrix]);
	}
	printMatrix(dimensionOfMatrices, matrices[0]);
}
