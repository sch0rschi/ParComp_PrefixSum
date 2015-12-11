#include <stdio.h>

#include "matrix.c"

int main(int argc, const char* argv[]) {
	unsigned **matrixA = randomMatrix(2);
    unsigned **matrixB = randomMatrix(2);

    multiplyResultInA( 2, matrixA, matrixB );

    printf("%u\t%u\n%u\t%u\n", matrixA[0][0], matrixA[0][1], matrixA[1][0], matrixA[1][1]);
    return 0;
}
