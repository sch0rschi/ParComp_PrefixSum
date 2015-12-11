#include <stdio.h>

#include "matrix.h"

unsigned **sequentialSimulation(unsigned numberOfMatrices, unsigned dimensionOfMatrices, unsigned ***matrices) {

	time_t start;
	time_t end;
	time (&start);

	for(int matrix = 1; matrix < numberOfMatrices; matrix++){
		multiplyResultInA(dimensionOfMatrices, matrices[0], matrices[matrix]);
	}

	time (&end);
	printf("Sequential took: %d.\n", (end-start));

	return matrices[0];
}
