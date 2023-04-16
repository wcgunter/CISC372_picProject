
image:image.c image.h
	gcc -g image.c -o image -lm
clean:
	rm -f image output.png image_pthreads
image_pthreads: image_pthreads.c image_pthreads.h
	gcc -g image_pthreads.c -o image_pthreads -lm -lpthread -std=c99
image_omp: image_omp.c image.h
	gcc -g image_omp.c -o image_omp -lm -fopenmp