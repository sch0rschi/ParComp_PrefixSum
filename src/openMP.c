#include <stdio.h>

#include "matrix.h"

unsigned **openMPSimulation(unsigned numberOfMatrices, unsigned dimensionOfMatrices, unsigned ***matrices) {

	time_t start;
	time_t end;
	time (&start);

	for(int step = 1; step < numberOfMatrices-1; step *= 2 ){
		#pragma omp parallel for
		for(int matrix = 0; matrix < (numberOfMatrices - step); matrix += (2*step)){
			multiplyResultInA(dimensionOfMatrices, matrices[matrix], matrices[matrix+step]);
		}
	}

	time (&end);
	printf("OpenMP took: %d.\n", (end-start));

	return matrices[0];
}
