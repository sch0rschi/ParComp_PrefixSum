#include <unistd.h>
#include <string.h>
#include "sequential.c"
#include "openMP.c"

void usage();

int main(int argc, const char **argv) {

	int option = -1;
	int numberOfMatrices = 2;
	int dimensionOfMatrices = 2;
	char method[1];

	if(argc != 4){
		printf("%d\n", argc);
		usage();
		return 0;
	}

	numberOfMatrices = atoi(argv[1]);
	dimensionOfMatrices = atoi(argv[2]);
	strncpy(method, argv[3], 1);

	unsigned ***matrices = malloc(numberOfMatrices * sizeof(**matrices));
	for(int matrix = 0; matrix < numberOfMatrices; matrix++){
		matrices[matrix] = randomMatrix(dimensionOfMatrices);
	}

	unsigned*** matricesCopy1 = copyMatrices(numberOfMatrices, dimensionOfMatrices, matrices);
	unsigned*** matricesCopy2 = copyMatrices(numberOfMatrices, dimensionOfMatrices, matrices);

	printf("Starting simulation.\n");

	unsigned **resultMatrixSequential = sequentialSimulation(numberOfMatrices, dimensionOfMatrices, matricesCopy1);
	printMatrix(dimensionOfMatrices, resultMatrixSequential);
	unsigned **resultMatrixOpenMP = openMPSimulation(numberOfMatrices, dimensionOfMatrices, matricesCopy2);
	printMatrix(dimensionOfMatrices, resultMatrixOpenMP);
	printf("equals: %d\n", equals(dimensionOfMatrices, resultMatrixSequential, resultMatrixOpenMP));

	return 0;
}

void usage(){
	printf("simulation numberOfMatrices dimensionofMatrices method\n");
}
