#include <stdio.h>

#include "matrix.h"

unsigned **sequentialSimulation(unsigned numberOfMatrices, unsigned dimensionOfMatrices, unsigned ***matrices) {

	for(int matrix = 1; matrix < numberOfMatrices; matrix++){
		multiplyResultInA(dimensionOfMatrices, matrices[0], matrices[matrix]);
	}

	return matrices[0];
}
