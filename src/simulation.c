#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include "sequential.c"
#include "openMP.c"
#include <omp.h>

void usage();

int main(int argc, const char **argv) {

	int numberOfMatrices = 2;
	int dimensionOfMatrices = 2;
	//char method[1];

	if(argc != 3){
		printf("%d\n", argc);
		usage();
		return 0;
	}

	numberOfMatrices = atoi(argv[1]);
	dimensionOfMatrices = atoi(argv[2]);
	omp_set_num_threads(8);
	//strncpy(method, argv[3], 1);

	// a quick hack
	typedef unsigned long long usecs;
	usecs mytime()
	{
	  struct timeval now;
	  gettimeofday(&now,NULL);
	  return (usecs)now.tv_usec+(usecs)now.tv_sec*1000000L;
	}
	usecs start, stop;
	double sequentialTime, openMPTime;

	unsigned ***matrices = malloc(numberOfMatrices * sizeof(**matrices));
	#pragma omp parallel for
	for(int matrix = 0; matrix < numberOfMatrices; matrix++){
		matrices[matrix] = randomMatrix(dimensionOfMatrices);
	}

	unsigned*** matricesCopy1 = copyMatrices(numberOfMatrices, dimensionOfMatrices, matrices);
	unsigned*** matricesCopy2 = copyMatrices(numberOfMatrices, dimensionOfMatrices, matrices);

	printf("Starting simulation.\n");

	start = mytime();
	unsigned **resultMatrixSequential = sequentialSimulation(numberOfMatrices, dimensionOfMatrices, matricesCopy1);
	stop = mytime();
	sequentialTime = ((double)(stop-start))/(double)1000000;
	printf("Sequential time %fs\n",sequentialTime);

	start = mytime();
	unsigned **resultMatrixOpenMP = openMPSimulation(numberOfMatrices, dimensionOfMatrices, matricesCopy2);
	stop = mytime();
	openMPTime = ((double)(stop-start))/(double)1000000;
	printf("OpenMP time %fs\n",openMPTime);

	printf("OpenMP: equals: %d; speedup: %f\n", equals(dimensionOfMatrices, resultMatrixSequential, resultMatrixOpenMP), sequentialTime/openMPTime);

	return 0;
}

void usage(){
	printf("simulation numberOfMatrices dimensionofMatrices method\n");
}
