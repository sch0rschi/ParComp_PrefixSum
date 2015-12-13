#include <stdio.h>
#include "matrix.h"
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>

unsigned **cilkSimulation(unsigned numberOfMatrices, unsigned dimensionOfMatrices, unsigned ***matrices) {

	for(int step = 1; step < numberOfMatrices; step *= 2 ){

		for(int matrix = 0; matrix < (numberOfMatrices - step); matrix += (2*step)){
			cilk_spawn multiplyResultInA(dimensionOfMatrices, matrices[matrix], matrices[matrix+step]);
		}
		cilk_sync;
	}

	return matrices[0];
}
