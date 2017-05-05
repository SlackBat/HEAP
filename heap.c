#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void siftDown(int *numbers, int root, int bottom)
{
	int maxChild;
	int done = 0;

	while ((root * 2 <= bottom) && (!done)) {
		if (root * 2 == bottom)
			maxChild = root * 2;
		else if (numbers[root * 2] > numbers[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		if (numbers[root] < numbers[maxChild]) {
			int temp = numbers[root];
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
		}
		else 
			done = 1;
	}
}

void heapSort(int *numbers, int array_size) 
{
	for (int i = (array_size / 2) - 1; i >= 0; i--) {
		siftDown(numbers, i, array_size);
	}
	
	for (int i = array_size - 1; i >= 1; i--) {
		int temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		siftDown(numbers, 0, i - 1);
	}
}

int main()
{

double t;
	t = wtime();

	int const N = 50000;
	int mas[N];
	
	for(int i = 0; i < N; i++)
		mas[i] = getrand(1, 100000);
	
//	for (int i = 0; i < N; i++) {
//		printf("%d ", mas[i]);
//	}

//	printf("\n");
	heapSort(mas, N);
//	for (int i = 0; i < N; i++) {
//		printf("%d ", mas[i]);
//	}

//	printf("\n");
	t = wtime() - t;
	printf("Elapsed time: %.6f sec.\n", t); 
	return 0;
}
