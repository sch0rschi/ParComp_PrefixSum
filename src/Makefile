CC=gcc

simulation.o: simulation.c sequential.c openMP.c cilk.c matrix.h
	gcc -O3 -Wall -fopenmp -fcilkplus -o simulation.o simulation.c

sequential.o: sequential.c matrix.h
	gcc -O3 -Wall -o sequential.o sequential.c

openMP.o: openMP.c matrix.h
	gcc -O3 -Wall -fopenmp -o openMP.o openMP.c

cilk.o: cilk.c matrix.h
	gcc -O3 -Wall -fcilkplus -fopenmp -o cilk.o cilk.c