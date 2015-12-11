#include <stdio.h>
#include "matrix.h"
#include <omp.h>

unsigned **openMPSimulation(unsigned numberOfMatrices, unsigned dimensionOfMatrices, unsigned ***matrices) {

    omp_set_num_threads(8);

	for(int step = 1; step < numberOfMatrices; step *= 2 ){
		#pragma omp parallel for
		for(int matrix = 0; matrix < (numberOfMatrices - step); matrix += (2*step)){
			multiplyResultInA(dimensionOfMatrices, matrices[matrix], matrices[matrix+step]);
		}
	}

	return matrices[0];
}
