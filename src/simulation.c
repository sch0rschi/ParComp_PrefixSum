#include <unistd.h>
#include "sequential.c"

int main(int argc, const char* argv[]) {

	int option = -1;
	int numberOfMatrices = 2;
	int dimensionOfMatrices = 2;
	char method = 's';

	/*while ((option = getopt (argc, argv, "n:d:m:")) != -1){
		switch (option){
			case 'n':
			numberOfMatrices = (unsigned)atoi(optarg);
			break;
			case 'd':
			dimensionOfMatrices = (unsigned)atoi(optarg);
			break;
			case 'm':
			method = strdup(optarg);
			break;
			default:
			usage();
			return 0;
			break;
		}
	}*/

	sequentialSimulation(20, 20);

	return 0;
}

void usage(){
	printf("Options: n for number of Matrices, d for dimension of Matrices, m for method.");
}
