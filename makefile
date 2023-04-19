
image:image.c image.h
	gcc -g image.c -o image -lm -lpthread -std=c99
image_omp: image_omp.c image.h
	gcc -g image_omp.c -o image_omp -lm -fopenmp
clean:
	rm -f image image_omp output.png
